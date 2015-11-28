#include<iom128v.h>
#include "main.h"
#include "lcd.h"
#include "time.h"
#include "timertask.h"
#include "key.h"
//************************
// ���н�����Ϣ������,�õ�ȫ�ֱ����� 
// unsigned int pageNum;//��ǰҳ�棬������ת�ı����ֵ����
// unsigned int pageParam[5];//���ݲ��������������ݴ�
// unsigned int prePageNum;
//************************

//�����Ե�һ��������Ϣ������Page1��Page3 ��Page8ʹ�ã�
//�ɶ�ʱ�������ú���������������������������ʱ�����˳�ʱ�ر�
void pageUtil(void){
                //�ض�ʱ��
   lcd_write_str(0,0,"ʱ��:");
   showTime_page();
                 //����ʱ�� 
}
//page1,��ҳ�Ľ���
void page1(void){
   uint cur=0;
   uchar keyV;
   uint i;//����ѭ��
   uint y;//ȷ�����Ǹ�����Ļ
   //��ʼ����ʼѡ��
	 
   
   
   lcd_write_str(1,1," T1:100");
   lcd_write_char(5,1,0xA1);
   lcd_write_char_con(1,0xE6);
	
   
    lcd_write_str(6,1," T2:800");
	lcd_write_char(10,1,0xA1);
	lcd_write_char_con(1,0xE6);
	
    lcd_write_str(1,2," T3:ֹͣ");

    lcd_write_str(6,2," T4:����");

	
	lcd_write_str(1,3,"��ʼ    ");
    lcd_write_str_con(3,"ֹͣ    ");
	lcd_write_str_con(3,"����");
	
	
	
	 
	cur=0;
	Set_White(2,1,3);
	while(1){
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
		   lcd_write_str_con(y,"ֹͣ");
		   break;
		 case 1:
		   lcd_write_str_con(y,"150");
		   break;
		 case 2:
		   lcd_write_str_con(y,"����");
		   break;
		 case 3:
		   lcd_write_str_con(y,"��ͣ");
		   break;
		 case 4:
		   lcd_write_str_con(y,"����");
		   break;
		 case 5:
		   lcd_write_str_con(y,"�ȴ�");
		   break;
		 case 6:
		   lcd_write_str_con(y,"����");
		   break;
		   break;
		 default:
		   break;
	   }
	}
	 pageUtil();
	 keyV=KeyScan_once();
	 if(keyV=='a'){
	      //pageNum=8;//��ת������ʱ��Ľ���
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
		    pageParam[0]=0;//����ʹ�õ�һ������Ӧ��ͬ���¶�
		    pageNum=3;
		    return;
		 case 1:
		   Set_White_off(7,1,8);
		    prePageNum=1;
		   pageParam[0]=1;//����ʹ�õ�һ������Ӧ��ͬ���¶�
		    pageNum=3;
		    return;
		 case 2:
		  Set_White_off(2,2,3);
		    prePageNum=1;
		    pageParam[0]=2;//����ʹ�õ�һ������Ӧ��ͬ���¶�
		   pageNum=3;
		   return;
		 case 3:
		   Set_White_off(7,2,8);
		     prePageNum=1;
		    pageParam[0]=3;//����ʹ�õ�һ������Ӧ��ͬ���¶�
		    pageNum=3;
		    return;
		 case 4:
		    //���ú���ȫ����ʼ��������ȷ��
		   break;
		 case 5:
		    //ȫ��ֹͣ
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
 void page3(void){
   lcd_write_str(1,1,"Page3");
 }
 void page5(void){
  uint cur=0;
   uchar keyV;
   lcd_write_str(4,0,"�ϵ��Զ�����");
   lcd_write_str(4,1,"����ʱ��");
   lcd_write_str(4,2,"����ϵͳ");
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
		     //ִ��EEPROM����
		    break;
		  case 1:
		   pageNum=8;
		   Set_White_off(5,1,8);
		   return;
		  
		  case 2:
		    //����ϵͳ
		    break;
		}
	    
	  }
   }
   
 }
 void page8(void){
   lcd_write_str(1,1,"Page8");
   while(1){
   
   }
 }
//�ַ�Pages
void dispatchPages(void){
      lcd_clear();//����Ļ
      if(pageNum==1){
	    page1();
	  }else if(pageNum==2){
	   // page2();
	  }else if(pageNum==3){
	    page3();
	  }else if(pageNum==4){
	   // page4();
	  }else if(pageNum==5){
	    page5();
	  }else if(pageNum==6){
	   // page6();
	  }else if(pageNum==7){
	    //page7();
	  }else if(pageNum==8){
	    page8();
	  }
	         
}