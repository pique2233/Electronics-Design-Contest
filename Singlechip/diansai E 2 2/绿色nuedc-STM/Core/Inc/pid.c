#include "pid.h"
#include <stdio.h>
#include "tim.h"

//#define TARGET_X 1250    // �������λ��X
//#define TARGET_Y 300    // �������λ��Y

//#define KP 1.01        // ����ϵ��
//#define KI 0.01        // ����ϵ��
//#define KD 0        // ΢��ϵ��
//ServoState gensui;
//ServoState servo1;  // ���״̬

//void PID_init()
//{
//    
//    gensui.currentX = 0;//��ǰ���λ��X
//    gensui.currentY = 0;
//    gensui.prevErrorX = 0;//��һ�ζ��λ��X�����
//    gensui.prevErrorY = 0;
//    gensui.sumErrorX = 0;
//    gensui.sumErrorY = 0;//���λ��Y������ۼ�
//}


//// ���¶��״̬
//void updateServoState(ServoState *gensui, float newX, float newY) {
//    gensui->prevErrorX = TARGET_X - newX;
//    gensui->prevErrorY = TARGET_Y - newY;
//    gensui->sumErrorX += gensui->prevErrorX;
//    gensui->sumErrorY += gensui->prevErrorY;
//    gensui->currentX = newX;
//    gensui->currentY = newY;
//}

//// ��ά�����̨ PID ���ƺ���
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

//    // ���������
//    float controlX = KP * errorX + KI * gensui->sumErrorX + KD * deltaErrorX;
//    float controlY = KP * errorY + KI * gensui->sumErrorY + KD * deltaErrorY;
//    printf("X:%.3f\r\n",controlX);
//    printf("Y:%.3f\r\n",controlY);
//    printf("\r\n");

//    // ִ�п��ƶ���
//    // ������Ը��ݾ���Ķ�����Ʒ�ʽ����ʵ��
//   __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, controlY);  //��ֱ PA6 
//   __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_4, controlX);  //ˮƽ PB11  

//    // ���¶��״̬
////    updateServoState(gensui, gensui->currentX + controlX, gensui->currentY + controlY);

//}

//tPid pidFollow_x;    //���������PID
//tPid pidFollow_y;

Loc_PID Loc_pid; //���PID�㷨����Ҫ������
Spe_PID Spe_pid;

extern uint8_t g_ucaUsart2ReceiveBuffer[20];//���洮�ڽ�����Ч���ݵ�����

void PID_Init()
{
    Loc_pid.Sv=g_ucaUsart2ReceiveBuffer[2];     //red_x�û��趨ֵ
	Loc_pid.Pv=g_ucaUsart2ReceiveBuffer[4];      //green_x���ֵ
	Loc_pid.OUT0 =00;      //PID����
	Loc_pid.Ek=0.0;       //��ǰ���ֵ    
	Loc_pid.Ek_1=0.0;     //��һ�����ֵ
	Loc_pid.Kp=0.25;//0.6;     //��������
	Loc_pid.Ki=0.006;//0.007;       //���ֳ���
	Loc_pid.Kd=-0.001;       //΢�ֳ���
	Loc_pid.uplimit=1000; //����ֵ
	Loc_pid.lowlimit=600;//����ֵ
	Loc_pid.PIDOUT=750;
    
    Spe_pid.Sv=g_ucaUsart2ReceiveBuffer[3];     //red_y�û��趨ֵ
	Spe_pid.Pv=g_ucaUsart2ReceiveBuffer[5];      //green_y���ֵ
	Spe_pid.OUT0 =0;      //PID����
	Spe_pid.Ek=0.0;       //��ǰ���ֵ
	Spe_pid.Ek_1=0.0;     //��һ�����ֵ
	Spe_pid.Ek_2=0.0;     //����һ�����ֵ
	Spe_pid.Kp=-0.2;     //��������
	Spe_pid.Ki=-0.006;//-0.007;      //���ֳ���
	Spe_pid.Kd=0.001;       //΢�ֳ���
	Spe_pid.uplimit=1250; //����ֵ
	Spe_pid.lowlimit=500;//����ֵ
	Spe_pid.PIDOUT=950;
    
//    pidFollow_x.actual_val=0.0;
//	pidFollow_x.target_val=0.0;//��������� Ŀ�����22.5cm
//	pidFollow_x.err=0.0;
//	pidFollow_x.err_last=0.0;
//	pidFollow_x.err_sum=0.0;
//	pidFollow_x.Kp=1.1;//����������Kp��Сͨ������PID����������ݣ�ȷ����Ŵ�С��Ȼ���ڵ���
//	pidFollow_x.Ki=0;//KiСһЩ
//	pidFollow_x.Kd=0;
//    
//    pidFollow_y.actual_val=0.0;
//	pidFollow_y.target_val=0.0;//��������� Ŀ�����22.5cm
//	pidFollow_y.err=0.0;
//	pidFollow_y.err_last=0.0;
//	pidFollow_y.err_sum=0.0;
//	pidFollow_y.Kp=1.1;//����������Kp��Сͨ������PID����������ݣ�ȷ����Ŵ�С��Ȼ���ڵ���
//	pidFollow_y.Ki=0;//KiСһЩ
//	pidFollow_y.Kd=0;   
    
}
//float PID_realize(tPid * pid,float Green_actual_val,float Red_target_val)
//{
    
//	pid->actual_val = Green_actual_val;//������ʵֵ
//    pid->target_val = Red_target_val;
//	pid->err = pid->target_val - pid->actual_val;////��ǰ���=Ŀ��ֵ-��ʵֵ
//	pid->err_sum += pid->err;//����ۼ�ֵ = ��ǰ����ۼƺ�
//	//ʹ��PID���� ��� = Kp*��ǰ���  +  Ki*����ۼ�ֵ + Kd*(��ǰ���-�ϴ����)
//	pid->actual_val = pid->Kp*pid->err + pid->Ki*pid->err_sum + pid->Kd*(pid->err - pid->err_last);
//	//�����ϴ����: �����ֵ���ϴ����
//	pid->err_last = pid->err;
//	 pid->actual_val+=pid->actual_val;
//	return pid->actual_val;
//}
int Spe_PID_output (int actual_val,int target_val)
{
	float PIDOUT;
    Spe_pid.Pv=actual_val;//������ʵֵ
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
    Loc_pid.Pv=actual_val;//������ʵֵ
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

