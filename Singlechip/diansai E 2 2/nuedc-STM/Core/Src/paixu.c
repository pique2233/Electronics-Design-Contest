#include "paixu.h"
#include "main.h"
#include "stdio.h"
#include "tim.h"
#include "oled.h"



uint8_t string[20];
/*4点顺时针排序*/
struct Point {
    int x;
    int y;
};
struct NEW_points {
    int x;
    int y;
};
struct Point points[4];  // 输入四个点的坐标

// 计算两点间距离的平方
int calculateDistanceSquare(struct Point p1, struct Point p2) {
    int dx = p1.x - p2.x;
    int dy = p1.y - p2.y;
    return dx * dx + dy * dy;
}

// 判断三个点的方向，返回正数表示顺时针，负数表示逆时针，0表示共线
int getOrientation(struct Point p1, struct Point p2, struct Point p3) {
    return (p2.y - p1.y) * (p3.x - p2.x) - (p2.x - p1.x) * (p3.y - p2.y);
}

// 比较两个点到原点的距离，用于排序
int compareDistance(const void* a, const void* b) {
    struct Point p1 = *(struct Point*)a;
    struct Point p2 = *(struct Point*)b;
    int distance1 = p1.x * p1.x + p1.y * p1.y;
    int distance2 = p2.x * p2.x + p2.y * p2.y;
    return distance1 - distance2;
}

// 对四个点按照顺时针排序，并将最近原点的点放在第一个位置
void sortPointsClockwise(struct Point* points) {
    // 找到距离原点最近的点
    int minDistanceIndex = 0;
    for (int i = 1; i < 4; i++) {
        if (calculateDistanceSquare(points[i], points[minDistanceIndex]) < calculateDistanceSquare(points[minDistanceIndex], points[minDistanceIndex])) {
            minDistanceIndex = i;
        }
    }

    // 将最近原点的点调整到第一个位置
    struct Point temp = points[0];
    points[0] = points[minDistanceIndex];
    points[minDistanceIndex] = temp;

    // 使用插入排序按照顺时针排序剩下的三个点
    for (int i = 2; i < 4; i++) {
        struct Point key = points[i];
        int j = i - 1;
        while (j >= 1 && getOrientation(points[0], points[j], key) > 0) {
            points[j + 1] = points[j];
            j--;
        }
        points[j + 1] = key;
    }
}

int Xdebug,Ydebug;
extern uint8_t g_ucaUsart2ReceiveBuffer[20];//保存串口接收有效数据的数组
struct NEW_points NEW_points[4];  // 转化后输出坐标
int shunshizhen_4paixv_change(void) 
    {
   

//    printf("Enter the coordinates of four points:\n");
//    for (int i = 0; i < 4; i++) {
//        printf("Point %d: ", i + 1);
//        scanf("%d %d", &points[i].x, &points[i].y);
        points[0].x=g_ucaUsart2ReceiveBuffer[2]-44.5+Xdebug;
        points[0].y=g_ucaUsart2ReceiveBuffer[3]-47+Ydebug;
        
        points[1].x=g_ucaUsart2ReceiveBuffer[4]-44.5+Xdebug;
        points[1].y=g_ucaUsart2ReceiveBuffer[5]-47+Ydebug;
        
        points[2].x=g_ucaUsart2ReceiveBuffer[6]-44.5+Xdebug;
        points[2].y=g_ucaUsart2ReceiveBuffer[7]-47+Ydebug;
        
        points[3].x=g_ucaUsart2ReceiveBuffer[8]-44.5+Xdebug;//445+a
        points[3].y=g_ucaUsart2ReceiveBuffer[9]-47+Ydebug;//47+b
//        points[8].x=g_ucaUsart2ReceiveBuffer[3];
    
//    }

    sortPointsClockwise(points);

//    sprintf((char *)string,"  %d  ",points[3].x);//显示6050数据
//	OLED_ShowString(0,1,string,12);
//	sprintf((char *)string,"  %d  ",points[3].y);//显示6050数据
//	OLED_ShowString(50,1,string,12);
//	sprintf((char *)string,"  %d  ",points[2].x);//显示6050数据
//	OLED_ShowString(0,3,string,12);
//	sprintf((char *)string,"  %d  ",points[2].y);//显示6050数据
//	OLED_ShowString(50,3,string,12);
//	sprintf((char *)string,"  %d  ",points[1].x);//显示6050数据
//	OLED_ShowString(0,5,string,12);
//	sprintf((char *)string,"  %d  ",points[1].y);//显示6050数据
//	OLED_ShowString(50,5,string,12);
//	sprintf((char *)string,"  %d  ",points[0].x);//显示6050数据
//	OLED_ShowString(0,7,string,12);
//	sprintf((char *)string,"  %d  ",points[0].y);//显示6050数据
//	OLED_ShowString(50,7,string,12);

//    printf("Points in clockwise order:\n");
    for (int i = 3; i>=0; i--) {
         NEW_points[i].x= 5.62* points[i].x;   //500/89 5.619
         NEW_points[i].y=5.35 * points[i].y; //500/91
//        printf("Point 4: (%d, %d)\r\n",  points[3].x, points[3].y);
//        printf("Point 3: (%d, %d)\r\n",  points[2].x, points[2].y);
//        printf("Point 2: (%d, %d)\r\n",  points[1].x, points[1].y);
//        printf("Point 1: (%d, %d)\r\n",  points[0].x, points[0].y);
//         printf("Point %d: (%d, %d)\r\n",  i,NEW_points[i].x, NEW_points[i].y);
    
    }
//for()
//    float newX=6.25 * points[i].x;
//    float newY=6.25 * points[i].y;
    
    return 0;
}
    
/*坐标系转换后输出*/
void change_pwmset(void)
{
//   __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_4, 750+);  //水平 PA11
//   __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, 565);  //竖直 PA8

//    slow_motion (0, -250, 0, -250,10);
//    slow_motion (-250, -250, 0, -250,50);
//    HAL_Delay(2000);
    slow_motion (0, NEW_points[3].x, 0, NEW_points[3].y,50);
    HAL_Delay(6000);      
    slow_motion (NEW_points[3].x, NEW_points[2].x, NEW_points[3].y, NEW_points[2].y,20);
    //HAL_Delay(2000);
    slow_motion (NEW_points[2].x, NEW_points[1].x, NEW_points[2].y, NEW_points[1].y,20);
   // HAL_Delay(2000);
    slow_motion (NEW_points[1].x, NEW_points[0].x, NEW_points[1].y, NEW_points[0].y,20);
   // HAL_Delay(2000);
     slow_motion (NEW_points[0].x, NEW_points[3].x, NEW_points[0].y, NEW_points[3].y,20);
   // HAL_Delay(2000);
    
    
}

