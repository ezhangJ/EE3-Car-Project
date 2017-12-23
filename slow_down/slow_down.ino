//Sensors
//sensor1 = 2
//sensor2 = 3

//Motors
//motor_left = 5;
//motor_right = 11;

//LEDs
//left_led = 6
//right_led = 7

//Wheel Speed (PWM)
int LSpeed = 145;
int RSpeed = 110;

//Interrupt Counters, Functions, and other Parameters
//JUST MORE EFFICIENT TO CALCULATE WITH LATER
unsigned long Lcount = 0;
unsigned long Rcount = 0;

void Linterrupt() {
  Lcount++;
}

void Rinterrupt() {
  Rcount++;
}



void setup() {
  //Sensors
  pinMode(2,INPUT);
  pinMode(3,INPUT);

  //Wheels
  pinMode(5,OUTPUT);
  pinMode(11,OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  //0 and 1 correspond to digital pins 2 and 3
  attachInterrupt(0, Linterrupt, CHANGE);
  attachInterrupt(1, Rinterrupt, CHANGE);
  analogWrite(5, LSpeed);
  analogWrite(11, RSpeed);
  unsigned long start = millis();
  unsigned long duration;
  //delay until at least one second has passed
  while((duration = (millis()-start)) < 500);
  detachInterrupt(0);
  detachInterrupt(1);
  double Lrpm = ((double)(Lcount*60000))/(40*duration);
  double Rrpm = ((double)(Rcount*60000))/(40*duration);
  //PROB DON’T NEED DOUBLES
  Serial.println(Lrpm, 3);
  Serial.println(Rrpm, 3);
  Serial.println('\n');
  if(Lcount == 0) {
    digitalWrite(6, HIGH);
    delay(100);
    digitalWrite(6, LOW);
    delay(100);
    digitalWrite(6, HIGH);
    delay(100);
    digitalWrite(6, LOW);
    delay(100);
    digitalWrite(6, HIGH);
    delay(100);
    digitalWrite(6, LOW);
    delay(100);
    digitalWrite(6, HIGH);
    delay(100);
    digitalWrite(6, LOW);
    delay(100);
    digitalWrite(6, HIGH);
    delay(100);
    digitalWrite(6, LOW);
    delay(100);
    LSpeed = 145;
  }
  if(Rcount == 0) {
    digitalWrite(7, HIGH);
    delay(100);
    digitalWrite(7, LOW);
    delay(100);
    digitalWrite(7, HIGH);
    delay(100);
    digitalWrite(7, LOW);
    delay(100);
    digitalWrite(7, HIGH);
    delay(100);
    digitalWrite(7, LOW);
    delay(100);
    digitalWrite(7, HIGH);
    delay(100);
    digitalWrite(7, LOW);
    delay(100);
    digitalWrite(7, HIGH);
    delay(100);
    digitalWrite(7, LOW);
    delay(100);
    RSpeed = 115;
  }
  Lcount = 0;
  Rcount = 0;
  LSpeed -= 2;
  RSpeed -= 2;
}



