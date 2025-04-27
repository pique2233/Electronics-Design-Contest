/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

#include "stdio.h"
#include "oled.h"
#include "paixu.h"
#include "pid.h"
#include "oled_page.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
//uint8_t rx_data[1];
uint8_t g_ucUsart1ReceiveData; 


 uint8_t state = 0;
uint8_t g_ucaUsart2ReceiveBuffer[20];//���洮�ڽ�����Ч���ݵ�����
uint8_t g_ucUsart1ReceivCounter=0;//���ڽ��ռ���ֵ
uint8_t g_ucUsart1ReceiveCompletionFlag;//���ڶ�������ɱ�־λ 1:������� ���Խ��д��� 0:����δ��ɻ��߽�����

uint8_t key_flag=0;

uint16_t page=0;//��ǰ������ҳ�ţ�0Ϊ��ʼ���棬1Ϊ��һ����Ŀҳ�棬2Ϊ�ڶ�����Ŀҳ��
uint16_t page0_column=0;//��ʼҳ���е�ѡ����
uint16_t page1_column=0;//��һ����Ŀҳ���е�ѡ����
uint16_t page2_column=0;//�ڶ�����Ŀҳ���е�ѡ����
uint16_t page3_column=0;//����ҳ���е�ѡ����
uint8_t key_flagA,key_flagB,key_flagC,key_flagD;

int move_debug;


#define speed_move  100//100
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
//uint8_t string[20];
  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM1_Init();
  MX_USART1_UART_Init();
  MX_TIM3_Init();
  MX_USART3_UART_Init();
  /* USER CODE BEGIN 2 */
  
	OLED_Init(); //��ʼ��OLED
    OLED_Clear();//����
		
   HAL_UART_Receive_IT(&huart1, &g_ucUsart1ReceiveData, 1);//���ڽ����ж�
	
	
		//���
  HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_1);//������ʱ��1 ͨ��1 PWM���
  HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_4);//������ʱ��1 ͨ��4 PWM���
  HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_1);//������ʱ��1 ͨ��4 PWM���
   __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_4, 770);  //ˮƽ PA11 750
   __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, 740);  //��ֱ PA8  605
//    HAL_Delay(2000);
//slow_motion (0, 0, 0, 250,2);
		

/////////////////////////////////////////////////////////////////������



