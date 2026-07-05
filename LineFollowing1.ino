#include <Servo.h>
#include <MeetAndroid.h>

Servo servoLeft;
Servo servoRight;
MeetAndroid meetAndroid;
int onboardLed = 13;
int i = 0;
unsigned long time;
unsigned long tinit = 0;

int sensorPin = 3;
int sensorPin1 = 6;
int sensorPin2 = 7;
int qti[3];
bool rcTimeoutFault = false;
const long RC_TIMEOUT_COUNT = 3000;

int n = 0;
int threshold = 20;

long result = 0;
void setup()
{
  Serial.begin(9600);
  Serial.println("start");
  meetAndroid.registerFunction(testEvent, 'A');
  meetAndroid.registerFunction(forward, 'b' ); 
  tone(4, 3000, 1000);
  pinMode(onboardLed, OUTPUT);
  digitalWrite(onboardLed, HIGH);
  servoLeft.attach(11);
  servoRight.attach(10);
  tinit = micros();
}

//float threshold = RCtime(sensorPin)-((RCtime(sensorPin)+RCtime(sensorPin2))/2);
//read & navigate function
void loop()
{
   meetAndroid.receive();
  rcTimeoutFault = false;
  //Serial.println(threshold);
  time = micros() - tinit;
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

  if(qti[0]==0 && qti[1]==1 && qti[2]==0){
    servoLeft.writeMicroseconds(1700);
    servoRight.writeMicroseconds(1300);
  }
      
  else if(qti[0]==1 && qti[1]==1 && qti[2]==0){
    servoLeft.writeMicroseconds(1700);
    servoRight.writeMicroseconds(1500);
  }
      
  else if(qti[0]==1 && qti[1]==0 && qti[2]==0){
    servoLeft.writeMicroseconds(1700);
    servoRight.writeMicroseconds(1700);
  }
      
  else if(qti[0]==0 && qti[1]==1 && qti[2]==1){
    servoLeft.writeMicroseconds(1500);
    servoRight.writeMicroseconds(1300);
  }
          
  else if(qti[0]==0 && qti[1]==0 && qti[2]==1){
    servoLeft.writeMicroseconds(1300);
    servoRight.writeMicroseconds(1300);
  }
  
  else if(qti[0]==1 && qti[1]==1 && qti[2]==1){
    servoLeft.writeMicroseconds(1500);
    servoRight.writeMicroseconds(1500);
    i++;
    if(i>=5){
      meetAndroid.send("The Robot has Stopped:");
      meetAndroid.send(i);
      meetAndroid.send(time);
    }
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

void forward(byte flag, byte numOfValues)
{
    servoLeft.writeMicroseconds(1700);
    servoRight.writeMicroseconds(1300);
    delay(100); 
    tinit = micros();
    meetAndroid.send("The new initial time is:");
    meetAndroid.send(tinit);
    i = 0;
}
