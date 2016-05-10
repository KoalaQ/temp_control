
#ifndef __MAIN_H__
#define __MAIN_H__

#define uchar unsigned char
#define uint unsigned int
//串口发送数据需要
extern  unsigned int send_data_cache[139];
extern  unsigned int send_data_length;//数据长度
extern  unsigned int send_data_cur;//当前发送到游标 
//串口接收需要
extern unsigned int read_data_cur;
extern  unsigned int  read_data_cache[132];
extern  unsigned char read_data_cmd;//字母表示。如果是z表示空指令
//定时器功能转换需求
extern  unsigned int t0_flag;
//温度读取需要
extern  unsigned int temp_h;
extern  unsigned int temp_l;
//开始等待，温度时复用
extern  unsigned int waitflag;
//界面轮转，传值参数
extern  unsigned int pageNum;
extern  unsigned int pageParam[5];
extern  unsigned int prePageNum;
 //定义温度结构体，在此处，其他地方使用传递地址，然后解指
 //温度1、2、3、4
 //******************
 struct temp{
        //标志位。0：未初始化，显示未停止，代表数据为空的。1：正在运行，2：故障，
		//        3：暂停 4：运行结束，5：等待断点运行（此状态会在扫描时候自动接着上个暂停时间可以是从头开始的继续运行）
		//        6：保存重新运行（保存全新的参数，需要手动运行）
        unsigned int flag;
        unsigned int temp_data[132];  //阶段设置的参数
		//当前运行的状态，0是阶段，1、当前阶段需要时间，2、当前已进行时间
        unsigned int status;
		unsigned int needtime;
		unsigned int nowtime;
		unsigned int pertime;//每1C需要时间，计时
		unsigned int pertimecnt;//每1C需要时间，计时器
	    unsigned int statusflag;//是否第一次进入当前状态,1、第一次；0、不是第一次
		//控制相关
		unsigned int  p_settemp;//升温时候的小阶段需要温度
		unsigned int p_err_next;//升温阶段控制使用
		unsigned int p_Kp;//升温阶段控制使用
		unsigned int p_Ki;//升温阶段控制使用
		unsigned int p_err_last;
	  //PID 算法需要的参数
	  int  settemp;
	  int actualtemp;
	  int err;
	  int err_last;
	  int err_next;
	  int Kp;
	  int Ki;
	  int Kd;
	  int incrementtemp;
	  
};
//全局变量，温度
extern struct temp temps[4];
#endif