/////////////////////////////////////////////////////////////////������

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  { 
      
//shunshizhen_4paixv_change();

		if(key_flag==1)
      {
          
//          HAL_Delay(2000);
//      slow_motion (0, 0, 0, 235,100);
//      slow_motion (0, 260, 235, 235,100);    
//      slow_motion (260, 260, 235,0,100);
//      slow_motion (260, 260, 0,-255,100);
//      slow_motion (260, -260, -255, -255,100);
//      slow_motion (-260, -260, -255, 250,100);
//      slow_motion (-260, -260, 250, 250,100);
//      slow_motion (-260, 0, 250, 250,100);
//      slow_motion (0, 0, 250, 0,100);

          
//      slow_motion (0, 0, 0, -250,speed_move);
//      slow_motion (0, -250, -250, -250,speed_move);    
//      slow_motion (-250, -250, -250, 250,speed_move);
//      slow_motion (-250, 0, 250, 250,speed_move);
//      slow_motion (0, 250, 250, 250,speed_move);
//      slow_motion (250, 250, 250, -250,speed_move);
//      slow_motion (250, 0, -250, -250,speed_move);
//      slow_motion (0, 0, -250, 0,speed_move);
/*111*/
//      slow_motion (0, -250, 0, -250,speed_move);
//      slow_motion (-250, -250, -250, 250,speed_move);    
//      slow_motion (-250, 250, 250, 250,speed_move);
//      slow_motion (250, 250, 250, -250,speed_move);
//      slow_motion (250, -250, -250, -250,speed_move);
//      slow_motion (-250, 0, -250, 0,speed_move);
      
      slow_motion (0, 250, 0, 250,0);
      slow_motion (250, 250, 250, -250,speed_move);    
      slow_motion (250, -250, -250, -250,speed_move);
      slow_motion (-250, -250, -250, 240+move_debug,speed_move);//240+c
      slow_motion (-250, 250, 240+move_debug, 240+move_debug,speed_move);//240+c
      slow_motion (250, 0, 250, 0,speed_move);
      
      
//      slow_motion (250, 0, -250, -250,speed_move);
//      slow_motion (0, 0, -250, 0,speed_move);
//          
//          /*PC1 ��Ƭƽ������ɨ��*/
//      slow_motion (0, 0, 250, 0,100);
//      slow_motion (0, -270, 0, 0,100);    
//      slow_motion (-270, -270, 0, 500,100);
//      slow_motion (-270, 0, 500, 500,100);
//      slow_motion (0, 280, 500, 500,100);
//      slow_motion (280, 280, 500, 0,100);
//      slow_motion (280, 0, 0, 0,100);
//      slow_motion (0, 0, 0, 0,100);
          
//      slow_motion (0, -70, 0, 375,100); 
//          HAL_Delay(1000);          
//      slow_motion (-70,105 , 375, 370,100);
//          HAL_Delay(1000);   
//      slow_motion (105, 105, 370, 130,100);
//          HAL_Delay(1000);   
//      slow_motion (105, -70, 130, 130,100);
//          HAL_Delay(1000);   
//      slow_motion (-70, -70, 130, 375,100);
//          HAL_Delay(1000);   

      key_flag=0;      
      }
      
      /*PC15 ��Ƭƽ��������λ*/
        if(key_flag==2)
      {
      slow_motion (250, 0, 240, 0,0);
          
      key_flag=0;
       }
      shunshizhen_4paixv_change();
        if(key_flag==3)
      {
      shunshizhen_4paixv_change();
          change_pwmset();
      key_flag=0;
       }
      
//		
            
            
            
		if(g_ucUsart1ReceiveCompletionFlag == 1)
			{
			
////				sprintf((char *)string,"  %d  ",g_ucaUsart2ReceiveBuffer[2]-40);//��ʾ6050����
////				OLED_ShowString(0,1,string,12);
////				sprintf((char *)string,"  %d  ",g_ucaUsart2ReceiveBuffer[3]-40);//��ʾ6050����
////				OLED_ShowString(50,1,string,12);
////				sprintf((char *)string,"  %d  ",g_ucaUsart2ReceiveBuffer[4]-40);//��ʾ6050����
////				OLED_ShowString(0,3,string,12);
////				sprintf((char *)string,"  %d  ",g_ucaUsart2ReceiveBuffer[5]-40);//��ʾ6050����
////				OLED_ShowString(50,3,string,12);
////				sprintf((char *)string,"  %d  ",g_ucaUsart2ReceiveBuffer[6]-40);//��ʾ6050����
////				OLED_ShowString(0,5,string,12);
////				sprintf((char *)string,"  %d  ",g_ucaUsart2ReceiveBuffer[7]-40);//��ʾ6050����
////				OLED_ShowString(50,5,string,12);
////				sprintf((char *)string,"  %d  ",g_ucaUsart2ReceiveBuffer[8]-40);//��ʾ6050����
////				OLED_ShowString(0,7,string,12);
////				sprintf((char *)string,"  %d  ",g_ucaUsart2ReceiveBuffer[9]-40);//��ʾ6050����
////				OLED_ShowString(50,7,string,12);
//				sprintf((char *)string,"  %d  ",g_ucaUsart2ReceiveBuffer[10]);//��ʾ6050����
//				OLED_ShowString(0,9,string,12);
//				sprintf((char *)string,"  %d  ",g_ucaUsart2ReceiveBuffer[11]);//��ʾ6050����
//				OLED_ShowString(3,9,string,12);
				
				
				
				
				for(int i=0;i<20;i++) g_ucaUsart2ReceiveBuffer[i]=0x00;//�������
				g_ucUsart1ReceiveCompletionFlag = 0;//ʹ�����ݺ���Ϊ0
			}
		
		
		
/////////////////////////////////////////////////////////////////������ ����ɾ����Ӱ��ϵͳ		
		
HAL_GPIO_TogglePin(GPIOC,GPIO_PIN_13);
		

		oled_change();
		
		
/////////////////////////////////////////////////////////////////������
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
//////////////////////////////////////////////////////////////////////////////

/*�����жϻص�����*/
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
  if (huart == &huart1) 
  {
  
		//
		usartCamera_Receive_Data(g_ucUsart1ReceiveData);//ͨ�Ŵ�����
		
  }
	 HAL_UART_Receive_IT(&huart1, &g_ucUsart1ReceiveData, 1);
}






