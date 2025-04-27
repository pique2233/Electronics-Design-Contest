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
sensor.set_framesize(sensor.QVGA)
sensor.skip_frames(time=2000)
sensor.set_windowing(220,220) #取中间的80*80区域
sensor.set_auto_gain(False) # 关闭自动自动增益。默认开启的，在颜色识别中，一定要关闭白平衡。

sensor.set_auto_whitebal(False)
sensor.set_auto_exposure(False, 1000)  # 曝光速度

clock = time.clock()
uart = UART(3, 115200, bits=8, parity=None, stop=1, timeout_char=1000)
red_threshold = (53, 100, -10, 127, -128, 127)
green_threshold = (65, 100, -63, -15, -128, 127)
ROI=[]
F1= F2 = 0
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
    NO_cropped_img = sensor.snapshot().lens_corr(strength = 1.6, zoom = 1)
    img = NO_cropped_img.gaussian(1)
    center_x = 0
    center_y = 0
    center_x_G =0
    center_y_G=0
    flag0 = flag1 = flag2 = flag3 = flag4 = flag5 = flag6 = flag7 = 0
    flag = []
    ###########################红外识别############################
    blobs = img.find_blobs([green_threshold])

    if blobs:
        # 找到最大的blob
        max_blob = max(blobs, key=lambda b: b.pixels())

        # 计算激光点中心坐标
        center_x_G = max_blob.cx()
        center_y_G = max_blob.cy()

        # 绘制激光点中心
        img.draw_cross(center_x_G, center_y_G, size=10, color=(0, 255, 0))
        center_x_G = center_x_G
        center_y_G = -center_y_G + 240
        F1 = 1
    else:
        F1 = 0

    blobs = img.find_blobs([red_threshold])
    if blobs:
        # 找到最大的blob
        max_blob = max(blobs, key=lambda b: b.pixels())

        # 计算激光点中心坐标
        center_x = max_blob.cx()
        center_y = max_blob.cy()

        # 绘制激光点中心
        img.draw_cross(center_x, center_y, size=10, color=(255,1 , 0))
        center_x = center_x
        center_y = -center_y+240
        #print("%d,%d",center_x,center_y)
        F2 = 1
    else:
        F2 = 0
    if(F1 ==F2 ==1):
        sending_data(center_x, center_y, center_x_G, center_y_G, 0, 0, 0, 0, 0, 0)
