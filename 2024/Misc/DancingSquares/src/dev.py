import cv2
import numpy as np

with open('flag.txt', 'r') as file:
    content = file.read()
binary_content = ''.join(format(ord(char), '08b') for char in content)

height, width = 480, 640
canvas = np.zeros((height, width, 3), dtype=np.uint8)

def draw_square(color):
    square_size = 20
    pt1 = ((width - square_size) // 2, (height - square_size) // 2)
    pt2 = ((width + square_size) // 2, (height + square_size) // 2)
    cv2.rectangle(canvas, pt1, pt2, color, -1)

frame_per_second = 90
fourcc = cv2.VideoWriter_fourcc(*'MP4V')
out = cv2.VideoWriter('crazy.mp4', fourcc, frame_per_second, (width, height))

colors = [(0, 0, 255), (255, 0, 0),(0,255,0),(255,255,0)]

for bit in binary_content:
    color = colors[int(bit)]
    canvas.fill(0)
    draw_square(color)
    out.write(canvas)
    color=colors[3]
    canvas.fill(0)
    draw_square(color)
    out.write(canvas)

out.release()