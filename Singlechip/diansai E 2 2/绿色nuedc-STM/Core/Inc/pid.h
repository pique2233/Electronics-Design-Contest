#ifndef __PID_H
#define __PID_H

//typedef struct {
//    float currentX;    // 当前舵机位置X
//    float currentY;    // 当前舵机位置Y
//    float prevErrorX;  // 上一次舵机位置X的误差
//    float prevErrorY;  // 上一次舵机位置Y的误差
//    float sumErrorX;   // 舵机位置X的误差累计
//    float sumErrorY;   // 舵机位置Y的误差累计
//} ServoState;


//void updateServoState(ServoState *state1, float newX, float newY);
//void pidControl(ServoState *gensui, float newX, float newY);
//void PID_init();

//typedef struct 
//{
//	float target_val;//目标值
//	float actual_val;//实际值
//	float err;//当前偏差
//	float err_last;//上次偏差
//	float err_sum;//误差累计值
//	float Kp,Ki,Kd;//比例，积分，微分系数
//	
//} tPid;

//void PID_init(void);
//float PID_realize(tPid * pid,float Green_actual_val,float Red_target_val);


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

extern Spe_PID Spe_pid; //存放PID算法所需要的数据
extern Loc_PID Loc_pid;

void PID_Init(void); //pid数据初始化

int Loc_PID_output (int actual_val,int target_val);
int Spe_PID_output (int actual_val,int target_val);

#endif
