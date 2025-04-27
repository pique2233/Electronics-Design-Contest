# Find Rects Example
#
# 这个例子展示了如何使用april标签代码中的四元检测代码在图像中找到矩形。 四元检测算法以非常稳健的方式检测矩形，并且比基于Hough变换的方法好得多。 例如，即使镜头失真导致这些矩形看起来弯曲，它仍然可以检测到矩形。 圆角矩形是没有问题的！
# (但是，这个代码也会检测小半径的圆)...

import sensor, image, time
import ustruct
from pyb import UART
#import numpy


sensor.reset()
sensor.set_pixformat(sensor.RGB565) # 灰度更快(160x120 max on OpenMV-M7)
sensor.set_framesize(sensor.QQVGA)
sensor.skip_frames(time = 2000)
sensor.set_hmirror(True)
clock = time.clock()
uart = UART(3,115200,bits=8, parity=None, stop=1, timeout_char = 1000)
red_threshold = (65, 100, 10, 127, -128, 127)


def sending_data(c1,c2,c3,c4,c5,c6,c7,c8,c9,c10): #定义发送数据的函数，输入要发送数据 data 发送时候加入帧头 0xA5 0xA6 #用的上
    global uart;
    data = ustruct.pack("<bbbbbbbbbbbbb",      #格式为八个字符占八位ustruct.pack是py的函数
                   0xA5,                      #帧头1
                   0xA6,                      #帧头2
                   c1,
                   c2,
                   c3,
                   c4,
                   c5,
                   c6,
                   c7,
                   c8,
                   c9,
                   c10,
                   0x5B                    #帧尾
                   )
    uart.write(data);   #必须要传入一个字节数组 通过串口发送出去
    print(data)      #输出在调试终端




while(True):
    clock.tick()
    img = sensor.snapshot()
    i = 0
    flag = []
 #######################################################
    blobs = img.find_blobs([red_threshold])
    if blobs:
        # 找到最大的blob
        max_blob = max(blobs, key=lambda b: b.pixels())

        # 计算激光点中心坐标
        center_x = max_blob.cx()
        center_y = max_blob.cy()

        # 绘制激光点中心
        img.draw_cross(center_x, center_y, size=10, color=(255, 255, 255))
        #flag8 = center_x
        #flag9 = center_y
    # 下面的`threshold`应设置为足够高的值，以滤除在图像中检测到的具有
    # 低边缘幅度的噪声矩形。最适用与背景形成鲜明对比的矩形。
    for r in img.find_rects(threshold = 50000):
        img.draw_rectangle(r.rect(), color = (255, 0, 0))
        for p in r.corners():
            img.draw_circle(p[0], p[1], 5, color = (0, 255, 0))
            #img.draw_circle(XX,YY, 5, color = (0, 255, 0))
            #print(p[0],end = ' ')#循环打印四个角的坐标
            #print(p[1],end = '    ')#循环打印四个角的坐标()
            if(i==0):
                #flag.append(p[0])  # 将 p[0] 添加到数组中
                flag0 = p[0]
                flag1 = p[1]
            if(i == 1):
                flag2 = p[0]
                flag3 = p[1]

            if(i == 2):
                flag4 = p[0]
                flag5 = p[1]
            if(i == 3):
                flag6 = p[0]
                flag7 = p[1]


            #if(i == 5):
                #flag0 = 0xEE
            i += 1
        sending_data(flag0,flag1,flag2,flag3,flag4,flag5,flag6,flag7,center_x,center_y)#循环打印四个角的坐标
        #sleep_ms(100)
            #print(flag[1])#循环打印四个角的坐标
            #print(f"Point {i+1}-{j+1}: ({p[0]}, {p[1]})")  # 打印四个角的坐标并区分不同点
    print('\n')
    #print("FPS %f" % clock.fps())
