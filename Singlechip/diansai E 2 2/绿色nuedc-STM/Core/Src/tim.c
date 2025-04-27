/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    tim.c
  * @brief   This file provides code for the configuration
  *          of the TIM instances.
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
#include "tim.h"

/* USER CODE BEGIN 0 */
#include <math.h>
#include "stdio.h"
#include <stdlib.h>
/* USER CODE END 0 */

TIM_HandleTypeDef htim1;
TIM_HandleTypeDef htim2;
TIM_HandleTypeDef htim3;

/* TIM1 init function */
void MX_TIM1_Init(void)
{

  /* USER CODE BEGIN TIM1_Init 0 */

  /* USER CODE END TIM1_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};
  TIM_BreakDeadTimeConfigTypeDef sBreakDeadTimeConfig = {0};

  /* USER CODE BEGIN TIM1_Init 1 */

  /* USER CODE END TIM1_Init 1 */
  htim1.Instance = TIM1;
  htim1.Init.Prescaler = 144-1;
  htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim1.Init.Period = 10000-1;
  htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim1.Init.RepetitionCounter = 0;
  htim1.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
  if (HAL_TIM_Base_Init(&htim1) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim1, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_Init(&htim1) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim1, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 50;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCNPolarity = TIM_OCNPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  sConfigOC.OCIdleState = TIM_OCIDLESTATE_RESET;
  sConfigOC.OCNIdleState = TIM_OCNIDLESTATE_RESET;
  if (HAL_TIM_PWM_ConfigChannel(&htim1, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.Pulse = 0;
  if (HAL_TIM_PWM_ConfigChannel(&htim1, &sConfigOC, TIM_CHANNEL_4) != HAL_OK)
  {
    Error_Handler();
  }
  sBreakDeadTimeConfig.OffStateRunMode = TIM_OSSR_DISABLE;
  sBreakDeadTimeConfig.OffStateIDLEMode = TIM_OSSI_DISABLE;
  sBreakDeadTimeConfig.LockLevel = TIM_LOCKLEVEL_OFF;
  sBreakDeadTimeConfig.DeadTime = 0;
  sBreakDeadTimeConfig.BreakState = TIM_BREAK_DISABLE;
  sBreakDeadTimeConfig.BreakPolarity = TIM_BREAKPOLARITY_HIGH;
  sBreakDeadTimeConfig.AutomaticOutput = TIM_AUTOMATICOUTPUT_DISABLE;
  if (HAL_TIMEx_ConfigBreakDeadTime(&htim1, &sBreakDeadTimeConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM1_Init 2 */

  /* USER CODE END TIM1_Init 2 */
  HAL_TIM_MspPostInit(&htim1);

}
/* TIM2 init function */
void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 144-1;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 10000-1;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_4) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */
  HAL_TIM_MspPostInit(&htim2);

}
/* TIM3 init function */
void MX_TIM3_Init(void)
{

  /* USER CODE BEGIN TIM3_Init 0 */

  /* USER CODE END TIM3_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};

  /* USER CODE BEGIN TIM3_Init 1 */

  /* USER CODE END TIM3_Init 1 */
  htim3.Instance = TIM3;
  htim3.Init.Prescaler = 144-1;
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim3.Init.Period = 10000-1;
  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
  if (HAL_TIM_Base_Init(&htim3) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim3, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_Init(&htim3) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM3_Init 2 */

  /* USER CODE END TIM3_Init 2 */
  HAL_TIM_MspPostInit(&htim3);

}

void HAL_TIM_Base_MspInit(TIM_HandleTypeDef* tim_baseHandle)
{

  if(tim_baseHandle->Instance==TIM1)
  {
  /* USER CODE BEGIN TIM1_MspInit 0 */

  /* USER CODE END TIM1_MspInit 0 */
    /* TIM1 clock enable */
    __HAL_RCC_TIM1_CLK_ENABLE();
  /* USER CODE BEGIN TIM1_MspInit 1 */

  /* USER CODE END TIM1_MspInit 1 */
  }
  else if(tim_baseHandle->Instance==TIM2)
  {
  /* USER CODE BEGIN TIM2_MspInit 0 */

  /* USER CODE END TIM2_MspInit 0 */
    /* TIM2 clock enable */
    __HAL_RCC_TIM2_CLK_ENABLE();
  /* USER CODE BEGIN TIM2_MspInit 1 */

  /* USER CODE END TIM2_MspInit 1 */
  }
  else if(tim_baseHandle->Instance==TIM3)
  {
  /* USER CODE BEGIN TIM3_MspInit 0 */

  /* USER CODE END TIM3_MspInit 0 */
    /* TIM3 clock enable */
    __HAL_RCC_TIM3_CLK_ENABLE();

    /* TIM3 interrupt Init */
    HAL_NVIC_SetPriority(TIM3_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(TIM3_IRQn);
  /* USER CODE BEGIN TIM3_MspInit 1 */

  /* USER CODE END TIM3_MspInit 1 */
  }
}
void HAL_TIM_MspPostInit(TIM_HandleTypeDef* timHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(timHandle->Instance==TIM1)
  {
  /* USER CODE BEGIN TIM1_MspPostInit 0 */

  /* USER CODE END TIM1_MspPostInit 0 */
    __HAL_RCC_GPIOA_CLK_ENABLE();
    /**TIM1 GPIO Configuration
    PA8     ------> TIM1_CH1
    PA11     ------> TIM1_CH4
    */
    GPIO_InitStruct.Pin = GPIO_PIN_8|GPIO_PIN_11;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /* USER CODE BEGIN TIM1_MspPostInit 1 */

  /* USER CODE END TIM1_MspPostInit 1 */
  }
  else if(timHandle->Instance==TIM2)
  {
  /* USER CODE BEGIN TIM2_MspPostInit 0 */

  /* USER CODE END TIM2_MspPostInit 0 */

    __HAL_RCC_GPIOB_CLK_ENABLE();
    /**TIM2 GPIO Configuration
    PB11     ------> TIM2_CH4
    */
    GPIO_InitStruct.Pin = GPIO_PIN_11;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    __HAL_AFIO_REMAP_TIM2_PARTIAL_2();

  /* USER CODE BEGIN TIM2_MspPostInit 1 */

  /* USER CODE END TIM2_MspPostInit 1 */
  }
  else if(timHandle->Instance==TIM3)
  {
  /* USER CODE BEGIN TIM3_MspPostInit 0 */

  /* USER CODE END TIM3_MspPostInit 0 */

    __HAL_RCC_GPIOA_CLK_ENABLE();
    /**TIM3 GPIO Configuration
    PA6     ------> TIM3_CH1
    */
    GPIO_InitStruct.Pin = GPIO_PIN_6;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /* USER CODE BEGIN TIM3_MspPostInit 1 */

  /* USER CODE END TIM3_MspPostInit 1 */
  }

}

void HAL_TIM_Base_MspDeInit(TIM_HandleTypeDef* tim_baseHandle)
{

  if(tim_baseHandle->Instance==TIM1)
  {
  /* USER CODE BEGIN TIM1_MspDeInit 0 */

  /* USER CODE END TIM1_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_TIM1_CLK_DISABLE();
  /* USER CODE BEGIN TIM1_MspDeInit 1 */

  /* USER CODE END TIM1_MspDeInit 1 */
  }
  else if(tim_baseHandle->Instance==TIM2)
  {
  /* USER CODE BEGIN TIM2_MspDeInit 0 */

  /* USER CODE END TIM2_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_TIM2_CLK_DISABLE();
  /* USER CODE BEGIN TIM2_MspDeInit 1 */

  /* USER CODE END TIM2_MspDeInit 1 */
  }
  else if(tim_baseHandle->Instance==TIM3)
  {
  /* USER CODE BEGIN TIM3_MspDeInit 0 */

  /* USER CODE END TIM3_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_TIM3_CLK_DISABLE();

    /* TIM3 interrupt Deinit */
    HAL_NVIC_DisableIRQ(TIM3_IRQn);
  /* USER CODE BEGIN TIM3_MspDeInit 1 */

  /* USER CODE END TIM3_MspDeInit 1 */
  }
}

/* USER CODE BEGIN 1 */
void HAL_TIM_PWM_MspDeInit(TIM_HandleTypeDef* tim_pwmHandle)
{

  if(tim_pwmHandle->Instance==TIM1)
  {
  /* USER CODE BEGIN TIM1_MspDeInit 0 */

  /* USER CODE END TIM1_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_TIM1_CLK_DISABLE();
  /* USER CODE BEGIN TIM1_MspDeInit 1 */

  /* USER CODE END TIM1_MspDeInit 1 */
  }
}

/* USER CODE BEGIN 1 */



float pwm_set_red(double x,double y)
{
    double angle_shuiping;
    double angle_shuzhi;
       
    uint16_t pwm_shuiping=0;
    uint16_t pwm_shuzhi=0;
    
//    uint16_t SERVO_MIN_ANGLE=0;
//    uint16_t SERVO_MAX_ANGLE=0;
//    // 输入 x 和 y 坐标
//    printf("请输入 x 坐标：");
//    scanf("%lf", &x);
//    printf("请输入 y 坐标：");
//    scanf("%lf", &y);

    // 计算角度（弧度）
   angle_shuiping = atan2(x, 1000);
   angle_shuzhi= atan2(y, 1000);
    // 将弧度转换为角度
    angle_shuiping= angle_shuiping * 180 / 3.1415;
    angle_shuzhi= angle_shuzhi * 180 / 3.1415;
    
     
    pwm_shuiping=angle_shuiping*3.7037+770;
    pwm_shuzhi=angle_shuzhi*3.7037+740;
    
   __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_4, pwm_shuiping);  //水平
   __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, pwm_shuzhi);  //竖直
    // 输出角度
//    printf("坐标 (%d, %d) \r\n", pwm_shuzhi, pwm_shuiping);

//// 逐步增加舵机角度
//    for (float angle_sp = angle_shuiping; angle_shuiping_last <= angle_sp; angle_shuiping_last += 0.3f)
//    {

//     pwm_shuiping=angle_shuiping_last*3.7037+750;
//     __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_4, pwm_shuiping);
//      HAL_Delay(100);  // 等待一段时间，根据需要调整延迟时间
//    }
//    
//// 逐步增加舵机角度
//    for (float angle_sp = angle_shuiping; angle_shuiping_last > angle_sp; angle_shuiping_last -= 0.3f)
//    {

//     pwm_shuiping=angle_shuiping_last*3.7037+750;
//     __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_4, pwm_shuiping);
//      HAL_Delay(1000);  // 等待一段时间，根据需要调整延迟时间
//    }


return 0;

}
int absoluteValue(int num) 
{ 
if (num < 0) { return -num; } 
    else { return num; }
}

//x1 y1是上次坐标0    0.9
void slow_motion (double x1,double x2,double y1,double y2,int time){
  //  float slope, intercept;
    float x_can,y_can=0;
    x1 = (int)x1;
    x2 = (int)x2;
    y1 = (int)y1;
    y2 = (int)y2;

    if(x1 !=x2||y1!=y2){//原理来是5000
        x_can = absoluteValue(x1 - x2)/1000.0;//250.0;
        y_can = absoluteValue(y1 - y2)/1000.0;//250.0;
        //while(x1 !=x2||y1!=y2){ 
        for(int i=0;i<1000;i++){
                    if(x2 > x1){
                        x1+=x_can;
                    }
                    else if(x2 <x1 ){
                        x1-=x_can;
                    }
                    if(y2 > y1){
                        y1+=y_can;
                    }
                    else if(y2 < y1){
                        y1-=y_can;
                    }

            pwm_set_red(-x1,y1);
//                    printf("x1:%.3f,x2:%.3f,x_can:%.2f  \r",x1,x2,x_can);
//                    printf("y1:%.3f,y2:%.3f,y_can:%.2f\r\n",y1,y2,y_can);
//            for(int j=0;j<time;j++){
//                    __nop();
//               }
                    delay_us(time);
//                    HAL_Delay(time/100);
        }
                for(int i=0;i<200;i++){
                    if(x2 > x1){
                        x1+=x_can;
                    }
                    else if(x2 <x1 ){
                        x1-=x_can;
                    }
                    if(y2 > y1){
                        y1+=y_can;
                    }
                    else if(y2 < y1){
                        y1-=y_can;
                    }
                    delay_us(400);
}
//}
}
}

#define TIM_HANDLE &htim3 //定义这个是为了方便移植
 
void delay_us(uint16_t nus)
{
	__HAL_TIM_SET_COUNTER(TIM_HANDLE, 0); //把计数器的值设置为0
	__HAL_TIM_ENABLE(TIM_HANDLE); //开启计数
	while (__HAL_TIM_GET_COUNTER(TIM_HANDLE) < nus); //每计数一次，就是1us，直到计数器值等于我们需要的时间
	__HAL_TIM_DISABLE(TIM_HANDLE); //关闭计数
}

//void slow_motion (double x1,double x2,double y1,double y2,int time){
//  //  float slope, intercept;
//    float x_can,y_can=0;
//    x1 = (int)x1;
//    x2 = (int)x2;
//    y1 = (int)y1;
//    y2 = (int)y2;

//    if(x1 !=x2||y1!=y2){
//        x_can = absoluteValue(x1 - x2)/260.0;//250.0;
//        y_can = absoluteValue(y1 - y2)/260.0;//250.0;
//        //while(x1 !=x2||y1!=y2){ 
//        for(int i=0;i<260;i++){
//                    if(x2 > x1){
//                        x1+=x_can;
//                    }
//                    else if(x2 <x1 ){
//                        x1-=x_can;
//                    }
//                    if(y2 > y1){
//                        y1+=y_can;
//                    }
//                    else if(y2 < y1){
//                        y1-=y_can;
//                    }

//            pwm_set_red(-x1,y1);
//                    printf("x1:%.3f,x2:%.3f,x_can:%.2f  \r",x1,x2,x_can);
//                    printf("y1:%.3f,y2:%.3f,y_can:%.2f\r\n",y1,y2,y_can);
//            HAL_Delay(time);
//        }
//}
////}
//}



////x1 y1是上次坐标0    0.9
//void slow_motion (double x1,double x2,double y1,double y2,int time){
//    float slope, intercept;
//    x1 = (int)x1;
//    x2 = (int)x2;
//    y1 = (int)y1;
//    y2 = (int)y2;
//    // 计算斜率
//    if(x1 !=x2){
//    slope = (y2 - y1) / (x2 - x1);

//    // 计算截距
//    intercept = y1 - slope * x1;

//    // 输出直线方程
//    while(x1!=x2){       
//        if(x2 > x1){
//            x1+=1;
//        }
//        else if(x2 <x1 ){
//            x1-=1;
//        }
//        
////        if(y2 > y1){
////            y1+=1;
////        }
////        else if(y2 < y1){
////            y1-=1;
////        }

//    pwm_set_red(-x1,slope*x1 + intercept);
//    printf("x1:%.3f,x2:%.3f\r\n",x1,x2);
//    HAL_Delay(time);
//}
//}
//}

/*第三问*/

/*范围检测*/
extern uint8_t g_ucaUsart2ReceiveBuffer[20];//保存串口接收有效数据的数组

//#define SCREEN_WIDTH  1920  // 屏幕宽度（以像素为单位）
//#define SCREEN_HEIGHT 1080  // 屏幕高度（以像素为单位）
#define SPEED         10000     // 移动速度（以像素为单位）

double calculateDistance(int x1, int y1, int x2, int y2) {
    int dx = x1 - x2;
    int dy = y1 - y2;
    return sqrt((double)(dx * dx) + (double)(dy * dy));
}

void moveToPoint(int targetX, int targetY, int currentX, int currentY) {
    double distance = calculateDistance(targetX, targetY, currentX, currentY);
//    double ratio = SPEED / distance;
    int dx = targetX - currentX;
    int dy = targetY - currentY;
//    float bili =dy/dx;
    int redmoveSPEED_y=SPEED/dy;
    int redmoveSPEED_x=SPEED/dx;
    
    int redmove_y=+redmoveSPEED_y;
    int redmove_x=+redmoveSPEED_x;
//    currentX += (int)(dx * ratio);
//    currentY += (int)(dy * ratio);
    printf("redmove_x:%d\n redmove_y:%d\r\n",redmove_x,redmove_y);
   __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_4, 750+redmove_x);  //水平 PA11
   __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, 565+redmove_y);  //竖直 PA8

}

void xie_move(int pointAX,int pointAY,int pointBX,int pointBY,uint16_t time) 
    {
//    int pointAX = 100;      // 目标位置A的x坐标
//    int pointAY = 100;      // 目标位置A的y坐标
//    int pointBX = 500;      // 可移动点B的初始x坐标
//    int pointBY = 500;      // 可移动点B的初始y坐标

    if(calculateDistance(pointAX, pointAY, pointBX, pointBY) > 3.0)
        {
        moveToPoint(pointAX, pointAY, pointBX, pointBY);

        // 在此处添加代码以将点B绘制在屏幕上
        // 例如，使用图形库或绘制函数将点B显示在屏幕上的相应位置

        // 模拟延迟，以便观察移动效果
        // 此处可以根据需要自行调整延迟时间
       
            // 空循环
            delay_us(time);
       
    }

//    printf("Point B reached point A!\n");
//    return 0;
}



/* USER CODE END 1 */
