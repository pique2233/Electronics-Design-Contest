# Find Rects Example
#
# 这个例子展示了如何使用april标签代码中的四元检测代码在图像中找到矩形。 四元检测算法以非常稳健的方式检测矩形，并且比基于Hough变换的方法好得多。 例如，即使镜头失真导致这些矩形看起来弯曲，它仍然可以检测到矩形。 圆角矩形是没有问题的！
# (但是，这个代码也会检测小半径的圆)...

import sensor, image, time
import ustruct
from pyb import UART

# import numpy


sensor.reset()
sensor.set_pixformat(sensor.RGB565)  # 灰度更快(160x120 max on OpenMV-M7)
sensor.set_framesize(sensor.QQVGA)
sensor.set_windowing(120,120) #取中间的80*80区域
sensor.skip_frames(time=2000)
# .set_hmirror(True)
sensor.set_auto_gain(False) # 关闭自动自动增益。默认开启的，在颜色识别中，一定要关闭白平衡。
sensor.set_auto_whitebal(False)
sensor.set_auto_exposure(False, 20000)
sensor.set_contrast(3)
#sensor.set_brightness(500)


clock = time.clock()
uart = UART(3, 115200, bits=8, parity=None, stop=1, timeout_char=1000)
red_threshold = (55, 100, 23, 127, -128, 127)
rects_threshold = (42, 100, -128, 127, -128, 127)
ROI=[]
#滑动窗口滤波的
def sliding_window_filter(flag0, flag1, flag2, flag3, flag4, flag5, flag6, flag7, center_x, center_y, window_size, filter_param):
    window = []  # 滑动窗口
    #滑动窗口大小 window_size 指的是用于滤波的窗口的长度，即滑动窗口中保留的数据个数
   #filter_param 较大的滤波参数意味着更强烈的滤波效果，会使滤波结果对噪声等不良数据更不敏感，较大的滤波参数将使滤波器更加强烈地抑制高频噪声，并产生更平坦、更平滑的输出信号。

    for data in [flag0, flag1, flag2, flag3, flag4, flag5, flag6, flag7, center_x, center_y]:
        window.append(data)  # 将当前数据添加到滑动窗口中

        if len(window) > window_size:
            window.pop(0)  # 如果滑动窗口大小超过设定的窗口大小，则移除最早进入窗口的数据

    # 对窗口内的数据进行滤波处理，这里仍假设采用简单的加权平均滤波
    filtered_value = sum(window) / len(window) * filter_param

    return filtered_value
def sending_data(c1, c2, c3, c4, c5, c6, c7, c8, c9, c10):  # 定义发送数据的函数，输入要发送数据 data 发送时候加入帧头 0xA5 0xA6 #用的上
    global uart;
    data = ustruct.pack("<bbbbbbbbbbbbb",  # 格式为八个字符占八位ustruct.pack是py的函数
                        0xA5,  # 帧头1
                        0xA6,  # 帧头2
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
                        0x5B  # 帧尾
                        )
    uart.write(data);  # 必须要传入一个字节数组 通过串口发送出去
    #print(data)  # 输出在调试终端


