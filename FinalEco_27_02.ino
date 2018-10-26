#include<Servo.h>

#define Left 2
#define Right 3

int sensorPin[5] = {12, 11, 10, 9, 8};

#define s_2 A4
#define s_3 A5

#define s_22 A2
#define s_32 A3

float Kp = 0.05;
float Kd = 0.03;
float Kdd = 0.0;

int tCount = 0;
int riverDone = 0;

Servo myServo;

int leftThresh = 15, rightThresh = 15;
int ThresholdRed[5] = {12, 12, 12, 12, 12};
int ThresholdBlue[5] = {0, 0, 0, 0, 0};
int ThresholdGreen[5] = {0, 0, 0, 0, 0};

int colorRedData[5], colorBlueData[5], colorGreenData[5], colorClearData[5], leftData, rightData;
int cored[10][5], sum[5], b = 0, d = 0;
int coleft[40], coright[40], sumLeft, sumRight;

int deviation = 0, deviationEcho = 0, deviationLeft = 0, deviationRight = 0;
int deviationLeftEcho = 0, deviationRightEcho = 0;
int sensorNum = 0;

int tChk = 0;

int initial = 82;
float desPos = 0.0, curPos = 0.0;
float error = 0, errorDiff = 0, errorEcho = 0;
float correction = 0;

void setup()
{
  analogWrite(s_2, 0);        // 0,0 red    0,1 blue    1,0 gray    1,1 green
  analogWrite(s_3, 255);
  analogWrite(s_22, 0);
  analogWrite(s_32, 255);
  myServo.attach(6);
  myServo.write(initial);
}

void loop() 
{
  movAvgs();
  deviationEcho = deviation;
  deviationLeftEcho = deviationLeft;
  deviationRightEcho = deviationRight;
  deviation = 0;
  sensorNum = 0;

  colourInputPulse();
  deviationCal();

  if ((sumLeft+sumRight)/5 < 75 && tCount == 1)     //river
  {
    ThresholdRed[0] = 8;
    ThresholdRed[1] = 8;
    ThresholdRed[2] = 5;
    ThresholdRed[3] = 8;
    ThresholdRed[4] = 8;

    analogWrite(s_2,0);
    analogWrite(s_2,0);
    
    riverDone = 1;
    angleCalBlue();
  }
  
  else if(tCount == 0)            //others
  {
    T_Chk();
    ThresholdRed[0] = 12;
    ThresholdRed[1] = 12;
    ThresholdRed[2] = 12;
    ThresholdRed[3] = 12;
    ThresholdRed[4] = 12;

    analogWrite(s_2, 0);
    analogWrite(s_3, 255);

    angleCal();
  }
  else 
  {                                // Slope
    ThresholdRed[0] = 9;
    ThresholdRed[1] = 9;
    ThresholdRed[2] = 9;
    ThresholdRed[3] = 9;
    ThresholdRed[4] = 9;
    
    analogWrite(s_2, 0);
    analogWrite(s_3, 255);
 
    angleCal();
  }

  PID();
}




