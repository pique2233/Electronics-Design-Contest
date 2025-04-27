#ifndef __PID_H
#define __PID_H

//typedef struct {
//    float currentX;    // ��ǰ���λ��X
//    float currentY;    // ��ǰ���λ��Y
//    float prevErrorX;  // ��һ�ζ��λ��X�����
//    float prevErrorY;  // ��һ�ζ��λ��Y�����
//    float sumErrorX;   // ���λ��X������ۼ�
//    float sumErrorY;   // ���λ��Y������ۼ�
//} ServoState;


//void updateServoState(ServoState *state1, float newX, float newY);
//void pidControl(ServoState *gensui, float newX, float newY);
//void PID_init();

//typedef struct 
//{
//	float target_val;//Ŀ��ֵ
//	float actual_val;//ʵ��ֵ
//	float err;//��ǰƫ��
//	float err_last;//�ϴ�ƫ��
//	float err_sum;//����ۼ�ֵ
//	float Kp,Ki,Kd;//���������֣�΢��ϵ��
//	
//} tPid;

//void PID_init(void);
//float PID_realize(tPid * pid,float Green_actual_val,float Red_target_val);


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

extern Spe_PID Spe_pid; //���PID�㷨����Ҫ������
extern Loc_PID Loc_pid;

void PID_Init(void); //pid���ݳ�ʼ��

int Loc_PID_output (int actual_val,int target_val);
int Spe_PID_output (int actual_val,int target_val);

#endif
