import os
import cv2

cap1 = cv2.VideoCapture(1)
ret1 = cap1.set(3,800)
ret1 = cap1.set(4,480)

while True:
    ret1, image1 = cap1.read()
    roi = image1[row:row + height, column:column + width]
    cv2.imshow("ROI 1", roi)

cv2.waitKey(0)

