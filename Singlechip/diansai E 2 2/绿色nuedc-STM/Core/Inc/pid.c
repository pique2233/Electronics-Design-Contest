#include "pid.h"
#include <stdio.h>
#include "tim.h"

//#define TARGET_X 1250    // 期望舵机位置X
//#define TARGET_Y 300    // 期望舵机位置Y

//#define KP 1.01        // 比例系数
//#define KI 0.01        // 积分系数
//#define KD 0        // 微分系数
//ServoState gensui;
//ServoState servo1;  // 舵机状态

//void PID_init()
//{
//    
//    gensui.currentX = 0;//当前舵机位置X
//    gensui.currentY = 0;
//    gensui.prevErrorX = 0;//上一次舵机位置X的误差
//    gensui.prevErrorY = 0;
//    gensui.sumErrorX = 0;
//    gensui.sumErrorY = 0;//舵机位置Y的误差累计
//}


//// 更新舵机状态
//void updateServoState(ServoState *gensui, float newX, float newY) {
//    gensui->prevErrorX = TARGET_X - newX;
//    gensui->prevErrorY = TARGET_Y - newY;
//    gensui->sumErrorX += gensui->prevErrorX;
//    gensui->sumErrorY += gensui->prevErrorY;
//    gensui->currentX = newX;
//    gensui->currentY = newY;
//}

//// 二维舵机云台 PID 控制函数
//void pidControl(ServoState *gensui, float newX, float newY) {
//    gensui->prevErrorX = TARGET_X - newX;
//    gensui->prevErrorY = TARGET_Y - newY;
//    gensui->sumErrorX += gensui->prevErrorX;
//    gensui->sumErrorY += gensui->prevErrorY;
//    gensui->currentX = newX;
//    gensui->currentY = newY;
//    float errorX = TARGET_X - gensui->currentX;
//    float errorY = TARGET_Y - gensui->currentY;
//    float deltaErrorX = errorX - gensui->prevErrorX;
//    float deltaErrorY = errorY - gensui->prevErrorY;

//    // 计算控制量
//    float controlX = KP * errorX + KI * gensui->sumErrorX + KD * deltaErrorX;
//    float controlY = KP * errorY + KI * gensui->sumErrorY + KD * deltaErrorY;
//    printf("X:%.3f\r\n",controlX);
//    printf("Y:%.3f\r\n",controlY);
//    printf("\r\n");

//    // 执行控制动作
//    // 这里可以根据具体的舵机控制方式进行实现
//   __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, controlY);  //竖直 PA6 
//   __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_4, controlX);  //水平 PB11  

//    // 更新舵机状态
////    updateServoState(gensui, gensui->currentX + controlX, gensui->currentY + controlY);

//}

//tPid pidFollow_x;    //定距离跟随PID
//tPid pidFollow_y;

Loc_PID Loc_pid; //存放PID算法所需要的数据
Spe_PID Spe_pid;

extern uint8_t g_ucaUsart2ReceiveBuffer[20];//保存串口接收有效数据的数组

void PID_Init()
{
    Loc_pid.Sv=g_ucaUsart2ReceiveBuffer[2];     //red_x用户设定值
	Loc_pid.Pv=g_ucaUsart2ReceiveBuffer[4];      //green_x检测值
	Loc_pid.OUT0 =00;      //PID常数
	Loc_pid.Ek=0.0;       //当前误差值    
	Loc_pid.Ek_1=0.0;     //上一个误差值
	Loc_pid.Kp=0.25;//0.6;     //比例常数
	Loc_pid.Ki=0.006;//0.007;       //积分常数
	Loc_pid.Kd=-0.001;       //微分常数
	Loc_pid.uplimit=1000; //上限值
	Loc_pid.lowlimit=600;//下限值
	Loc_pid.PIDOUT=750;
    
    Spe_pid.Sv=g_ucaUsart2ReceiveBuffer[3];     //red_y用户设定值
	Spe_pid.Pv=g_ucaUsart2ReceiveBuffer[5];      //green_y检测值
	Spe_pid.OUT0 =0;      //PID常数
	Spe_pid.Ek=0.0;       //当前误差值
	Spe_pid.Ek_1=0.0;     //上一个误差值
	Spe_pid.Ek_2=0.0;     //上上一个误差值
	Spe_pid.Kp=-0.2;     //比例常数
	Spe_pid.Ki=-0.006;//-0.007;      //积分常数
	Spe_pid.Kd=0.001;       //微分常数
	Spe_pid.uplimit=1250; //上限值
	Spe_pid.lowlimit=500;//下限值
	Spe_pid.PIDOUT=950;
    
//    pidFollow_x.actual_val=0.0;
//	pidFollow_x.target_val=0.0;//定距离跟随 目标距离22.5cm
//	pidFollow_x.err=0.0;
//	pidFollow_x.err_last=0.0;
//	pidFollow_x.err_sum=0.0;
//	pidFollow_x.Kp=1.1;//定距离跟随的Kp大小通过估算PID输入输出数据，确定大概大小，然后在调试
//	pidFollow_x.Ki=0;//Ki小一些
//	pidFollow_x.Kd=0;
//    
//    pidFollow_y.actual_val=0.0;
//	pidFollow_y.target_val=0.0;//定距离跟随 目标距离22.5cm
//	pidFollow_y.err=0.0;
//	pidFollow_y.err_last=0.0;
//	pidFollow_y.err_sum=0.0;
//	pidFollow_y.Kp=1.1;//定距离跟随的Kp大小通过估算PID输入输出数据，确定大概大小，然后在调试
//	pidFollow_y.Ki=0;//Ki小一些
//	pidFollow_y.Kd=0;   
    
}
//float PID_realize(tPid * pid,float Green_actual_val,float Red_target_val)
//{
    
