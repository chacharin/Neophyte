#!/usr/bin/env python3
import os
from playsound import playsound
import speech_recognition as sr
from gtts import *

import rospy
from std_msgs.msg import Int16

def conversation():
    while(1):
        os.environ["GOOGLE_APPLICATION_CREDENTIALS"]="/home/ubuntu/000.json"
        r = sr.Recognizer()
        file = sr.Microphone()
        with file as source:
            playsound("/home/ubuntu/catkin_ws/src/my_project/src/signal.mp3")
            audio = r.record(source,duration=3.5)
            print("Record finish")
        try:
            r = sr.Recognizer()
            answer = r.recognize_google_cloud(audio, language = 'en')
            print(answer)
        except Exception as e:
            print("An error occure: " + str(e))
        except sr.UnknownValueError:
            print("Google Speech Recognition could not understand audio")
        
        if "Coca-Cola" in answer:
            playsound("/home/ubuntu/catkin_ws/src/my_project/src/Cola.mp3")
            talker(1)
            break
        elif "orange" in answer:
            playsound("/home/ubuntu/catkin_ws/src/my_project/src/Oj.mp3")
            talker(2)
            break
        else:
            playsound("/home/ubuntu/catkin_ws/src/my_project/src/Sorry.mp3")

def publish():
    talker()

def talker(val):
    pub1 = rospy.Publisher('pass_data2', Int16, queue_size=10)
    rate = rospy.Rate(10) 
    cmd_value = Int16(val)
    rospy.loginfo(cmd_value)
    pub1.publish(cmd_value)
    rate.sleep()

def callback(data):
    rospy.loginfo(rospy.get_caller_id() + "I recived %s", data.data)
    if(data.data==5):
        rospy.loginfo(rospy.get_caller_id() + "I recived %s", data.data)
        rospy.loginfo("Conversation Begin")
        playsound("/home/ubuntu/catkin_ws/src/my_project/src/Hello.mp3")
        playsound("/home/ubuntu/catkin_ws/src/my_project/src/Ask.mp3")
        conversation()
    
def listener():
    rospy.Subscriber("pass_data1", Int16, callback)
    rospy.spin()


if __name__ == '__main__':
    rospy.init_node('Sound_node_Reciver', anonymous=True)
    while not rospy.is_shutdown():
        listener()
        

