const int VSND = 0.034; //speed of sound in cm/microsecond
const int IRRIGHT = 33;// input pin for left sensor
pinMode(IRLEFT, INPUT); //set pins to accept input
//https://www.tutorialspoint.com/arduino/arduino_ultrasonic_sensor.htm
void setup() {
  Serial.begin(9600);
  //subroutine variables
  const int IRLEFT = 31;// input pin for right sensor
  pinMode(IRRIGHT, INPUT);
  const int TRIG = 53;//trigger pin on ultrasonic sensor - output
  pinMode(TRIG, OUTPUT);
  const int ECHO = 51;//echo pin on ultrasonic sensor - input
  pinMode(ECHO, INPUT);
  //klaire u need motors pins
  //main variables
  float distance;//distance from ultrasonic to obstacle
  int irline;//the ir
  //motor crap
}

void loop() {
//this reads irs left and right, and if its not deviating, checks distance. 
  digitalRead(IRLEFT);//read IRLEFT to be compared
  digitalRead(IRRIGHT);//read IRRIGHT to be compared\
  if(IRLEFT==LOW && IRRIGHT==LOW)//if its all good, go forward
  {
    //Serial.print("led's high");
    distanceViaUltrasonic();
    //call motors go forwards
  }
  else if(IRLEFT==HIGH && IRRIGHT==LOW)//if its drifting right (left sensor triggered==off), turn left
  {
    //Serial.print("veers right, call left turn subroutine");
    distanceViaUltrasonic();
    //call morotrs turn left
  }
  else if(IRLEFT==LOW && IRRIGHT==HIGH)//if its drifting left (right sensor triggered==off), turn right
  {
    //Serial.print("veers left, call right turn subroutine");
    distanceViaUltrasonic();
    //call morotrs turn right
  }
  else if(IRLEFT==HIGH && IRRIGHT==HIGH)//if both sensors triggered, stop
  {
    //Serial.print("you're too close, call stop subroutine");
    distanceViaUltrasonic();//may be redundant bc its gonna stop anyway
    //call stop subroutine
  }
}

void irsensor(){
   
}

void distanceViaUltrasonic(){
  //this checks distance and if distance is too short it stops otherwise it keeps going
  //https://create.arduino.cc/projecthub/abdularbi17/ultrasonic-sensor-hc-sr04-with-arduino-tutorial-327ff6
  //arduino uses milliseconds, ultrason uses microseconds. theres a built in function delayMicroseconds()
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  float duration = pulseIn(ECHO, HIGH);
  float dist = (duration*VSND)/2;//dist in cm from sensor to obstacle
  Serial.print(dist);//debug for testing purposes 
  delay(100);
  if(distance>10){
    //call stop subroutine
  }
}
 

 
