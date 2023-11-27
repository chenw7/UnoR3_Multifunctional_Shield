//Testing out Github for FIRST TIME
#include <dht11.h>
#include "IRremote.h"

//LEDs
int LED1 = 2;
int RGBr = 5;
int RGBg = 6;
int RGBb = 11;

//Ultrasonic Sensor
int trigPin = 9;
int echoPin = 10;

//Joystick
int x = A2;
int y = A3;
int joyButton = 8;

//Various Others
int buzzer = 12;
int pushButton = 4;
int poten = A0;
int tilt = 3;
int tempHumid = 7;

int photo = A1;
const int IRrec = 7;
IRrecv irrecv(IRrec);
decode_results results;


//Other necessary variables
long elapsedTime;
long duration;
double distance;
int tiltState;
int lastTiltState = HIGH;
long lastTime = 0;
long debounceDelay = 50;
int chk;
int lightReading = 0;

//Available Functions
void ledOne(int t);
void RGB(int r, int g, int b);
double getDistance();
int getX();
int getY();
void buzz(int t);
bool buttonPushed();
bool joyButtonPushed();
int getPoten();
void getTilt();
float getTemp();
float getHumid();
dht11 DHT11;
void receiveIR();
int senseLight();


//Setup and Main
void setup() {
  Serial.begin(9600);
  
  pinMode(LED1, OUTPUT);
  pinMode(RGBr, OUTPUT);
  pinMode(RGBg, OUTPUT);
  pinMode(RGBb, OUTPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(joyButton, INPUT);
  digitalWrite(joyButton, HIGH); //always high until pressed

  pinMode(buzzer, OUTPUT);
  pinMode(pushButton, INPUT);
  pinMode(tilt, INPUT);
  digitalWrite(tilt, HIGH); //turn on built-in pull up
  pinMode(tempHumid, INPUT);
  pinMode(IRrec, INPUT);

  irrecv.enableIRIn();
  irrecv.blink13(true);
}

void loop() {
//  Turns on led for specified time (ms)
//  ledOne(500);

//  Outputs ultrasonic sensor distance in cm
//  Serial.println(getDistance());

//  Buzzer buzzes for specified time (ms)
//  buzz(200);
  
//  Indicates whether the button has been pressed on not
//  Serial.println(buttonPushed());

//  Outputs potentiometer reading
//  Serial.println(getPoten());

//  LED1 lights up when not tilted
//  getTilt(); 

//  Outputs temperature in celsius and humidity in %
//  Serial.print("Temperature: ");
//  Serial.println(getTemp());
//  Serial.print("Humidity: ");
//  Serial.println(getHumid());

//  Outputs which button is being pressed
//  receiveIR();

//  Outputs brightness on scale of 1-10
//  Serial.println(senseLight());

//  Outputs xy readings and pushed or not
//  Serial.println(getX());
//  Serial.println(getY());
//  Serial.println(pushed());
//  Serial.println();
//  delay(200);
}


//Function Implementations
void ledOne(int t){
  digitalWrite(LED1, HIGH);
  delay(t);
  digitalWrite(LED1, LOW);
}

void RGB(int r, int g, int b){
  analogWrite(RGBr, r);
  analogWrite(RGBg, g);
  analogWrite(RGBb, b);
}

double getDistance(){
  elapsedTime = millis();
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = ((duration/1000000.0)*343.0*100.0)/2.0; //in centimeters
  
  return distance;
}

int getX(){
  return analogRead(x);
}

int getY(){
  return analogRead(y);
}

void buzz(int t){
  digitalWrite(buzzer, HIGH);
  delay(t);
  digitalWrite(buzzer, LOW);
}

bool buttonPushed(){
  if(digitalRead(pushButton) == HIGH)
    return false;
  else{
    return true;
  }
}
bool joyButtonPushed(){
  if(digitalRead(joyButton) == HIGH){
    return false;
  }
  else{
   return true;
  }
}

int getPoten(){
  return analogRead(poten);
}

void getTilt(){
  tiltState = digitalRead(tilt);
  if(tiltState == lastTiltState){
    lastTime = millis();
  }
  if((millis() - lastTime) > debounceDelay){
    digitalWrite(LED1, HIGH);
    lastTiltState = tiltState;
  }
  if(tiltState == 1){
    digitalWrite(LED1, LOW);
  }
  else{
    digitalWrite(LED1, HIGH);
  }  
}

float getTemp(){
  chk = DHT11.read(tempHumid);
  return (float)DHT11.temperature;
}

float getHumid(){
  chk = DHT11.read(tempHumid);
  return (float)DHT11.humidity;
}

void receiveIR(){
  if (irrecv.decode()) {
    switch(irrecv.decodedIRData.decodedRawData){
      case 4077715200: 
        Serial.println("1");
        break;
      case 3877175040: 
        Serial.println("2");
        break;
      case 2707357440: 
        Serial.println("3");
        break;
      case 4144561920: 
        Serial.println("4"); 
        break;
      case 3810328320: 
        Serial.println("5");
        break;
      case 2774204160: 
        Serial.println("6");
        break;
      case 3175284480: 
        Serial.println("7");
        break;
      case 2907897600: 
        Serial.println("8");
        break;
      case 3041591040: 
        Serial.println("9");
        break;
      case 3910598400: 
        Serial.println("0");
        break;
    }
    irrecv.resume();
  } 
}

int senseLight(){
  lightReading = analogRead(photo);
  return map(lightReading, 0, 1023, 1, 10);
}
