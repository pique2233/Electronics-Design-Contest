#ifndef _PID_
#define _PID_

//#include "led.h"
//#define AIN2   PBout(12)
//#define AIN1   PBout(14)
typedef struct
{
 float Sv;//用户设定值
 float Pv;//采样值
 
 float Kp,Ki,Kd;
 float Ek;  //本次偏差
 float Ek_1;//上次偏差
 float Ek_2; 
	
 float OUT0;

 float PIDOUT;
	
 float  lowlimit;
 float  uplimit;
	
}Spe_PID;
typedef struct
{
 float Sv;//用户设定值
 float Pv;//采样值
 
 float Kp,Ki,Kd;
 float Ek;  //本次偏差
 float Ek_1;//上次偏差
 float Ek_2; 
 float OUT0;

 float PIDOUT;
	
 float  lowlimit;
 float  uplimit;
	
}Loc_PID;
typedef struct
{
 float Sv;//用户设定值目标
 float Pv;//采样值
 
 float Kp,Ki,Kd;
 float Ek;  //本次偏差
 float Ek_1;//上次偏差
	
 float OUT0;

 float PIDOUT;
	
 float  lowlimit;
 float  uplimit;
	
}Ele_PID;

extern Spe_PID Spe_pid; //存放PID算法所需要的数据
extern Loc_PID Loc_pid;

void Spe_PID_Init(void); //pid数据初始化
void Loc_PID_Init(void); 

int Loc_PID_output (int MuBiao_val,int JianCe_val);
int Spe_PID_output (int MuBiao_val,int JianCe_val);


float myabs(float a);
//float Set_Pwm(float moto1);
#endif