void usartCamera_Receive_Data(uint8_t data)
{
//	static uint8_t state = 0;
	if(state==0&&data==0xA5) //��һ���ǲ���֡ͷ0xA5
	{
		state=1;
		g_ucaUsart2ReceiveBuffer[g_ucUsart1ReceivCounter++]=data;
		HAL_UART_Receive_IT(&huart1,&g_ucUsart1ReceiveData,1);  //���ڶ���������
	}
	else if(state==1&&data==0xA6) //�ڶ����ǲ���֡ͷ0xA6
	{
		state=2;
		g_ucaUsart2ReceiveBuffer[g_ucUsart1ReceivCounter++]=data;
		HAL_UART_Receive_IT(&huart1,&g_ucUsart1ReceiveData,1);  //���ڶ���������		
	}
	else if(state==2)//Ȼ��ȷ����ͷ��0XA5 0XA6 �Ϳ�ʼ����
	{
		g_ucaUsart2ReceiveBuffer[g_ucUsart1ReceivCounter++]=data;
		if(g_ucUsart1ReceivCounter>14||data==0x5B) state=3;  //���մ���9�����߽��յ�֡β0X5B ����λ״̬��
		HAL_UART_Receive_IT(&huart1,&g_ucUsart1ReceiveData,1);  //���ڶ���������		
	}
	else if(state==3) //״̬��
	{
		if(g_ucaUsart2ReceiveBuffer[g_ucUsart1ReceivCounter-1] == 0x5B)  //���һ���ǲ���0x5B֡β
		{
			state = 0;//����Ϳ��Դ��������ˡ�������ǵ������������ñ�־λ�����ֵ
			//��������������ú�����תƫ��״̬
//			if(g_ucMode == 7)
//			{
				//1.���ÿ��� �����ұ� ���&&g_ucaUsart2ReceiveBuffer[4]==1
				
				/**
				 if(g_ucaUsart2ReceiveBuffer[6]==0&&g_ucaUsart2ReceiveBuffer[5]==0&&g_ucaUsart2ReceiveBuffer[3]==0&&g_ucaUsart2ReceiveBuffer[2]==0)
				 {g_cThisState=0;//ǰ��
				 g_lHW_State=00200;
				 }
				 if(g_ucaUsart2ReceiveBuffer[6]==0&&g_ucaUsart2ReceiveBuffer[5]==1&&g_ucaUsart2ReceiveBuffer[3]==0&&g_ucaUsart2ReceiveBuffer[2]==0)
				 {g_cThisState=-1;//Ӧ����ת
				 g_lHW_State=00210;
				 }
				 if(g_ucaUsart2ReceiveBuffer[6]==1&&g_ucaUsart2ReceiveBuffer[5]==0&&g_ucaUsart2ReceiveBuffer[3]==0&&g_ucaUsart2ReceiveBuffer[2]==0)
				 {g_cThisState=-2;//������ת
				 g_lHW_State=00201;
				 }
				 if(g_ucaUsart2ReceiveBuffer[6]==1&&g_ucaUsart2ReceiveBuffer[5]==1&&g_ucaUsart2ReceiveBuffer[3]==0&&g_ucaUsart2ReceiveBuffer[2]==0)
				 {g_cThisState=-3;//������ת
				 g_lHW_State=00211;
				 }
				 if(g_ucaUsart2ReceiveBuffer[6]==0&&g_ucaUsart2ReceiveBuffer[5]==0&&g_ucaUsart2ReceiveBuffer[3]==1&&g_ucaUsart2ReceiveBuffer[2]==0)
				 {g_cThisState=1;//Ӧ����ת
				 g_lHW_State=01200;
				 }
                 if(g_ucaUsart2ReceiveBuffer[6]==0&&g_ucaUsart2ReceiveBuffer[5]==0&&g_ucaUsart2ReceiveBuffer[3]==0&&g_ucaUsart2ReceiveBuffer[2]==1)
				 {g_cThisState=2;//������ת
				 g_lHW_State=10200;
				 }
                 if(g_ucaUsart2ReceiveBuffer[6]==0&&g_ucaUsart2ReceiveBuffer[5]==0&&g_ucaUsart2ReceiveBuffer[3]==1&&g_ucaUsart2ReceiveBuffer[2]==1)
				 {g_cThisState=3;//������ת
				 g_lHW_State=1;
				 }
				 //������Ǻ��� ����1 ����Ϊ��Ӧ���� ��ʾֹͣ���е�
				 if(g_ucaUsart2ReceiveBuffer[6]==1&&g_ucaUsart2ReceiveBuffer[5]==1&&g_ucaUsart2ReceiveBuffer[4]==1&&g_ucaUsart2ReceiveBuffer[3]==1&&g_ucaUsart2ReceiveBuffer[2]==1)g_lHW_State=11111;
				 
				 //����㶼û�е�ʱ����Ϊ�ߵ��˾�ͷ
				 if(g_ucaUsart2ReceiveBuffer[6]==0&&g_ucaUsart2ReceiveBuffer[5]==0&&g_ucaUsart2ReceiveBuffer[4]==0&&g_ucaUsart2ReceiveBuffer[3]==0&&g_ucaUsart2ReceiveBuffer[2]==0)g_lHW_State=0;
				 //ֻ���м��Ǻ���ʱ��
				 if(g_ucaUsart2ReceiveBuffer[6]==0&&g_ucaUsart2ReceiveBuffer[5]==0&&g_ucaUsart2ReceiveBuffer[4]==1&&g_ucaUsart2ReceiveBuffer[3]==0&&g_ucaUsart2ReceiveBuffer[2]==0)g_lHW_State=100;
				 
				 **/
				//2.Ȼ���������
//				for(int i=0;i<10;i++) g_ucaUsart2ReceiveBuffer[i]=0x00;//�������
				g_ucUsart1ReceiveCompletionFlag = 1;
				//3.Ȼ��ʼ���� 
				HAL_UART_Receive_IT(&huart1,&g_ucUsart1ReceiveData,1);  //���ڶ���������
//			}
		}
		else //����֡β˵��ͨ�Ŵ������¿�ʼ����
		{
			state=0;
			g_ucUsart1ReceivCounter =0;
			//for(int i=0;i<10;i++) g_ucaUsart2ReceiveBuffer[i]=0x00;//�������
			g_ucUsart1ReceiveCompletionFlag = 0;
			HAL_UART_Receive_IT(&huart1,&g_ucUsart1ReceiveData,1);  //���ڶ���������
		}
	}
	else
	{	//�����쳣���
		state=0;
		g_ucUsart1ReceivCounter =0;
		//for(int i=0;i<10;i++) g_ucaUsart2ReceiveBuffer[i]=0x00;//�������
		g_ucUsart1ReceiveCompletionFlag = 0;
		HAL_UART_Receive_IT(&huart1,&g_ucUsart1ReceiveData,1);  //���ڶ���������
	}
}











/*PC15 ��Ƭƽ����*/
/*ɨ�����*/
//void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
//{

//if(GPIO_Pin == KEY2_Pin){//�ж�һ���Ǹ����Ŵ����ж�
////�����д�����жϺ�Ҫִ�еĳ���
//	
//	  slow_motion (0, -250, 0, 0,1);
//      slow_motion (-250, -250, 0, 500,1);
//      slow_motion (-250, 250, 500, 500,1);
//      slow_motion (250, 250, 500, 0,1);
//      slow_motion (250, 0, 0, 0,1);
////	printf("key");
//	
//HAL_GPIO_TogglePin(GPIOC,GPIO_PIN_13);//�л�LED GPIO״̬
//}
//}







/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
