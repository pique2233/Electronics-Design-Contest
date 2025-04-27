#include "oled.h"
#include "main.h" 
#include "oled_page.h"
#include "stdio.h"
#include "paixu.h"

extern uint8_t page,page0_column,page1_column,page2_column,page3_column;
extern uint8_t key_flagA,key_flagB,key_flagC,key_flagD;
uint8_t debug_ctrl_add,debug_ctrl_minus;
int debug_data=0;
/*
uint16_t page=0;//��ǰ������ҳ�ţ�0Ϊ��ʼ���棬1Ϊ��һ����Ŀҳ�棬2Ϊ�ڶ�����Ŀҳ��
uint16_t page0_column=0;//��ʼҳ���е�ѡ����
uint16_t page1_column=0;//��һ����Ŀҳ���е�ѡ����
uint16_t page2_column=0;//�ڶ�����Ŀҳ���е�ѡ����
*/


uint8_t oled_change(void)
{
if(key_flagA==1){//�л���Ŀ
		OLED_Clear();
		
		if(page==0){//�ڳ�ʼ����
			page0_column=(page0_column+1)%2;//�л�ѡ��
		}
		if(page==1){//�ڵ�һ����Ŀҳ��
			page1_column=(page1_column+1)%6;//�л���Ŀѡ��
		}
		else if(page==2){//�ڵڶ�����Ŀҳ��
			page2_column=(page2_column+1)%3;//�л���Ŀѡ��
		}
		else if(page==3){//�ڵ���ҳ��
			page3_column=(page3_column+1)%6;//�л�����ѡ��
		}
		key_flagA=0;
	}
///////////////////////////////////////////////////////////////////////�����ֽ�
	if(key_flagB==1){//�л�ҳ
		OLED_Clear();
		
		if(page==0){//�ڳ�ʼ���棬����page0_column��ֵ�����Ӧ��Ŀҳ��
			if(page0_column==0){
				page=1;
			}
			else{
				page=2;
			}
			page1_column=0;//������ҳ����Ŀ���
			page2_column=0;
		}
		else if(page==1){//�ڵ�һ����Ŀҳ��
			page=2;
			page0_column=0;//���ó�ʼҳ���2ҳ����Ŀ���
			page2_column=0;
		}
		else if(page==2){//�ڵڶ�����Ŀҳ��     //��Ϊ����ҳ
			page=1;
			page0_column=0;//���ó�ʼҳ���1ҳ����Ŀ���
			page1_column=0;
		}
		else if(page==3){//�ڵ���ҳ��
			debug_data++;
		}
		key_flagB=0;
	}

	if(key_flagC==1)
	{
		key_flagC=0;
		if(page==3){//�ڵ���ҳ��
		debug_data--;}
		
//	else if(page==2){//�ڵڶ�����Ŀҳ��
//						switch (page2_column)
//            {
//            	
//            	default:
//            		break;
//            }
		else if(page==1){//�ڵ�һ����Ŀҳ��
						switch (page1_column)
            {
            	case 0:{page_1_2();break;}
            	case 1:{page_1_3();break;}
							case 2:{page_1_4();break;}
							case 3:{page_2_1();break;}
            	case 4:{page_2_2();break;}
							case 5:{page_2_3();break;}
            	default:
            		break;
            }
		}
	
}
	
	if(key_flagD==1||page==3)
	{
		//OLED_Clear();
		page=3;
		page_DEBUG(); 
	//	key_flagD=0;
		key_flagD=0;
	
	}else page_start();

	return 0;
}