//	pid->actual_val = Green_actual_val;//传递真实值
//    pid->target_val = Red_target_val;
//	pid->err = pid->target_val - pid->actual_val;////当前误差=目标值-真实值
//	pid->err_sum += pid->err;//误差累计值 = 当前误差累计和
//	//使用PID控制 输出 = Kp*当前误差  +  Ki*误差累计值 + Kd*(当前误差-上次误差)
//	pid->actual_val = pid->Kp*pid->err + pid->Ki*pid->err_sum + pid->Kd*(pid->err - pid->err_last);
//	//保存上次误差: 这次误差赋值给上次误差
//	pid->err_last = pid->err;
//	 pid->actual_val+=pid->actual_val;
//	return pid->actual_val;
//}
int Spe_PID_output (int actual_val,int target_val)
{
	float PIDOUT;
    Spe_pid.Pv=actual_val;//传递真实值
    Spe_pid.Sv=target_val;
	Spe_pid.Ek=Spe_pid.Sv-Spe_pid.Pv;
    //printf("%.2f\r\n",Spe_pid.Ek);
	PIDOUT=Spe_pid.Kp*(Spe_pid.Ek-Spe_pid.Ek_1) + Spe_pid.Ki*Spe_pid.Ek + Spe_pid.Kd*(Spe_pid.Ek_1-Spe_pid.Ek)+Spe_pid.OUT0;
	Spe_pid.Ek_1=Spe_pid.Ek;
	Spe_pid.PIDOUT+=PIDOUT;
	Spe_pid.PIDOUT=(Spe_pid.PIDOUT<Spe_pid.lowlimit) ? Spe_pid.lowlimit:(Spe_pid.PIDOUT>Spe_pid.uplimit) ? Spe_pid.uplimit : Spe_pid.PIDOUT;
	return Spe_pid.PIDOUT;
}

int Loc_PID_output (int actual_val,int target_val)
{
	float PIDOUT;
    Loc_pid.Pv=actual_val;//传递真实值
    Loc_pid.Sv=target_val;
	Loc_pid.Ek=Loc_pid.Sv-Loc_pid.Pv;
    //printf("%.2f     ",Loc_pid.Ek);
	PIDOUT=Loc_pid.Kp*(Loc_pid.Ek-Loc_pid.Ek_1) + Loc_pid.Ki*Loc_pid.Ek + Loc_pid.Kd*(Loc_pid.Ek_1-Loc_pid.Ek)+Loc_pid.OUT0;
    //printf("%.2f    \r\n ",Loc_pid.Kd*(Loc_pid.Ek_1-Loc_pid.Ek));
	Loc_pid.Ek_1=Loc_pid.Ek;
	Loc_pid.PIDOUT+=PIDOUT;
	Loc_pid.PIDOUT=(Loc_pid.PIDOUT<Loc_pid.lowlimit) ? Loc_pid.lowlimit:(Loc_pid.PIDOUT>Loc_pid.uplimit) ? Loc_pid.uplimit : Loc_pid.PIDOUT;
	//printf("%.2f    ",Loc_pid.PIDOUT);
    return Loc_pid.PIDOUT;
}

