#!/usr/bin/env python3
import cv2
import time
import rospy
from std_msgs.msg import Int16

def talker(val):
    rospy.init_node('Cam_node', anonymous=True)
    pub = rospy.Publisher('pass_data1', Int16, queue_size=0)
    rate = rospy.Rate(50) # 1hz
    rospy.loginfo(val)
    pub.publish(val)
    rate.sleep()

face_cascade = cv2.CascadeClassifier('/home/ubuntu/catkin_ws/src/my_project/src/haarcascade_frontalface_default.xml')
cap = cv2.VideoCapture(2)
global tick
tick = False
global count
count = 0
while(1):
    _, img = cap.read()
    # Convert into grayscale
    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    # Detect faces
    faces = face_cascade.detectMultiScale(gray, 1.4, 3)

    # Draw rectangle around the faces
    for (x, y, w, h) in faces:
        cv2.rectangle(img, (x, y), (x + w, y + h), (255, 0, 0), 2)
        if(faces[0,3] > 225):
            if tick == False:
                if count< 5:
                    print("Detected")
                    talker(5)
                    count = 5
                tick = True   
        elif(faces[0,3] <= 225):
            tick = False
            if count>=5 and count<50:
                count+=1
            else:
                count=0

    # Display the output
    cv2.imshow('img', img)
    k = cv2.waitKey(30) & 0xff
    if k == 27:
        break
cap.release()