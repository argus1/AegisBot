#include <Servo.h>
#include <MeetAndroid.h>

Servo servoLeft;
Servo servoRight;
MeetAndroid meetAndroid;
int onboardLed = 13;


int sensorPin = 3;
int sensorPin1 = 6;
int sensorPin2 = 7;
int qti[3];
bool rcTimeoutFault = false;
const long RC_TIMEOUT_COUNT = 3000;

int n = 0;
int n1 = 0;
int threshold = 20;

long result = 0;
void setup()
{
  Serial.begin(9600);
  Serial.println("start");
  meetAndroid.registerFunction(testEvent, 'A');  
  tone(4, 3000, 1000);
  pinMode(onboardLed, OUTPUT);
  digitalWrite(onboardLed, HIGH);
  servoLeft.attach(11);
  servoRight.attach(10);
}

//float threshold = RCtime(sensorPin)-((RCtime(sensorPin)+RCtime(sensorPin2))/2);
//read & navigate function
void loop()
{
  rcTimeoutFault = false;
  //Serial.println(threshold);
  if (RCtime(sensorPin)>= threshold){
    qti[0] = 1;}
    else{
    qti[0]=0;}
  if (RCtime(sensorPin1)>= threshold){
    qti[1] = 1;}
    else{
    qti[1]=0;}
  if (RCtime(sensorPin2)>= threshold){
    qti[2] = 1;}
    else{
    qti[2]=0;}

  if (rcTimeoutFault) {
    servoLeft.writeMicroseconds(1500);
    servoRight.writeMicroseconds(1500);
    delayMicroseconds(40);
    return;
  }
  n = random(0,500);
  n1 = random(0,500);
  if(qti[0]==0 && qti[1]==1 && qti[2]==0){
    servoLeft.writeMicroseconds(1700 + n);
    servoRight.writeMicroseconds(1300 - n1);
  }
      
  else if(qti[0]==1 && qti[1]==1 && qti[2]==0){
    servoLeft.writeMicroseconds(1700 + n);
    servoRight.writeMicroseconds(1500);
  }
      
  else if(qti[0]==1 && qti[1]==0 && qti[2]==0){
    servoLeft.writeMicroseconds(1700 + n);
    servoRight.writeMicroseconds(1700 + n1);
  }
      
  else if(qti[0]==0 && qti[1]==1 && qti[2]==1){
    servoLeft.writeMicroseconds(1500 + n);
    servoRight.writeMicroseconds(1300 - n1);
  }
          
  else if(qti[0]==0 && qti[1]==0 && qti[2]==1){
    servoLeft.writeMicroseconds(1300 - n);
    servoRight.writeMicroseconds(1300 - n1);
  }
  
  else if(qti[0]==1 && qti[1]==1 && qti[2]==1){
    servoLeft.writeMicroseconds(1500);
    servoRight.writeMicroseconds(1500);
  }
  delayMicroseconds(40);
  
  //servoLeft.writeMicroseconds(1700);
  //servoRight.writeMicroseconds(1300);
  
  //Serial.println(qti[0]);
  //Serial.println(qti[1]);
  //Serial.println(qti[2]);

}



long RCtime(int sensPin){
  long result = 0;
  pinMode(sensPin, OUTPUT);
  digitalWrite(sensPin, HIGH);
  delay(1);
  
  pinMode(sensPin, INPUT);
  digitalWrite(sensPin, LOW);
  while(digitalRead(sensPin) && result < RC_TIMEOUT_COUNT){
    result++;
  }

  if (result >= RC_TIMEOUT_COUNT) {
    rcTimeoutFault = true;
  }
  
  return result;
}

void testEvent(byte flag, byte numOfValues)
{
  flushLed(300);
  flushLed(300);
}

void flushLed(int time)
{
  digitalWrite(onboardLed, LOW);
  delay(time);
  digitalWrite(onboardLed, HIGH);
  delay(time);
}
