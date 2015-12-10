#include<iom128v.h>
#include "temp.h"
#include "main.h"
#include "eeprom.h"
#include "lcd.h"
#include "max6675.h"
void PID_realize(uint temp_n);
void set_start_real(uint t);
 //执行温度控制数据更新操作，读取温度更新输出参数.会对温度数据故障更新
void tempcontrol(void){
   uint i,j;
      temp_l=0x00;
      temp_h=0x12;
   for(i=0;i<4;i++){
         //readTemp(i);//读取温度，一次验证有效性
	 if(temp_l&0x04){//当前故障，下面就不用再运行啦
		     temps[i].flag=2;
	 }else{
	      //temps[i].actualtemp=0x55<<2;
		  temps[i].actualtemp=(temp_h&0x3F)<<4|(temp_l&0xF0)>>4;
         if(temps[i].flag==1)//运行中的
	      {   
		      for(j=0;j<9;j++){
			    //readTemp(i);//读取温度，需要读取10次左右
			    temps[i].actualtemp+=(temp_h&0x3F)<<4|(temp_l&0xF0)>>4;
			  }
			    temps[i].actualtemp/=9;
		        if(temps[i].status[0]%2==0){//恒温阶段，使用pid算法
				   //PID_realize(i);//启用pid算法
                }else if(temps[i].settemp-temps[i].actualtemp<10){
		         //升温或阶段，如果温度接近某个温度则开始使用PID算法。这个值要重新考虑
				   //PID_realize(i);//启用pid算法
		         }else {//升温使用其他算法
		        
		         }
	      }else if(temps[i].flag==5){//和1相同，
	             temps[i].flag=1;
	      }else if(temps[i].flag==2){//故障的,设置标志位位未初始化，但是状态和温度数据可能存在、所以可以直接恢复
		       temps[i].flag=0;
	      }
	  }
   }
}

//开机初始化空间。全部置0,不初始化数据，等用户或EEPROM数据回填
void tempdata_init(void){
 uint i,j;
 for(i=0;i<4;i++){
    temps[i].flag=0;
	for(j=0;j<132;j++){
	 temps[i].temp_data[j]=0;
	}
	temps[i].status[0]=0;
	temps[i].status[1]=0;
	temps[i].status[2]=0;
	temps[i].status[3]=0;
	temps[i].settemp=0;
	temps[i].actualtemp=0;
	temps[i].err=0;
	 temps[i].err_last=0;
	 temps[i].err_next=0;
	 temps[i].Kp=0.0;
	 temps[i].Ki=0.0;
	 temps[i].Kd=0.0;
	 temps[i].incrementtemp=25.0;
 } 
}
void data_recover(void){
 uint i,j;
 uint dataC;
 for(i=0;i<4;i++){
   dataC=EEPROM_read(i+1,0);//读取标记位
   if(dataC==1){
      temps[i].flag=EEPROM_read(i+1,133);
	  for(j=0;j<132;j++){
	    temps[i].temp_data[j]=EEPROM_read(i+1,j+1);
	   }
	}
 } 
}

//设置指定的数据,保存相关标志位
void set_temp_data(uint t,uint* dataCach){
    uint j;
	temps[t].flag=6;
	EEPROM_write(t+1,0,0x01);
	EEPROM_write(t+1,133,6);
    for(j=0;j<132;j++){
	   temps[t].temp_data[j]=*(dataCach+j);
	 //  EEPROM_write(t+1,j+1,temps[t].temp_data[j]);
	}
}

//重置指定的数据,保存相关标志位
void reset_temp_data(uint t){
    uint j;
	temps[t].flag=0;
	EEPROM_write(t+1,0,0x00);
	EEPROM_write(t+1,133,0x00);
    for(j=0;j<132;j++){
	   temps[t].temp_data[j]=0;
	 //  EEPROM_write(t+1,j+1,0);
	}
}
//温度全部开始工作。状态为停止和刚重置数据的可以开始
void set_all_start(void){
    uint j;
	
    for(j=0;j<4;j++){
	   if(temps[j].flag==3 || temps[j].flag==6){
	     temps[j].flag=5;
		// EEPROM_write(j+1,133,5);
	   }
	}
}
//温度全部暂停.要运行的才会暂停
void set_all_stop(void){
    uint j;
	
    for(j=0;j<4;j++){
	  if(temps[j].flag==1 || temps[j].flag==5){
	     temps[j].flag=3;
		//  EEPROM_write(j+1,133,3);
	   }
	}
}
//指定温度开始,预备
void set_start(uint t){
 if(temps[t].flag==3 || temps[t].flag==6){
	     temps[t].flag=5;
		///  EEPROM_write(t+1,133,5);
	}
}

//指定温度暂停
void set_stop(uint t){
 if(temps[t].flag==1 || temps[t].flag==5){
	     temps[t].flag=3;
		// EEPROM_write(t+1,133,3);
	   }
}
/***********************************************************************
* 函数功能：	PID计算
* 参      数：	读入的温度
* 返 回  值：	无	改变incrementtemp的值，输出函数获得这个值然后输出
* 备	   注：	
**1
**********************************************************************/
void PID_realize(uint temp_n)
{
   temps[temp_n].err=temps[temp_n].settemp-temps[temp_n].actualtemp;//这两个都在结构体中
   temps[temp_n].incrementtemp=temps[temp_n].Kp*(temps[temp_n].err-temps[temp_n].err_next)+temps[temp_n].Ki*temps[temp_n].err+temps[temp_n].Kd*(temps[temp_n].err-2*temps[temp_n].err_next+temps[temp_n].err_last);
   temps[temp_n].err_last=temps[temp_n].err_next;
   temps[temp_n].err_next=temps[temp_n].err;
   temps[temp_n].incrementtemp=temps[temp_n].incrementtemp/2;
}
