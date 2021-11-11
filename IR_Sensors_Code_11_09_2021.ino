const int INPINLEFT = 33;// input pin for left sensor
const int INPINRIGHT = 31;// input pin for right sensor

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
    pinMode(INPINLEFT, INPUT); //set pins to accept input
   pinMode(INPINRIGHT, INPUT);

   digitalRead(INPINLEFT);//read inpinleft to be compared
   digitalRead(INPINRIGHT);//read inpinright to be compared\
   
  if(INPINLEFT==LOW && INPINRIGHT==LOW)//if its all good, go forward
  {

    Serial.print("led's high");

     }
  else if(INPINLEFT==HIGH && INPINRIGHT==LOW)//if its drifting right (left sensor triggered==off), turn left
  {
    Serial.print("veers left, call right turn subroutine");
  }
 
  else if(INPINLEFT==HIGH && INPINRIGHT==HIGH)//if both sensors triggered, stop{

  Serial.print("you're too close, call stop subroutine");
 
  else
  {
    int counter = counter + 1; //theres no significance to this other than i dont like ending cases on else.
  }
}
 
