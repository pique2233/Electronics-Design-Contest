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
uint16_t page=0;//当前所处的页号，0为初始界面，1为第一个题目页面，2为第二个题目页面
uint16_t page0_column=0;//初始页面中的选项编号
uint16_t page1_column=0;//第一个题目页面中的选项编号
uint16_t page2_column=0;//第二个题目页面中的选项编号
*/


uint8_t oled_change(void)
{
if(key_flagA==1){//切换题目
		OLED_Clear();
		
		if(page==0){//在初始界面
			page0_column=(page0_column+1)%2;//切换选项
		}
		if(page==1){//在第一个题目页面
			page1_column=(page1_column+1)%6;//切换题目选项
		}
		else if(page==2){//在第二个题目页面
			page2_column=(page2_column+1)%3;//切换题目选项
		}
		else if(page==3){//在调试页面
			page3_column=(page3_column+1)%6;//切换调试选项
		}
		key_flagA=0;
	}
///////////////////////////////////////////////////////////////////////按键分界
	if(key_flagB==1){//切换页
		OLED_Clear();
		
		if(page==0){//在初始界面，根据page0_column数值进入对应题目页面
			if(page0_column==0){
				page=1;
			}
			else{
				page=2;
			}
			page1_column=0;//重置两页的题目编号
			page2_column=0;
		}
		else if(page==1){//在第一个题目页面
			page=2;
			page0_column=0;//重置初始页与第2页的题目编号
			page2_column=0;
		}
		else if(page==2){//在第二个题目页面     //改为数据页
			page=1;
			page0_column=0;//重置初始页与第1页的题目编号
			page1_column=0;
		}
		else if(page==3){//在调试页面
			debug_data++;
		}
		key_flagB=0;
	}

	if(key_flagC==1)
	{
		key_flagC=0;
		if(page==3){//在调试页面
		debug_data--;}
		
//	else if(page==2){//在第二个题目页面
//						switch (page2_column)
//            {
//            	
//            	default:
//            		break;
//            }
		else if(page==1){//在第一个题目页面
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





uint8_t page_start(void)   //开始页
{
	uint8_t string[20];
	
	if(page==0){//无翻页操作
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
			//OLED_Clear();//清屏
			sprintf((char *)string,"*");//   >
			OLED_ShowString(0,5,(uint8_t *)string,12);
			sprintf((char *)string," ");//   >
			OLED_ShowString(65,5,(uint8_t *)string,12);
		}
		else{
			//OLED_Clear();//清屏
			sprintf((char *)string,"*");//   >
			OLED_ShowString(65,5,(uint8_t *)string,12);
			sprintf((char *)string," ");//   >
			OLED_ShowString(5,5,(uint8_t *)string,12);
		}
	}
	else if(page==1){//标准 进入p1
		page_1();
	}
	else{//标准 进入p2
		page_2();
	}
	
	
	
	//printf("start");
	return 0;
}


uint8_t page_1(void)           //基本题
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
extern struct Point points[];  // 输入四个点的坐标
uint8_t page_2(void) //发挥题
{
	uint8_t string[20];
	
  sprintf((char *)string,"  %d  ",points[3].x);//显示6050数据
	OLED_ShowString(0,1,string,12);
	sprintf((char *)string,"  %d  ",points[3].y);//显示6050数据
	OLED_ShowString(50,1,string,12);
	sprintf((char *)string,"  %d  ",points[2].x);//显示6050数据
	OLED_ShowString(0,3,string,12);
	
	sprintf((char *)string,"  %d  ",points[2].y);//显示6050数据
	OLED_ShowString(50,3,string,12);
	sprintf((char *)string,"  %d  ",points[1].x);//显示6050数据
	OLED_ShowString(0,5,string,12);
	sprintf((char *)string,"  %d  ",points[1].y);//显示6050数据
	OLED_ShowString(50,5,string,12);
	sprintf((char *)string,"  %d  ",points[0].x);//显示6050数据
	OLED_ShowString(0,7,string,12);
	sprintf((char *)string,"  %d  ",points[0].y);//显示6050数据
	OLED_ShowString(50,7,string,12);
	return 0;
}

extern int move_debug,Xdebug,Ydebug;
uint8_t page_DEBUG(void)           //调试页
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

uint8_t page_1_2(void)          //基本要求第二题
{
	printf("11111111111111page_1_2");
	 key_flag=1;
	return 0;
}

uint8_t page_1_3(void)          //基本要求第三题
{
	printf("2222222222page_1_3");
	key_flag=2;
	return 0;
}

uint8_t page_1_4(void)          //基本要求第四题
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


