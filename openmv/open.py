import sensor
import image
import time
from pyb import UART
import ustruct
sensor.reset()  # Reset and initialize the sensor.
sensor.set_pixformat(sensor.RGB565)  # Set pixel format to RGB565 (or GRAYSCALE)
sensor.set_framesize(sensor.QVGA)  # Set frame size to QVGA (320x240)
sensor.skip_frames(time=2000)  # Wait for settings take effect.
clock = time.clock()  # Create a clock object to track the FPS.
uart = UART(3,115200)#timeout_char = 10000
red_threshold = (30, 100, 15, 127, 15, 127)  #红色区域 
'''
目标是识别红色圆形物体，并通过UART发送其位置和大小信息。具体而谈，是识别红色激光笔
'''

while(True):
    img = sensor.snapshot()
    blobs = img.find_blobs([red_threshold],area_threshold=150, merge=True)#合并相邻色块
    if blobs:
        for blob in blobs:
            img.draw_reactangle(blob.rect(),color =(255, 0, 0))
            img.draw_cross(blob.cx(), blob.cy(), color=(0, 255, 0))
            cx = blob.cx()  # 获取圆心的x坐标
            cy = blob.cy()  # 获取圆心的y坐标
            uart.write("Centroid detected at x:{}, y:{}\n".format(cx, cy))
            print("Centroid detected at x:{}, y:{}".format(cx, cy))
    else:
        image_data = bytearray([0x2C, 7, 0, 0, 3, 4, 0x5B])  # 如果没有检测到红色圆形物体，发送默认数据
        uart.write(image_data)
             
    