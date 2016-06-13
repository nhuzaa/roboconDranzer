import numpy as np
import cv2

cap = cv2.VideoCapture(0)
ret = cap.set(3,640)
ret = cap.set(4,480)

while True:
    ret, frame = cap.read()
    gray = cv2.cvtColor(frame,cv2.COLOR_BGR2GRAY)
    gauss = cv2.GaussianBlur(frame,(3,3),0)
    edges = cv2.Canny(gauss,50,100,apertureSize = 3)
    lines = cv2.HoughLines(edges,1,np.pi/180,50)
    cv2.imshow('Dranzer', edges)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

for rho,theta in lines[0]:
    a = np.cos(theta)
    b = np.sin(theta)
    x0 = a*rho
    y0 = b*rho
    x1 = int(x0 + 1000*(-b))
    y1 = int(y0 + 1000*(a))
    x2 = int(x0 - 1000*(-b))
    y2 = int(y0 - 1000*(a))
    cv2.line(frame,(x1,y1),(x2,y2),(0,0,255),2)


    #cv2.imshow('frame',frame)

# When everything done, release the capture
cap.release()
cv2.destroyAllWindows()