#ifndef _PID_
#define _PID_

//#include "led.h"
//#define AIN2   PBout(12)
//#define AIN1   PBout(14)
typedef struct
{
 float Sv;//�û��趨ֵ
 float Pv;//����ֵ
 
 float Kp,Ki,Kd;
 float Ek;  //����ƫ��
 float Ek_1;//�ϴ�ƫ��
 float Ek_2; 
	
 float OUT0;

 float PIDOUT;
	
 float  lowlimit;
 float  uplimit;
	
}Spe_PID;
typedef struct
{
 float Sv;//�û��趨ֵ
 float Pv;//����ֵ
 
 float Kp,Ki,Kd;
 float Ek;  //����ƫ��
 float Ek_1;//�ϴ�ƫ��
 float Ek_2; 
 float OUT0;

 float PIDOUT;
	
 float  lowlimit;
 float  uplimit;
	
}Loc_PID;
typedef struct
{
 float Sv;//�û��趨ֵĿ��
 float Pv;//����ֵ
 
 float Kp,Ki,Kd;
 float Ek;  //����ƫ��
 float Ek_1;//�ϴ�ƫ��
	
 float OUT0;

 float PIDOUT;
	
 float  lowlimit;
 float  uplimit;
	
}Ele_PID;

extern Spe_PID Spe_pid; //���PID�㷨����Ҫ������
extern Loc_PID Loc_pid;

void Spe_PID_Init(void); //pid���ݳ�ʼ��
void Loc_PID_Init(void); 

int Loc_PID_output (int MuBiao_val,int JianCe_val);
int Spe_PID_output (int MuBiao_val,int JianCe_val);


float myabs(float a);
//float Set_Pwm(float moto1);
#endif



