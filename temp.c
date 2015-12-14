#include<iom128v.h>
#include "temp.h"
#include "main.h"
#include "eeprom.h"
#include "lcd.h"
#include "max6675.h"
uint second;
void PID_realize(uint temp_n);
void set_start_real(uint t);

//中断1s进入，使用int2。可以使用，但是买的这个DS1307，硬件电路问题不可以使用
//  进行状态变换和参数调整,
/*升温：没1C变化温度更改参数，状态计算
/*恒温：只计算状态
/*****************************/
#pragma interrupt_handler int_int2:4
void int_int2(void){//做温度数据时间增加操作。不能做耗时的操作.中断优先级较高
  uint cache=0;//保存多次使用的数据，局部变量更快
  EIMSK &= 0xFB;//关中断2
  TIMSK&=0xBF;//关定时器2溢出中断,8位的
  //10分钟计时
  second++;
  if(second>600){
     //保存状态。保存flag、status、nowtime就行，下面需加上判断
	 second=0;
	  EEPROM_write(1,133,temps[0].flag);
	  if(temps[0].flag==1 || temps[0].flag==3){
	    EEPROM_write(1,134,temps[0].status);
	    EEPROM_write(1,135,temps[0].needtime>>8);
		EEPROM_write(1,136,temps[0].needtime & 0xFF);
		EEPROM_write(1,137,temps[0].nowtime>>8);
		EEPROM_write(1,138,temps[0].nowtime & 0xFF);
	    EEPROM_write(1,139,temps[0].pertime>>8);
		EEPROM_write(1,140,temps[0].pertime & 0xff);
		
	    EEPROM_write(1,141,temps[0].statusflag);
	    EEPROM_write(1,142,temps[0].p_settemp>>8 );
		EEPROM_write(1,143,temps[0].p_settemp&0xff);
		EEPROM_write(1,144,((int)temps[0].settemp)>>8);
	    EEPROM_write(1,145,((int)temps[0].settemp)&0xff);
	 }
	 EEPROM_write(2,133,temps[1].flag);
	  if(temps[1].flag==1 || temps[1].flag==3){
	    EEPROM_write(2,134,temps[1].status);
	    EEPROM_write(2,135,temps[1].needtime>>8);
		EEPROM_write(2,136,temps[1].needtime & 0xFF);
		EEPROM_write(2,137,temps[1].nowtime>>8);
		EEPROM_write(2,138,temps[1].nowtime & 0xFF);
	    EEPROM_write(2,139,temps[1].pertime>>8);
		EEPROM_write(2,140,temps[1].pertime & 0xff);
		
	    EEPROM_write(2,141,temps[1].statusflag);
	   EEPROM_write(2,142,temps[1].p_settemp>>8 );
		EEPROM_write(2,143,temps[1].p_settemp&0xff);
		EEPROM_write(2,144,((int)temps[1].settemp)>>8);
	    EEPROM_write(2,145,((int)temps[1].settemp)&0xff);
	 }
	 EEPROM_write(3,133,temps[2].flag);
	  if(temps[2].flag==1 || temps[2].flag==3){
	    EEPROM_write(3,134,temps[2].status);
	    EEPROM_write(3,135,temps[2].needtime>>8);
		EEPROM_write(3,136,temps[2].needtime & 0xFF);
		EEPROM_write(3,137,temps[2].nowtime>>8);
		EEPROM_write(3,138,temps[2].nowtime & 0xFF);
	    EEPROM_write(3,139,temps[2].pertime>>8);
		EEPROM_write(3,140,temps[2].pertime & 0xff);
	    EEPROM_write(3,141,temps[2].statusflag);
	    EEPROM_write(3,142,temps[2].p_settemp>>8 );
		EEPROM_write(3,143,temps[2].p_settemp&0xff);
		EEPROM_write(3,144,((int)temps[2].settemp)>>8);
	    EEPROM_write(3,145,((int)temps[2].settemp)&0xff);
	 }
	 EEPROM_write(4,133,temps[3].flag);
	  if(temps[3].flag==1 || temps[3].flag==3){
	    EEPROM_write(4,134,temps[3].status);
	    EEPROM_write(4,135,temps[3].needtime>>8);
		EEPROM_write(4,136,temps[3].needtime & 0xFF);
		EEPROM_write(4,137,temps[3].nowtime>>8);
		EEPROM_write(4,138,temps[3].nowtime & 0xFF);
	    EEPROM_write(4,139,temps[3].pertime>>8);
		EEPROM_write(4,140,temps[3].pertime & 0xff);
	    EEPROM_write(4,141,temps[3].statusflag);
	    EEPROM_write(4,142,temps[3].p_settemp>>8 );
		EEPROM_write(4,143,temps[3].p_settemp&0xff);
		EEPROM_write(4,144,((int)temps[3].settemp)>>8);
	    EEPROM_write(4,145,((int)temps[3].settemp)&0xff);
	 }
	 
  }
  //第一个
  if(temps[0].flag==1){//运行中
     cache=temps[0].status;//暂存当前状态
     if(temps[0].statusflag==0){//不是第一次进入当前状态
	     temps[0].nowtime++;//当前阶段运行时间
		if(temps[0].nowtime>=temps[0].needtime){//当前阶段运行结束进入下一阶段
		    temps[0].status++;
		    temps[0].statusflag=1;
			//PORTE=0xFF;
		}else{//还在当前阶段
		     if(cache & 0x01){//恒温阶段,
		         //执行pid算法控制温度就行,上面判断状态是否就行
		      }else{ //升温阶段
		            temps[0].pertimecnt++;
		            if(temps[0].pertimecnt>temps[0].pertime){
		                    temps[0].p_settemp++;//1C需要时间到达，增加温度。
			                temps[0].pertimecnt=0;
		              } 
			  }
		 }
	  }else{//第一次进入该状态。初始化当前状态.因为不是一直初始化，所以不必太担心耗时
	        temps[0].statusflag=0;
		    temps[0].nowtime=0;
	       if(cache & 0x01){//升温阶段
		      cache=((cache-1)>>1)*11;
		      temps[0].needtime=(temps[0].temp_data[cache]*10+temps[0].temp_data[cache+1])*3600+(temps[0].temp_data[cache+2]*10+temps[0].temp_data[cache+3])*60;
			  //temps[0].needtime=3;
			  if(temps[0].needtime==0){
			     //当前阶段时间为0，表示已经结束更改标记
				  temps[0].flag=4;
			  }else{
			     temps[0].p_settemp=temps[0].temp_data[cache+8]*100+temps[0].temp_data[cache+9]*10+temps[0].temp_data[cache+10];
			     temps[0].pertime=temps[0].needtime/(temps[0].p_settemp-temps[0].actualtemp);
			     temps[0].pertimecnt=0;
				 temps[0].settemp=temps[0].p_settemp;//当接近恒温温度时候使用pid需要此温度
			  }
		     
		    }else{//恒温阶段
			   cache=((cache-1)>>1)*11+4;
		      temps[0].needtime=(temps[0].temp_data[cache]*10+temps[0].temp_data[cache+1])*3600+(temps[0].temp_data[cache+2]*10+temps[0].temp_data[cache+3])*60;
			  //temps[0].needtime=3;
			  if(temps[0].needtime==0){
			     //当前阶段时间为0，表示已经结束更改标记
				  temps[0].flag=4;
			  }
			 // temps[0].settemp，在上一场升温时候赋值过
			}
	  }
  }
  //第二个
  if(temps[1].flag==1){//运行中
     cache=temps[1].status;//暂存当前状态
     if(temps[1].statusflag==0){//不是第一次进入当前状态
	     temps[1].nowtime++;//当前阶段运行时间
		if(temps[1].nowtime>=temps[1].needtime){//当前阶段运行结束进入下一阶段
		    temps[1].status++;
		    temps[1].statusflag=1;
			//PORTE=0xFF;
		}else{//还在当前阶段
		     if(cache & 0x01){//恒温阶段,
		         //执行pid算法控制温度就行,上面判断状态是否就行
		      }else{ //升温阶段
		            temps[1].pertimecnt++;
		            if(temps[1].pertimecnt>temps[1].pertime){
		                    temps[1].p_settemp++;//1C需要时间到达，增加温度。
			                temps[1].pertimecnt=0;
		              } 
			  }
		 }
	  }else{//第一次进入该状态。初始化当前状态.因为不是一直初始化，所以不必太担心耗时
	        temps[1].statusflag=0;
		    temps[1].nowtime=0;
	       if(cache & 0x01){//升温阶段
		      cache=((cache-1)>>1)*11;
		      temps[1].needtime=(temps[1].temp_data[cache]*10+temps[1].temp_data[cache+1])*3600+(temps[1].temp_data[cache+2]*10+temps[1].temp_data[cache+3])*60;
			  //temps[0].needtime=3;
			  if(temps[1].needtime==0){
			     //当前阶段时间为0，表示已经结束更改标记
				  temps[1].flag=4;
			  }else{
			     temps[1].p_settemp=temps[1].temp_data[cache+8]*100+temps[1].temp_data[cache+9]*10+temps[1].temp_data[cache+10];
			     temps[1].pertime=temps[1].needtime/(temps[1].p_settemp-temps[1].actualtemp);
			     temps[1].pertimecnt=0;
				 temps[1].settemp=temps[1].p_settemp;//当接近恒温温度时候使用pid需要此温度
			  }
		     
		    }else{//恒温阶段
			   cache=((cache-1)>>1)*11+4;
		      temps[1].needtime=(temps[1].temp_data[cache]*10+temps[1].temp_data[cache+1])*3600+(temps[1].temp_data[cache+2]*10+temps[1].temp_data[cache+3])*60;
			  //temps[1].needtime=3;
			  if(temps[1].needtime==0){
			     //当前阶段时间为0，表示已经结束更改标记
				  temps[1].flag=4;
			  }
			 // temps[1].settemp，在上一场升温时候赋值过
			}
	  }
  }
  //第三个
  if(temps[2].flag==1){//运行中
     cache=temps[2].status;//暂存当前状态
     if(temps[2].statusflag==0){//不是第一次进入当前状态
	     temps[2].nowtime++;//当前阶段运行时间
		if(temps[2].nowtime>=temps[2].needtime){//当前阶段运行结束进入下一阶段
		    temps[2].status++;
		    temps[2].statusflag=1;
			//PORTE=0xFF;
		}else{//还在当前阶段
		     if(cache & 0x01){//恒温阶段,
		         //执行pid算法控制温度就行,上面判断状态是否就行
		      }else{ //升温阶段
		            temps[2].pertimecnt++;
		            if(temps[2].pertimecnt>temps[2].pertime){
		                    temps[2].p_settemp++;//1C需要时间到达，增加温度。
			                temps[2].pertimecnt=0;
		              } 
			  }
		 }
	  }else{//第一次进入该状态。初始化当前状态.因为不是一直初始化，所以不必太担心耗时
	        temps[2].statusflag=0;
		    temps[2].nowtime=0;
	       if(cache & 0x01){//升温阶段
		      cache=((cache-1)>>1)*11;
		      temps[2].needtime=(temps[2].temp_data[cache]*10+temps[2].temp_data[cache+1])*3600+(temps[2].temp_data[cache+2]*10+temps[2].temp_data[cache+3])*60;
			  //temps[0].needtime=3;
			  if(temps[2].needtime==0){
			     //当前阶段时间为0，表示已经结束更改标记
				  temps[2].flag=4;
			  }else{
			     temps[2].p_settemp=temps[2].temp_data[cache+8]*100+temps[2].temp_data[cache+9]*10+temps[2].temp_data[cache+10];
			     temps[2].pertime=temps[2].needtime/(temps[2].p_settemp-temps[2].actualtemp);
			     temps[2].pertimecnt=0;
				 temps[2].settemp=temps[2].p_settemp;//当接近恒温温度时候使用pid需要此温度
			  }
		     
		    }else{//恒温阶段
			   cache=((cache-1)>>1)*11+4;
		      temps[2].needtime=(temps[2].temp_data[cache]*10+temps[2].temp_data[cache+1])*3600+(temps[2].temp_data[cache+2]*10+temps[2].temp_data[cache+3])*60;
			  //temps[0].needtime=3;
			  if(temps[2].needtime==0){
			     //当前阶段时间为0，表示已经结束更改标记
				  temps[2].flag=4;
			  }
			 // temps[0].settemp，在上一场升温时候赋值过
			}
	  }
  }
  //第一个
  if(temps[3].flag==1){//运行中
     cache=temps[3].status;//暂存当前状态
     if(temps[3].statusflag==0){//不是第一次进入当前状态
	     temps[3].nowtime++;//当前阶段运行时间
		if(temps[3].nowtime>=temps[3].needtime){//当前阶段运行结束进入下一阶段
		    temps[3].status++;
		    temps[3].statusflag=1;
			//PORTE=0xFF;
		}else{//还在当前阶段
		     if(cache & 0x01){//恒温阶段,
		         //执行pid算法控制温度就行,上面判断状态是否就行
		      }else{ //升温阶段
		            temps[3].pertimecnt++;
		            if(temps[3].pertimecnt>temps[3].pertime){
		                    temps[3].p_settemp++;//1C需要时间到达，增加温度。
			                temps[3].pertimecnt=0;
		              } 
			  }
		 }
	  }else{//第一次进入该状态。初始化当前状态.因为不是一直初始化，所以不必太担心耗时
	        temps[3].statusflag=0;
		    temps[3].nowtime=0;
	       if(cache & 0x01){//升温阶段
		      cache=((cache-1)>>1)*11;
		      temps[3].needtime=(temps[3].temp_data[cache]*10+temps[3].temp_data[cache+1])*3600+(temps[3].temp_data[cache+2]*10+temps[3].temp_data[cache+3])*60;
			  //temps[0].needtime=3;
			  if(temps[3].needtime==0){
			     //当前阶段时间为0，表示已经结束更改标记
				  temps[3].flag=4;
			  }else{
			     temps[3].p_settemp=temps[3].temp_data[cache+8]*100+temps[3].temp_data[cache+9]*10+temps[3].temp_data[cache+10];
			     temps[3].pertime=temps[3].needtime/(temps[3].p_settemp-temps[3].actualtemp);
			     temps[3].pertimecnt=0;
				 temps[3].settemp=temps[3].p_settemp;//当接近恒温温度时候使用pid需要此温度
			  }
		     
		    }else{//恒温阶段
			   cache=((cache-1)>>1)*11+4;
		      temps[3].needtime=(temps[3].temp_data[cache]*10+temps[3].temp_data[cache+1])*3600+(temps[3].temp_data[cache+2]*10+temps[3].temp_data[cache+3])*60;
			  //temps[0].needtime=3;
			  if(temps[3].needtime==0){
			     //当前阶段时间为0，表示已经结束更改标记
				  temps[3].flag=4;
			  }
			 // temps[0].settemp，在上一场升温时候赋值过
			}
	  }
  }
  TIMSK|=0x40;//开定时器2溢出中断,8位的
  EIMSK |= 0x04;//开中断2  
}
 //执行温度控制数据更新操作，读取温度更新输出参数.会对温度数据故障更新
 //定时器控制，0.5s进入一次
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
			    temps[i].actualtemp/=10;
		        if(temps[i].status & 0x01){//恒温阶段，使用pid算法。temps[i].status & 0x01如果是1代表是奇数，0代表是偶数
				   //PID_realize(i);//启用pid算法
                }else if(temps[i].settemp-temps[i].actualtemp<10){
		           //升温或阶段，如果温度接近某个温度则开始使用PID算法。这个值要重新考虑
				   //PID_realize(i);//启用pid算法
		         }else {//升温使用pi算法
		            //PI_realize(i);//启用pi算法
		         }
	      }else if(temps[i].flag==5){//初始化参数
	             temps[i].flag=1;
				 temps[i].status=1;
				 temps[i].statusflag=1;
				  EEPROM_write(i+1,133,5);//先写状态为5，预防在刚开始还未记录状态时候发生断电。
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
	temps[i].status=0;
	temps[i].needtime=0;
	temps[i].nowtime=0;
	temps[i].pertime=0;//每1C需要时间，计时
	temps[i].pertimecnt=0;//每1C需要时间，计时器
	temps[i].statusflag=1;//是否第一次进入当前状态,1、第一次；0、不是第一次
		//控制相关
	temps[i].p_settemp=0;//升温时候的小阶段需要温度
	temps[i].p_err_next=0;//升温阶段控制使用
	temps[i].p_Kp=0;//升温阶段控制使用
	temps[i].p_Ki=0;//升温阶段控制使用
    temps[i].p_err_last=0;
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
	  if(temps[i].flag==1 || temps[i].flag==3){
	    temps[i].status=EEPROM_read(i+1,134);
	    temps[i].needtime =EEPROM_read(i+1,135)<<8 | EEPROM_read(i+1,136);
		temps[i].nowtime=EEPROM_read(i+1,137)<<8  | EEPROM_read(i+1,138);
	    temps[i].pertime=EEPROM_read(i+1,139)<<8 | EEPROM_read(i+1,140);
	    temps[i].statusflag=EEPROM_read(i+1,141);
	    temps[i].p_settemp=EEPROM_read(i+1,142)<<8  | EEPROM_read(i+1,143);
	    temps[i].settemp=EEPROM_read(i+1,144)<<8 | EEPROM_read(i+1,145);
	  }
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
	   EEPROM_write(t+1,j+1,temps[t].temp_data[j]);//这里要保存的
	}
}