uint8_t page_start(void)   //��ʼҳ
{
	uint8_t string[20];
	
	if(page==0){//�޷�ҳ����
		OLED_ShowCHinese(0,0,0);//
		OLED_ShowCHinese(18,0,1);//
		OLED_ShowCHinese(36,0,2);//
		OLED_ShowCHinese(54,0,3);//
		OLED_ShowCHinese(72,0,4);//
		OLED_ShowCHinese(90,0,5);//
		OLED_ShowCHinese(108,0,6);//
		OLED_ShowCHinese(9,2,7);//
		OLED_ShowCHinese(27,2,8);//
		OLED_ShowCHinese(45,2,9);//
		OLED_ShowCHinese(63,2,10);//
		OLED_ShowCHinese(81,2,11);//
		OLED_ShowCHinese(99,2,12);
		OLED_ShowCHinese(9,5,13);
		OLED_ShowCHinese(27,5,14);
		OLED_ShowCHinese(45,5,15);
		OLED_ShowCHinese(72,5,16);
		OLED_ShowCHinese(90,5,17);
		OLED_ShowCHinese(108,5,18);
		
		if(page0_column==0){
			//OLED_Clear();//����
			sprintf((char *)string,"*");//   >
			OLED_ShowString(0,5,(uint8_t *)string,12);
			sprintf((char *)string," ");//   >
			OLED_ShowString(65,5,(uint8_t *)string,12);
		}
		else{
			//OLED_Clear();//����
			sprintf((char *)string,"*");//   >
			OLED_ShowString(65,5,(uint8_t *)string,12);
			sprintf((char *)string," ");//   >
			OLED_ShowString(5,5,(uint8_t *)string,12);
		}
	}
	else if(page==1){//��׼ ����p1
		page_1();
	}
	else{//��׼ ����p2
		page_2();
	}
	
	
	
	//printf("start");
	return 0;
}


uint8_t page_1(void)           //������
{
	uint8_t string[20];
	
	sprintf((char *)string,"1question 2");//   >
	OLED_ShowString(5,0,(uint8_t *)string,12);
	
	sprintf((char *)string,"1question 3");//   >
	OLED_ShowString(5,1,(uint8_t *)string,12);
	
	sprintf((char *)string,"1question 4");//   >
	OLED_ShowString(5,2,(uint8_t *)string,12);

	
	sprintf((char *)string,"2question 1");//   >
	OLED_ShowString(5,3,(uint8_t *)string,12);
	
	sprintf((char *)string,"2question 2");//   >
	OLED_ShowString(5,4,(uint8_t *)string,12);
	
	sprintf((char *)string,"2question 3");//   >
	OLED_ShowString(5,5,(uint8_t *)string,12);
	
	
	
	
	if(page1_column==0){
		sprintf((char *)string,"*");//   >
		OLED_ShowString(0,0,(uint8_t *)string,12);
		sprintf((char *)string," ");//   >
		OLED_ShowString(0,1,(uint8_t *)string,12);
		sprintf((char *)string," ");//   >
		OLED_ShowString(0,2,(uint8_t *)string,12);
		sprintf((char *)string," ");//   >
		OLED_ShowString(0,3,(uint8_t *)string,12);
		sprintf((char *)string," ");//   >
		OLED_ShowString(0,4,(uint8_t *)string,12);
		sprintf((char *)string," ");//   >
		OLED_ShowString(0,5,(uint8_t *)string,12);	
		
		
	}
	else if(page1_column==1){
		sprintf((char *)string," ");//   >
		OLED_ShowString(0,0,(uint8_t *)string,12);
		sprintf((char *)string,"*");//   >
		OLED_ShowString(0,1,(uint8_t *)string,12);
		sprintf((char *)string," ");//   >
		OLED_ShowString(0,2,(uint8_t *)string,12);
		sprintf((char *)string," ");//   >
		OLED_ShowString(0,3,(uint8_t *)string,12);
		sprintf((char *)string," ");//   >
		OLED_ShowString(0,4,(uint8_t *)string,12);
		sprintf((char *)string," ");//   >
		OLED_ShowString(0,5,(uint8_t *)string,12);	
		
	}

	if(page1_column==2){
		sprintf((char *)string," ");//   >
		OLED_ShowString(0,0,(uint8_t *)string,12);
		sprintf((char *)string," ");//   >
		OLED_ShowString(0,1,(uint8_t *)string,12);
		sprintf((char *)string,"*");//   >
		OLED_ShowString(0,2,(uint8_t *)string,12);
		sprintf((char *)string," ");//   >
		OLED_ShowString(0,3,(uint8_t *)string,12);
		sprintf((char *)string," ");//   >
		OLED_ShowString(0,4,(uint8_t *)string,12);
		sprintf((char *)string," ");//   >
		OLED_ShowString(0,5,(uint8_t *)string,12);	
	}
	
	if(page1_column==3){
		sprintf((char *)string," ");//   >
		OLED_ShowString(0,0,(uint8_t *)string,12);
		sprintf((char *)string," ");//   >
		OLED_ShowString(0,1,(uint8_t *)string,12);
		sprintf((char *)string," ");//   >
		OLED_ShowString(0,2,(uint8_t *)string,12);
		sprintf((char *)string,"*");//   >
		OLED_ShowString(0,3,(uint8_t *)string,12);
		sprintf((char *)string," ");//   >
		OLED_ShowString(0,4,(uint8_t *)string,12);
		sprintf((char *)string," ");//   >
		OLED_ShowString(0,5,(uint8_t *)string,12);	
	}
	
	if(page1_column==4){
		sprintf((char *)string," ");//   >
		OLED_ShowString(0,0,(uint8_t *)string,12);
		sprintf((char *)string," ");//   >
		OLED_ShowString(0,1,(uint8_t *)string,12);
		sprintf((char *)string," ");//   >
		OLED_ShowString(0,2,(uint8_t *)string,12);
		sprintf((char *)string," ");//   >
		OLED_ShowString(0,3,(uint8_t *)string,12);
		sprintf((char *)string,"*");//   >
		OLED_ShowString(0,4,(uint8_t *)string,12);
		sprintf((char *)string," ");//   >
		OLED_ShowString(0,5,(uint8_t *)string,12);	
	}
	
	if(page1_column==5){
		sprintf((char *)string," ");//   >
		OLED_ShowString(0,0,(uint8_t *)string,12);
		sprintf((char *)string," ");//   >
		OLED_ShowString(0,1,(uint8_t *)string,12);
		sprintf((char *)string," ");//   >
		OLED_ShowString(0,2,(uint8_t *)string,12);
		sprintf((char *)string," ");//   >
		OLED_ShowString(0,3,(uint8_t *)string,12);
		sprintf((char *)string," ");//   >
		OLED_ShowString(0,4,(uint8_t *)string,12);
		sprintf((char *)string,"*");//   >
		OLED_ShowString(0,5,(uint8_t *)string,12);	
	}
	
	
	//printf("page_1");
	return 0;
}

