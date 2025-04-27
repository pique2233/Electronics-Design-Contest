#include "pid.h"

Loc_PID Loc_pid; //存放PID算法所需要的数据
Spe_PID Spe_pid;
Ele_PID Ele_pid;
//float Sv;//用户设定值
// float Pv;//采样值
// 
void Loc_PID_Init()
{
	Loc_pid.Sv=0;     //用户设定值
	Loc_pid.Pv=00.0;      //检测值
	Loc_pid.OUT0 =00;      //PID常数
	Loc_pid.Ek=0.0;       //当前误差值
	Loc_pid.Ek_1=0.0;     //上一个误差值
	Loc_pid.Kp=1.3;     //比例常数
	Loc_pid.Ki=0.03;       //积分常数
	Loc_pid.Kd=0;       //微分常数
	Loc_pid.uplimit=1250; //上限值
	Loc_pid.lowlimit=250;//下限值
	Loc_pid.PIDOUT=750;
}
void Spe_PID_Init()
{
	Spe_pid.Sv=0;     //用户设定值
	Spe_pid.Pv=00.0;      //检测值
	Spe_pid.OUT0 =0;      //PID常数
	Spe_pid.Ek=0.0;       //当前误差值
	Spe_pid.Ek_1=0.0;     //上一个误差值
	Spe_pid.Ek_2=0.0;     //上上一个误差值
	Spe_pid.Kp=1.1;     //比例常数
	Spe_pid.Ki=0.02;       //积分常数
	Spe_pid.Kd=0.00000;       //微分常数
	Spe_pid.uplimit=1250; //上限值
	Spe_pid.lowlimit=250;//下限值
	Spe_pid.PIDOUT=565;
}
//float Set_Pwm(float moto1)
//{
//	float OUT;
//	if(moto1>0)			AIN2=0,			AIN1=1;
//	else 	          AIN2=1,			AIN1=0;
//	OUT=myabs(moto1);
//	return OUT;
//}
//绝对值函数
float myabs(float a)
{ 		   
	  int temp;
		if(a<0)  temp=-a;  
	  else temp=a;
	  return temp;
}

int Spe_PID_output (int MuBiao_val,int JianCe_val)
{
	float PIDOUT;
    Spe_pid.Sv=MuBiao_val;
    Spe_pid.Pv=JianCe_val;
	Spe_pid.Ek=Spe_pid.Sv-Spe_pid.Pv;
	PIDOUT=Spe_pid.Kp*(Spe_pid.Ek-Spe_pid.Ek_1) + Spe_pid.Ki*Spe_pid.Ek + Spe_pid.Kd*(Spe_pid.Ek_2*Spe_pid.Ek_1+Spe_pid.Ek_2)+Spe_pid.OUT0;
	Spe_pid.Ek_2=Spe_pid.Ek_1;
	Spe_pid.Ek_1=Spe_pid.Ek;
	Spe_pid.PIDOUT+=PIDOUT;
	Spe_pid.PIDOUT=(Spe_pid.PIDOUT<Spe_pid.lowlimit) ? Spe_pid.lowlimit:(Spe_pid.PIDOUT>Spe_pid.uplimit) ? Spe_pid.uplimit : Spe_pid.PIDOUT;
	return Spe_pid.PIDOUT;
}

int Loc_PID_output (int MuBiao_val,int JianCe_val)
{
	float PIDOUT;
    Loc_pid.Sv=MuBiao_val;
    Loc_pid.Pv=JianCe_val;
	Loc_pid.Ek=Loc_pid.Sv-Loc_pid.Pv;
	PIDOUT=Loc_pid.Kp*(Loc_pid.Ek-Loc_pid.Ek_1) + Loc_pid.Ki*Loc_pid.Ek + Loc_pid.Kd*(Loc_pid.Ek_2*Loc_pid.Ek_1+Loc_pid.Ek_2)+Loc_pid.OUT0;
	Loc_pid.Ek_2=Loc_pid.Ek_1;
	Loc_pid.Ek_1=Loc_pid.Ek;
	Loc_pid.PIDOUT+=PIDOUT;
	Loc_pid.PIDOUT=(Loc_pid.PIDOUT<Loc_pid.lowlimit) ? Loc_pid.lowlimit:(Loc_pid.PIDOUT>Loc_pid.uplimit) ? Loc_pid.uplimit : Loc_pid.PIDOUT;
	return Loc_pid.PIDOUT;
}