//重置指定的数据,保存相关标志位
void reset_temp_data(uint t){
    uint j;
	temps[t].flag=0;
	temps[t].status=0;
	temps[t].statusflag=1;//是否第一次进入当前状态,1、第一次；0、不是第一次
		//控制相关
	temps[t].p_settemp=0;//升温时候的小阶段需要温度
	temps[t].p_err_next=0;//升温阶段控制使用
    temps[t].p_err_last=0;
	 temps[t].err_last=0;
	 temps[t].err_next=0;
	
	EEPROM_write(t+1,0,0x00);
	EEPROM_write(t+1,133,0x00);
    for(j=0;j<132;j++){
	   temps[t].temp_data[j]=0;
	   EEPROM_write(t+1,j+1,0);//这里要保存的
	}
	 EEPROM_write(t+1,134,0);
	 EEPROM_write(t+1,135,0);
	 EEPROM_write(t+1,136,0);
	 EEPROM_write(t+1,137,0);
	 EEPROM_write(t+1,138,0);
	 EEPROM_write(t+1,139,0);
	 EEPROM_write(t+1,140,0);
	 EEPROM_write(t+1,141,0);
	 EEPROM_write(t+1,142,0);
	 EEPROM_write(t+1,143,0);
	 EEPROM_write(t+1,144,0);
	 EEPROM_write(t+1,145,0);
}
//温度全部开始工作。状态为停止和刚重置数据的可以开始
void set_all_start(void){
    uint j;
	
    for(j=0;j<4;j++){
	    if(temps[j].flag==3){
	           temps[j].flag=1;
	      }else if(temps[j].flag==6){
	             temps[j].flag=5;

	      }
	}
}
//温度全部暂停.要运行的才会暂停。。关闭输出
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
  if(temps[t].flag==3){
	     temps[t].flag=1;
		///  EEPROM_write(t+1,133,5);
	}else if(temps[t].flag==6){
	     temps[t].flag=5;
		///  EEPROM_write(t+1,133,5);
	}else if(temps[t].flag==4){
	     temps[t].flag=5;
		///  EEPROM_write(t+1,133,5);
	}
}

//指定温度暂停。关闭输出
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
void PI_realize(uint temp_n)
{
   temps[temp_n].err=temps[temp_n].p_settemp-temps[temp_n].actualtemp;//这两个都在结构体中
   temps[temp_n].incrementtemp=temps[temp_n].p_Kp*(temps[temp_n].err-temps[temp_n].p_err_next)+temps[temp_n].p_Ki*temps[temp_n].err;
   temps[temp_n].p_err_last=temps[temp_n].p_err_next;
   temps[temp_n].p_err_next=temps[temp_n].err;
   temps[temp_n].incrementtemp=temps[temp_n].incrementtemp/2;
}