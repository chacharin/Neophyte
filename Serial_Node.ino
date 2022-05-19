#include <ros.h>
#include <std_msgs/Int16.h>
#include<Servo.h>
Servo S3; Servo S5; Servo S6; Servo S9; Servo S10; Servo S11;

int x3, x5, x6, x9, x10, x11 = 90;

ros::NodeHandle  nh;
 
void decision( const std_msgs::Int16 & cmd_msg)
{ nh.loginfo("reviced");
  int cmd = cmd_msg.data; 
  if(cmd == 1) { nh.loginfo("1"); digitalWrite(13,1); one(); }
  if(cmd == 2) { nh.loginfo("2"); digitalWrite(13,0); two(); }
  else {}
}

ros::Subscriber<std_msgs::Int16> sub("pass_data2", decision);
 
void setup()
{
  pinMode(13, OUTPUT);
  S3.attach(3);S5.attach(5);S6.attach(6);S9.attach(9); S10.attach(10);S11.attach(11);delay(1000);
  nh.initNode(); nh.subscribe(sub);
}

void loop()
{
  nh.spinOnce();
  delay(1);
}

void one() 
{ nh.loginfo("Coca-Cola is on the way...");
x3=90; while(x3 >= 30){S3.write(x3); delay(20); x3 -= 1; }
x11=90; while(x11 >= 15){S11.write(x11); delay(20); x11 -= 1; }
x6=90; while(x6 <= 140){S6.write(x6); delay(20); x6 += 1; }
x10=90; while(x10 >= 70){S10.write(x10); delay(20); x10 -= 1; }
x9=90; while(x9 >= 20){S9.write(x9); delay(20); x9 -= 1; }
x10=70; while(x10 >= 50){S10.write(x10); delay(20); x10 -= 1; }
x9=20; while(x9 >= 0){S9.write(x9); delay(20); x9 -= 1; }
x10=50; while(x10 <= 65){S10.write(x10); delay(20); x10 += 1; }
x3=30; while(x3 <= 100){S3.write(x3); delay(20); x3 += 1; }
x9=0; while(x9 <= 20){S9.write(x9); delay(20); x9 += 1; }
x11=15; while(x11 <= 90){S11.write(x11); delay(20); x11 += 1; }
x9=20; while(x9 >= 0){S9.write(x9); delay(20); x9 -= 1; }
x3=100; while(x3 >= 30){S3.write(x3); delay(20); x3 -= 1; }
/*back to begin*/
x6=140; while(x6 >= 90){S6.write(x6); delay(20); x6 -= 1; }
x9=0; while(x9 <= 90){S9.write(x9); delay(20); x9 += 1; }
x10=65; while(x10 <= 90){S10.write(x10); delay(20); x10 += 1; }
/*back to begin*/
S3.write(90); delay(200); S5.write(90); delay(200); S6.write(90); delay(200); 
S9.write(90); delay(200); S10.write(90); delay(200); S11.write(90); delay(200);
nh.loginfo("Coca-Cola have served");
}

void two()
{ nh.loginfo("Orange-Juice is on the way...");
x3=90; while(x3 >= 30){S3.write(x3); delay(20); x3 -= 1; }
x11=90; while(x11 <= 180){S11.write(x11); delay(20); x11 += 1; }
x6=90; while(x6 <= 140){S6.write(x6); delay(20); x6 += 1; }
x10=90; while(x10 >= 70){S10.write(x10); delay(20); x10 -= 1; }
x9=90; while(x9 >= 20){S9.write(x9); delay(20); x9 -= 1; }
x10=70; while(x10 >= 50){S10.write(x10); delay(20); x10 -= 1; }
x9=20; while(x9 >= 0){S9.write(x9); delay(20); x9 -= 1; }
x10=50; while(x10 <= 65){S10.write(x10); delay(20); x10 += 1; }
x3=30; while(x3 <= 100){S3.write(x3); delay(20); x3 += 1; }
x9=0; while(x9 <= 20){S9.write(x9); delay(20); x9 += 1; }
x11=180; while(x11 >= 90){S11.write(x11); delay(20); x11 -= 1; }
x9=20; while(x9 >= 0){S9.write(x9); delay(20); x9 -= 1; }
x3=100; while(x3 >= 30){S3.write(x3); delay(20); x3 -= 1; }
/*back to begin*/
x6=140; while(x6 >= 90){S6.write(x6); delay(20); x6 -= 1; }
x9=0; while(x9 <= 90){S9.write(x9); delay(20); x9 += 1; }
x10=65; while(x10 <= 90){S10.write(x10); delay(20); x10 += 1; }
/*back to begin*/
S3.write(90); delay(200); S5.write(90); delay(200); S6.write(90); delay(200); 
S9.write(90); delay(200); S10.write(90); delay(200); S11.write(90); delay(200);
nh.loginfo("Orange-Juice have served");
}
