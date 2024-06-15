//L200921 Aisha Muhammad Nawaz - IIOT A1 BSCS 8A Spring 2024
/*
-> ODD ROLL NUMBER QUESTION:
Build a traffic light and pedestrian boom-gate system for a busy road. Due to high vehicular traffic,
the signal normally stays green, and the boom-gate remains closed. When any pedestrians arrive to
cross the road, a PIR motion sensor detects them, and once at least 60 seconds have passed since
signal turned green, the system turns the traffic signal to yellow-then-red, and the boom gate then
opens. When the sensor no longer detects pedestrians, or after 30 seconds (whichever is earlier),
the traffic light changes to yellow-then-green and boom gate closes.
Note the timing requirements:
• Yellow light duration: 3 seconds
• Minimum time signal stays green: 60 seconds
• Maximum time signal stays red: 30 seconds
*/
#include <Servo.h>
int ON=255;
int OFF=0;

//<--- LEDs --->
int led_red=3;
int led_green=2;
int redState, yellowState=OFF;
int greenState=ON;

//<--- PIR SENSOR --->
int pirSensor=A4;
int pirState;

//<--- BOOM GATE --->
int gate=A5;
int posGate; //loop Variable
Servo servoGate;
int gateStatus=0; //0 for Gate Closed, 1 for Gate Opened.

//<--- Intervals --->
unsigned long lastTimeRed,lastTimeGreen=0;  // To store the last time the LED was updated
const long yellow_interval = 3000; //3 sec
const long green_interval = 60000; // Min time 60 sec
const long red_interval = 30000; // Max time 30 sec

void setup()
{
  pinMode(led_red, OUTPUT);
  pinMode(led_green, OUTPUT);
  pinMode(pirSensor,INPUT);
  servoGate.attach(gate);
  analogWrite(led_green,greenState); //Initially Green Light ON
}
void openGate()
{
for (posGate=90;posGate>=0;posGate=posGate-2) //Rotating Gate to open
{
servoGate.write(posGate);
delay(20);
}
gateStatus=1; //Updating status of gate to open i.e 1
}

void closeGate()
{
for (posGate=0;posGate<=90;posGate=posGate+2)//Rotating Gate to close
{
servoGate.write(posGate);
delay(20);
}
gateStatus=0; //Updating status of gate to close i.e 0
}
void loop()
{
 //Getting Current Time
 unsigned long currentTime = millis();
 
//Read PIR Sensor State 
 pirState=digitalRead(pirSensor);
 
 if(pirState==HIGH)// If motion detected
 { 
   if (currentTime - lastTimeGreen >= green_interval) //If green interval passed
   {
     if(greenState==ON)
     {
         //Open Gate (If it is Closed)
         if(gateStatus==0){openGate();} 

         //Turn on Yellow light
         analogWrite(led_red,ON);
         redState=ON;
         yellowState=ON; // Note: Red+Green light on means Yellow Light
         delay(yellow_interval); // Let yellow light on till yellow interval

         //Turn on Red light
         greenState=OFF;  
         analogWrite(led_green,greenState);
         lastTimeRed=millis(); //Update lastTime changed to Red to current time
     }
   }
 }
  else if((pirState==LOW) || (currentTime - lastTimeRed >= red_interval))//If no motion detected or red interval reached
  {   
    if(redState==ON)
    { //IF RED ON
         //Turn on  yellow light
          greenState=ON; //as Green+RED = Yellow
          yellowState=ON;
          analogWrite(led_green,ON);
          delay(yellow_interval); // Let yellow light on till yellow interval

          //Turn off red light
          redState=OFF;
          analogWrite(led_red,redState);
          // Save the last time state changed of RED
          lastTimeRed = millis();

          //Close Gate (If it is opened)
          if(gateStatus==1){closeGate();}
    }
 } 
}