
#ifndef __MAIN_H__
#define __MAIN_H__

#define uchar unsigned char
#define uint unsigned int
extern  unsigned int temp_h;
extern  unsigned int temp_l;

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
		//当前运行的状态，0是阶段，1：温度，2、3、4 对应时分秒
       // unsigned int status[4];
		//unsigned int pid[4];  //PID 算法需要的参数
};
//全局变量，温度
extern struct temp temps[4];
#endif