struct Point {
    int x;
    int y;
};
extern struct Point points[];  // �����ĸ��������
uint8_t page_2(void) //������
{
	uint8_t string[20];
	
  sprintf((char *)string,"  %d  ",points[3].x);//��ʾ6050����
	OLED_ShowString(0,1,string,12);
	sprintf((char *)string,"  %d  ",points[3].y);//��ʾ6050����
	OLED_ShowString(50,1,string,12);
	sprintf((char *)string,"  %d  ",points[2].x);//��ʾ6050����
	OLED_ShowString(0,3,string,12);
	
	sprintf((char *)string,"  %d  ",points[2].y);//��ʾ6050����
	OLED_ShowString(50,3,string,12);
	sprintf((char *)string,"  %d  ",points[1].x);//��ʾ6050����
	OLED_ShowString(0,5,string,12);
	sprintf((char *)string,"  %d  ",points[1].y);//��ʾ6050����
	OLED_ShowString(50,5,string,12);
	sprintf((char *)string,"  %d  ",points[0].x);//��ʾ6050����
	OLED_ShowString(0,7,string,12);
	sprintf((char *)string,"  %d  ",points[0].y);//��ʾ6050����
	OLED_ShowString(50,7,string,12);
	return 0;
}

extern int move_debug,Xdebug,Ydebug;
uint8_t page_DEBUG(void)           //����ҳ
{
		uint8_t string[20];
	
	sprintf((char *)string,"move_debug %d",move_debug);//   >
	OLED_ShowString(5,0,(uint8_t *)string,12);
	
	sprintf((char *)string,"Xdebug %d",Xdebug);//   >
	OLED_ShowString(5,1,(uint8_t *)string,12);
	
	sprintf((char *)string,"Ydebug %d",Ydebug);//   >
	OLED_ShowString(5,2,(uint8_t *)string,12);
	
	sprintf((char *)string,"debug_data %d",debug_data);//   >
	OLED_ShowString(5,3,(uint8_t *)string,12);
	
	sprintf((char *)string,"debug_data %d",debug_data);//   >
	OLED_ShowString(5,4,(uint8_t *)string,12);
	sprintf((char *)string,"EXTI");//   >
	OLED_ShowString(5,7,(uint8_t *)string,12);
	
	
	
	
	if(page3_column==0){
		sprintf((char *)string,"*");//   >
		OLED_ShowString(0,0,(uint8_t *)string,12);
		sprintf((char *)string," ");//   >
		OLED_ShowString(0,1,(uint8_t *)string,12);
		sprintf((char *)string," ");//   >
		OLED_ShowString(0,2,(uint8_t *)string,12);
		sprintf((char *)string," ");//   >
		OLED_ShowString(0,3,(uint8_t *)string,12);
		sprintf((char *)string," ");//   >
		OLED_ShowString(0,4,(uint8_t *)string,12);
		move_debug=debug_data;
	}
	else if(page3_column==1){
		sprintf((char *)string," ");//   >
		OLED_ShowString(0,0,(uint8_t *)string,12);
		sprintf((char *)string,"*");//   >
		OLED_ShowString(0,1,(uint8_t *)string,12);
		sprintf((char *)string," ");//   >
		OLED_ShowString(0,2,(uint8_t *)string,12);
		sprintf((char *)string," ");//   >
		OLED_ShowString(0,3,(uint8_t *)string,12);
		sprintf((char *)string," ");//   >
		OLED_ShowString(0,4,(uint8_t *)string,12);
		Xdebug=debug_data;
	}

	if(page3_column==2){
		sprintf((char *)string," ");//   >
		OLED_ShowString(0,0,(uint8_t *)string,12);
		sprintf((char *)string," ");//   >
		OLED_ShowString(0,1,(uint8_t *)string,12);
		sprintf((char *)string,"*");//   >
		OLED_ShowString(0,2,(uint8_t *)string,12);
		sprintf((char *)string," ");//   >
		OLED_ShowString(0,3,(uint8_t *)string,12);
		sprintf((char *)string," ");//   >
		OLED_ShowString(0,4,(uint8_t *)string,12);
		Ydebug=debug_data;
	}
	
	if(page3_column==3){
		sprintf((char *)string," ");//   >
		OLED_ShowString(0,0,(uint8_t *)string,12);
		sprintf((char *)string," ");//   >
		OLED_ShowString(0,1,(uint8_t *)string,12);
		sprintf((char *)string," ");//   >
		OLED_ShowString(0,2,(uint8_t *)string,12);
		sprintf((char *)string,"*");//   >
		OLED_ShowString(0,3,(uint8_t *)string,12);
		sprintf((char *)string," ");//   >
		OLED_ShowString(0,4,(uint8_t *)string,12);
		debug_data=debug_data;
	}
	if(page3_column==4){
		sprintf((char *)string," ");//   >
		OLED_ShowString(0,0,(uint8_t *)string,12);
		sprintf((char *)string," ");//   >
		OLED_ShowString(0,1,(uint8_t *)string,12);
		sprintf((char *)string," ");//   >
		OLED_ShowString(0,2,(uint8_t *)string,12);
		sprintf((char *)string," ");//   >
		OLED_ShowString(0,3,(uint8_t *)string,12);
		sprintf((char *)string,"*");//   >
		OLED_ShowString(0,4,(uint8_t *)string,12);
		debug_data=debug_data;
	}
	
	if(page3_column==5)
	{key_flagD=0;page=0;page3_column=0;}
	
	return 0;
	
	
	
	
	
	
}

extern uint8_t key_flag;

uint8_t page_1_2(void)          //����Ҫ��ڶ���
{
	printf("11111111111111page_1_2");
	 key_flag=1;
	return 0;
}

uint8_t page_1_3(void)          //����Ҫ�������
{
	printf("2222222222page_1_3");
	key_flag=2;
	return 0;
}

uint8_t page_1_4(void)          //����Ҫ�������
{
	printf("333333333333333333page_1_4");
	key_flag=3;
	return 0;
}

uint8_t page_2_1(void)	
{	
	printf("44444444page_2_1");
	key_flag=4;
	return 0;
}

uint8_t page_2_2(void)
{
	printf("555555555555page_2_2");
	return 0;
}

uint8_t page_2_3(void)
{
	printf("666666666666666page_2_3");
	return 0;
}	


