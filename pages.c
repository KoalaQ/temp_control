#include<iom128v.h>
#include "main.h"
#include "lcd.h"
#include "time.h"
#include "timertask.h"
#include "key.h"
#include "delay.h"
//************************
// 所有界面信息在这里,用到全局变量， 
// unsigned int pageNum;//当前页面，如需跳转改变这个值就行
// unsigned int pageParam[5];//传递参数。界面间参数暂存
// unsigned int prePageNum;
//************************

//用于显第一行日期信息，其中Page1、Page3 、Page8使用，
//由定时器触发该函数，进入这三个界面是启动定时器，退出时关闭
void pageTime(uint y){
                //关定时器
   lcd_write_str(0,y,"时间:");
   showTime_page(y);
                 //开定时器 
}
//page1,首页的界面
void page1(void){
   uint cur=0;
   uchar keyV;
   uint i;//用于循环
   uint y;//确定是那个半屏幕
   prePageNum=1;//首页不会再有上一界面，这里设置。虽然违反规则
   //初始化起始选择
	 
   
   
   lcd_write_str(1,1," T1:100");
   lcd_write_char(5,1,0xA1);
   lcd_write_char_con(1,0xE6);
	
   
    lcd_write_str(6,1," T2:800");
	lcd_write_char(10,1,0xA1);
	lcd_write_char_con(1,0xE6);
	
    lcd_write_str(1,2," T3:停止");

    lcd_write_str(6,2," T4:故障");

	
	lcd_write_str(1,3,"开始    ");
    lcd_write_str_con(3,"停止    ");
	lcd_write_str_con(3,"设置");
	
	
	
	 
	cur=0;
	Set_White(2,1,3);
	while(1){
	 pageTime(0);
	for(i=0;i<4;i++){
	  if(i==0){
	    y=1;
	    lcd_write_pos(3,1);
	  }else if(i==1){
	    y=1;
	    lcd_write_pos(8,1);
	  }else if(i==2){
	    y=2;
	    lcd_write_pos(3,2);
	  }else if(i==3){
	    y=2;
	    lcd_write_pos(8,2);
	  }
	   switch(temps[i].flag){
	     case 0:
		   lcd_write_str_con(y,"停止");
		   break;
		 case 1:
		   lcd_write_str_con(y,"150");
		   break;
		 case 2:
		   lcd_write_str_con(y,"故障");
		   break;
		 case 3:
		   lcd_write_str_con(y,"暂停");
		   break;
		 case 4:
		   lcd_write_str_con(y,"结束");
		   break;
		 case 5:
		   lcd_write_str_con(y,"等待");
		   break;
		 case 6:
		   lcd_write_str_con(y,"加载");
		   break;
		   break;
		 default:
		   break;
	   }
	}
	 keyV=KeyScan_once();
	 if(keyV=='a'){
	      //pageNum=8;//跳转到设置时间的界面
		   pageNum=8;
	   switch(cur){
		 case 0: 
		    Set_White_off(2,1,3);
		    break;
		 case 1:
		   Set_White_off(7,1,8);
		   break;
		 case 2:
		  Set_White_off(2,2,3);
		  break;
		 case 3:
		   Set_White_off(7,2,8);
		    break;
		case 5:
		    Set_White_off(6,3,7);
		    break;
		 case 6:
		   Set_White_off(10,3,11);
		    break;
		  default:
		   break;
		 }
	   return ;
	}else if(keyV=='d'){
	     switch(cur){
		  case 0:
		   Set_White_off(2,1,3);
		   Set_White(2,2,3);
		   cur=2;
		   break;
		  case 1:
		   Set_White_off(7,1,8);
		   Set_White(7,2,8);
		   cur=3;
		   break;
		  case 2:
		   Set_White_off(2,2,3);
		   Set_White(2,3,3);
		   cur=4;
		   break;
		  case 3:
		   Set_White_off(7,2,8);
		   Set_White(6,3,7);
		   cur=5;
		   break;
		  default:
		   break;
		 }
	}else if(keyV=='u'){switch(cur){
		  case 2:
		   Set_White_off(2,2,3);
		   Set_White(2,1,3);
		   cur=0;
		   break;
		  case 3:
		   Set_White_off(7,2,8);
		   Set_White(7,1,8);
		   cur=1;
		   break;
		  case 4:
		   Set_White_off(2,3,5);
		   Set_White(2,2,3);
		   cur=2;
		   break;
		  case 5:
		   Set_White_off(6,3,7);
		   Set_White(7,2,8);
		   cur=3;
		   break;
		  case 6:
		   Set_White_off(10,3,11);
		   Set_White(7,2,8);
		   cur=3;
		   break;
		  default:
		   break;
		 }
	}else if(keyV=='l'){switch(cur){
		  case 1:
		   Set_White_off(7,1,8);
		   Set_White(2,1,3);
		   cur=0;
		   break;
		  case 3:
		   Set_White_off(7,2,8);
		   Set_White(2,2,3);
		   cur=2;
		   break;
		  case 5:
		   Set_White_off(6,3,7);
		   Set_White(2,3,3);
		   cur=4;
		   break;
		  case 6:
		   Set_White_off(10,3,11);
		   Set_White(6,3,7);
		   cur=5;
		   break;
		  default:
		   break;
		 }
	}else if(keyV=='r'){
	switch(cur){
		  case 0:
		   Set_White_off(2,1,3);
		   Set_White(7,1,8);
		   cur=1;
		   break;
		  case 2:
		   Set_White_off(2,2,3);
		   Set_White(7,2,8);
		   cur=3;
		   break;
		  case 4:
		   Set_White_off(2,3,3);
		   Set_White(6,3,7);
		   cur=5;
		   break;
		  case 5:
		   Set_White_off(6,3,7);
		   Set_White(10,3,11);
		   cur=6;
		   break;
		  default:
		   break;
		 }
	}else if(keyV=='s'){
	   pageNum=5;
	   switch(cur){
		 case 0: 
		    Set_White_off(2,1,3);
		    break;
		 case 1:
		   Set_White_off(7,1,8);
		   break;
		 case 2:
		  Set_White_off(2,2,3);
		  break;
		 case 3:
		   Set_White_off(7,2,8);
		    break;
		case 5:
		    Set_White_off(6,3,7);
		    break;
		 case 6:
		   Set_White_off(10,3,11);
		    break;
		  default:
		   break;
		 }
	   return ;
	}else if(keyV=='t'){
	   switch(cur){
		 case 0: 
		    Set_White_off(2,1,3);
		    prePageNum=1;
		    pageParam[0]=0;//传递使用第一个，对应不同的温度
		    pageNum=3;
		    return;
		 case 1:
		   Set_White_off(7,1,8);
		    prePageNum=1;
		   pageParam[0]=1;//传递使用第一个，对应不同的温度
		    pageNum=3;
		    return;
		 case 2:
		  Set_White_off(2,2,3);
		    prePageNum=1;
		    pageParam[0]=2;//传递使用第一个，对应不同的温度
		   pageNum=3;
		   return;
		 case 3:
		   Set_White_off(7,2,8);
		     prePageNum=1;
		    pageParam[0]=3;//传递使用第一个，对应不同的温度
		    pageNum=3;
		    return;
		 case 4:
		    //调用函数全部开始，参数正确的
		   break;
		 case 5:
		    //全部停止
		   break;
		 case 6:
		   Set_White_off(10,3,11);
		    prePageNum=1;
		   pageNum=5;
		    return;
		  default:
		   break;
		 }
	
	}
  }
   return;
}
 void page2(void){
   uint cur=0;
   uchar keyV;
   //初始画面，会有读取EEPROM的判断默认操作，本次只是画界面
   lcd_write_str(2,0,"是否恢复上次工作");
   lcd_write_str(2,2,"恢复");
   lcd_write_str(8,2,"取消");
   Set_White(3,2,4);
    while(1){
      keyV=KeyScan_once();
	  switch(keyV){
	    case 'l':
		   if(cur==1){
		      Set_White_off(9,2,10);
		      Set_White(3,2,4);
			  cur=1;
		   }
		   break;
		case 'r':
		   if(cur==0){
		      Set_White_off(3,2,4);
		      Set_White(9,2,10);
			  cur=0;
		   }
		  break;
		case 't':
		  //执行相关操作
		   Set_White_off(9,2,10);
		    Set_White_off(3,2,4);
		  pageNum=1;
		  return;
	  }
	}
 }
 void page3(void){
  uint cur=0;
   uchar keyV;
   lcd_write_str(2,0,"单个温控界面");
   //Set_White(9,2,10);
    while(1){
      keyV=KeyScan_once();
	  if(keyV=='e'){
		    pageNum=1;
		    return;
	  }
	}
 }
  void page4(void){
    uint cur=0;
   uchar keyV;
   lcd_write_str(2,0,"单个温控设置界面");
   //Set_White(9,2,10);
    while(1){
      keyV=KeyScan_once();
	  if(keyV=='e'){
		    pageNum=3;
		    return;
	  }
	}
 }
 void page5(void){
  uint cur=0;
   uchar keyV;
   lcd_write_str(4,0,"断电自动重置");
   lcd_write_str(4,1,"设置时间");
   lcd_write_str(4,2,"重置系统");
   lcd_write_char(3,0,0xA1);
   lcd_write_char_con(0,0xC1);
   
   /* lcd_write_char(1,0,0xA1);
   lcd_write_char_con(0,0xCC);*/
   cur=0;
   Set_White(5,0,10);
   while(1){
      keyV=KeyScan_once();
	  if(keyV=='u'){
	    switch(cur){
		  case 1:
		   Set_White_off(5,1,8);
		   Set_White(5,0,10);
		   cur=0;
		   break;
		  case 2: 
		   Set_White_off(5,2,8);
		   Set_White(5,1,8);
		   cur=1;
		   break;
		}
	  }else if(keyV=='d'){
	      switch(cur){
		  case 0:
		   Set_White_off(5,0,10);
		   Set_White(5,1,8);
		   cur=1;
		   break;
		  case 1: 
		   Set_White_off(5,1,8);
		   Set_White(5,2,8);
		   cur=2;
		   break;
		}
	  }else if(keyV=='e'){
	     switch(cur){
		 case 0: 
		   Set_White_off(5,0,10);
		    break;
		 case 1:
		   Set_White_off(5,1,8);
		   break;
		 case 2:
		  Set_White_off(5,2,8);
		  break;
	
		  default:
		   break;
		 }
	    pageNum=1;
		return;
	  }else if(keyV=='t'){
	    switch(cur){
		  case 0:
		     //执行EEPROM操作
		    break;
		  case 1:
		   pageNum=8;
		   Set_White_off(5,1,8);
		   return;
		  
		  case 2:
		    pageNum=7;
		    Set_White_off(5,2,8);
		   return;
		}
	    
	  }
   }
   
 }
 void page6(void){//复用的方法
   lcd_write_str(5,1,"保存成功！");
   delay_ms(500);
   pageNum=prePageNum;
 }
 void page7(void){
   uint cur=1;
   uchar keyV;
   lcd_write_str(2,0,"是否重置");
   lcd_write_str(2,2,"确认");
   lcd_write_str(8,2,"取消");
   Set_White(9,2,10);
    while(1){
      keyV=KeyScan_once();
	  switch(keyV){
	    case 'l':
		   if(cur==1){
		      Set_White_off(9,2,10);
		      Set_White(3,2,4);
			  cur=0;
		   }
		   break;
		case 'r':
		   if(cur==0){
		      Set_White_off(3,2,4);
		      Set_White(9,2,10);
			  cur=1;
		   }
		  break;
		case 't':
		  //执行相关操作	  
		  if(cur==0){
		     Set_White_off(3,2,4);
			 
		       //进入重置画面。在Page9启动看门狗重置系统、不喂狗
		       pageNum=9;
		  }else {
		      Set_White_off(9,2,10);
		       pageNum=5;
		  }
		  return;
		 case 'e':
		    Set_White_off(3,2,4);
		    Set_White_off(9,2,10);
		    pageNum=5;
		    return;
	  }
	}
 }
 //由于使用DS1307，暂时不做读取和保存时间的。等实时时钟模块买来
 void page8(void){
   uint cur=0;
   uchar keyV;
   uchar date[15];
   uint i;
    uint dateAc[14]={1,2,3,4,6,7,9,10,2,3,5,6,8,9};
	prePageNum=8;//同样 是违反规则的设置
   date[0]=2;
   date[1]=0;
   date[2]=1;
   date[3]=5;
   date[4]=1;
   date[5]=2;
   date[6]=2;
   date[7]=5;
   date[8]=1;
   date[9]=2;
   date[10]=3;
   date[11]=0;
   date[12]=5;
   date[13]=0;
    lcd_write_pos(1,0);
  for(i=0;i<8;i++){
   lcd_write_char_con(0,0x30 | date[i]);
    lcd_write_char_con(0,' ');
	if(i==3 || i==5){
	  lcd_write_str_con(0,"- ");
	}
  }
   lcd_write_pos(2,1);
   for(i=8;i<14;i++){
   lcd_write_char_con(1,0x30 | date[i]);
   lcd_write_char_con(0,' ');
   if(i==9 || i==11){
	 lcd_write_str_con(0,": ");
   }
  } 
   lcd_write_str(3,2,"保存");
   lcd_write_str(8,2,"取消");
   //初始化date
  
   cur=0;
   lcd_write_pos(1,0);//初始游标位置
   cur_set(3);//上半屏幕游标设置
   while(1){
     pageTime(3);//
	 keyV=KeyScan_once();
	 if(keyV=='u'){
	   if(cur>13){//调到时间第一个
	        Set_White_off(4,2,5);
			Set_White_off(9,2,10);
	        lcd_write_pos(2,1);
		    cur_set(3);
			cur=8; 
		   }else if(cur>7 && cur <14){//调到日期第一个
		    lcd_write_pos(1,0);
			cur=0; 
		   }
	 }else if(keyV=='d'){
	     if(cur>7 && cur <14){//在时间上，第三行，默认要保存，所以调到保存上
		      cur_set(0);//关下半屏幕游标
			  Set_White(4,2,5);
			  cur=14;
		 }else if(cur<=7){ //调到时间第一个
		    lcd_write_pos(2,1);
			cur=8; 
		 }
	 }else if(keyV=='l'){
			if(cur<=8 && cur>0){
			 cur--;
			 lcd_write_pos(dateAc[cur],0);
			}else if (cur>8 && cur<14){
			 cur--;
			 lcd_write_pos(dateAc[cur],1);
			}else if (cur==15){
			    Set_White_off(9,2,10);
			    Set_White(4,2,5);
				cur=14;
			}
			
		
	 }else if(keyV=='r'){
	       if(cur<7){
			   cur++;
			   lcd_write_pos(dateAc[cur],0);
			}else if (cur<13){
			   cur++;
			   lcd_write_pos(dateAc[cur],1);
			}else if (cur==14){
			    Set_White_off(4,2,5);
				Set_White(9,2,10);
				cur=15;
			}
	 }else if(keyV=='e'){
	     cur_set(0);//关上半屏幕游标
		  Set_White_off(4,2,5);
		  Set_White_off(9,2,10);
		 pageNum=1;
		 return;
	     //退出界面
	 }else if(keyV=='t'){
	      if(cur==14){
		        //保存操作
				pageNum=6;
				return;
		 }else if(cur==15){
		        //取消操作
			 cur_set(0);//关上半屏幕游标
		  Set_White_off(4,2,5);
		  Set_White_off(9,2,10);
		 pageNum=1;
		 return;
		 }
	 }else if(keyV=='0' || keyV=='1' || keyV=='2' || keyV=='3' || keyV=='4' || keyV=='5' 
	           || keyV=='6'  || keyV=='7' || keyV=='8' || keyV=='9'){
			if(cur<14){
			 lcd_write_char_con(0,0x30 | keyV);
			 lcd_write_char_con(0,' ');
			 date[cur]=keyV;
			  if(cur==3 || cur==5){
			    lcd_write_str_con(0,"- ");
			 }else if(cur==9 || cur==11){
			    lcd_write_str_con(0,": ");
			 }
			 cur++;
			 if(cur==8){
			    lcd_write_pos(dateAc[8],1);
			 }else if(cur==14){
			  cur_set(0);//关下半屏幕游标
			  Set_White(4,2,5);
			 }
			}
	 }
   }
 }
void page9(void){//复用的方法
   lcd_write_str(5,1,"重置中。。。。");
   while(1){
      
   }
 }
//分发Pages
void dispatchPages(void){
      lcd_clear();//清屏幕
      if(pageNum==1){
	    page1();
	  }else if(pageNum==2){
	    page2();
	  }else if(pageNum==3){
	    page3();
	  }else if(pageNum==4){
	    page4();
	  }else if(pageNum==5){
	    page5();
	  }else if(pageNum==6){
	    page6();
	  }else if(pageNum==7){
	    page7();
	  }else if(pageNum==8){
	    page8();
	  }else if(pageNum==9){
	    page9();
	  }
	         
}