while (True):
    clock.tick()
    #area = (0, 0, 80, 80)#x,y,w,h


    img = sensor.snapshot()
    #img = NO_cropped_img.gaussian(1)
    #img = NO_cropped_img1.laplacian(0.5, threshold=1)




    #img = NO_cropped_img.crop((0, 0, 100, 100))  # 裁剪图像为 100x100 像素
    center_x = 0
    center_y = 0
    flag0 = flag1 = flag2 = flag3 = flag4 = flag5 = flag6 = flag7 = 0
    flag = []
    ###########################红外识别############################
    blobs = img.find_blobs([red_threshold])
    if blobs:
        # 找到最大的blob
        max_blob = max(blobs, key=lambda b: b.pixels())

        # 计算激光点中心坐标
        center_x = max_blob.cx()
        center_y = max_blob.cy()

        # 绘制激光点中心
        img.draw_cross(center_x, center_y, size=10, color=(255, 255, 255))
        center_x = center_x - 20 +5+1

        center_y = -center_y + 100 +8
        #print("%d,%d",center_x,center_y)
        # if(center_x>100):center_x = 100
        # if(center_y>100):center_y = 100
        # if(center_x<0):center_x = 0
        # if(center_y<0):center_y = 0
        #print("%d,%d",center_x,center_y)
        ##flag8 = center_x
        ##flag9 = center_y

    #####################################矩形############################################
    # 下面的`threshold`应设置为足够高的值，以滤除在图像中检测到的具有
    # 低边缘幅度的噪声矩形。最适用与背景形成鲜明对比的矩形。


    for r in img.find_rects(threshold = 15000):
        img.draw_rectangle(r.rect(), color=(255, 0, 0))

        for j in range(1):
            i = 0
            for p in r.corners():
                img.draw_circle(p[0], p[1], 5, color=(0, 255, 0))
                # img.draw_string(p[0], p[1], "p[0], p[1]", color=White)
                # img.draw_circle(XX,YY, 5, color = (0, 255, 0))

                P0 = p[0] - 20 + 6
                P1 = -p[1] + 100 + 6
                #print(P0, end=' ')  # 循环打印四个角的坐标
                #print(P1, end='    ')  # 循环打印四个角的坐标()

                #new_x1 = x1 + shrink_amount
                #new_y1 = y1 + shrink_amount
                #new_x2 = x2 - shrink_amount
                #new_y2 = y2 - shrink_amount


                if (i == 0):
                    # flag.append(p[0])  # 将 p[0] 添加到数组中
                    flag0 = P0
                    flag1 = P1
                if (i == 1):
                    flag2 = P0
                    flag3 = P1

                if (i == 2):
                    flag4 = P0
                    flag5 = P1
                if (i == 3):
                    flag6 = P0
                    flag7 = P1

                # if(i == 5):
                # flag0 = 0xEE
                i += 1
            #flag0 = int(flag0 / 10)
            #flag1 = int(flag1 / 10)
            #flag2 = int(flag2 / 10)
            #flag3 = int(flag3 / 10)
            #flag4 = int(flag4 / 10)
            #flag5 = int(flag5 / 10)
            #flag6 = int(flag6 / 10)
            #flag7 = int(flag7 / 10)
            #print('\n')
            sliding_window_filter(flag0, flag1, flag2, flag3, flag4, flag5, flag6, flag7, center_x, center_y, 5, 0.8)
    #滑动窗口大小 window_size 指的是用于滤波的窗口的长度，即滑动窗口中保留的数据个数
   #filter_param 较大的滤波参数意味着更强烈的滤波效果，会使滤波结果对噪声等不良数据更不敏感，较大的滤波参数将使滤波器更加强烈地抑制高频噪声，并产生更平坦、更平滑的输出信号。

            sending_data(flag0, flag1, flag2, flag3, flag4, flag5, flag6, flag7, center_x, center_y)  # 循环打印四个角的坐标
            print(flag0, flag1, flag2, flag3, flag4, flag5, flag6, flag7, center_x, center_y)
        # sleep_ms(100)
        # print(flag[1])#循环打印四个角的坐标
        # print(f"Point {i+1}-{j+1}: ({p[0]}, {p[1]})")  # 打印四个角的坐标并区分不同点

#################################################################################
    #for x in range(30, 140, 11):  # 每 100 像素绘制一个垂直线
        #img.draw_line((x, 0, x, img.height()), color=(255, 0, 0))
    #for y in range(10, 120, 11):  # 每 100 像素绘制一个水平线
        #img.draw_line((0, y, img.width(), y), color=(255, 0, 0))
    img.draw_line((20-5-1, 0, 20-5-1, img.height()), color=(0, 255, 0))
    img.draw_line((0, 100+7+1, img.width(), 100+7+1), color=(0, 255, 0))
    img.draw_line((100+5-2, 0, 100+5-2, img.height()), color=(0, 255, 0))
    img.draw_line((0, 16+1, img.width(), 16+1), color=(0, 255, 0))
##
    img.draw_line((60-2, 0, 60-2, img.height()), color=(0, 255, 0))
    img.draw_line((0, 60, img.width(), 60), color=(0, 255, 0))

# print("FPS %f" % clock.fps())
