
//middle sensors pointing down
//outside sensors pointing slightly out

//Sensors (CHANGED NAMES DUE TO AMBIGUITY)
//sensor0 = A0 (LL)
//sensor1 = A1 (ML)
//sensor2 = A2 (MR)
//sensor3 = A3 (RR)

//LEDs
//left_led = 6
//go_led = 4
//right_led = 7

//Motors
//motor_left = 5
//motor_right = 11

//Initial Readings (Over White) (ADDED)
int read0 = 0;
int read1 = 0;
int read2 = 0;
int read3 = 0;

//STOP
int counter = 0;

void setup() {
  // put your setup code here, to run once:
  //Transistors
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);

  //LEDs
  pinMode(6,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(7,OUTPUT);
  
  //Wheels
  pinMode(5,OUTPUT);
  pinMode(11,OUTPUT);

  //Initial Readings over White (ADDED)
  read0 = analogRead(A0);
  read1 = analogRead(A1);
  read2 = analogRead(A2);
  read3 = analogRead(A3);
}

void loop() {
  //STOP
  if(counter == 2)
  {
    analogWrite(5, 0);
    analogWrite(11, 0);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    return;
  }
  
  //Transistor
  int LL = ((read0 - analogRead(A0)) > 150);
  int ML = ((read1 - analogRead(A1)) > 150);
  int MR = ((read2 - analogRead(A2)) > 150);
  int RR = ((read3 - analogRead(A3)) > 150);
  //MAYBE I AM TOO PARANOID TO IMPLEMENT LL AND RR

  //CONDITIONALS (NEEDS EXPERIMENTATION FOR MOTOR AND DELAY VALUES)
  if((LL+ML+MR+RR) >= 3)
  {
    counter++;
    analogWrite(5, 160);
    analogWrite(11, 128);
    delay(60);
    LL = ((read0 - analogRead(A0)) > 150);
    ML = ((read1 - analogRead(A1)) > 150);
    MR = ((read2 - analogRead(A2)) > 150);
    RR = ((read3 - analogRead(A3)) > 150);
    if((LL+ML+MR+RR) >= 3)
    {
      counter++;
      analogWrite(5, 0);
      analogWrite(11, 0);
      digitalWrite(6, HIGH);
      digitalWrite(4, LOW);
      digitalWrite(7, HIGH);
      delay(100);
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      delay(100);
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
      delay(100);
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      delay(100);
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
      delay(100);
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      delay(100);
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
      delay(100);
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      delay(100);
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
      delay(100);
      digitalWrite(2, LOW);
      digitalWrite(6, LOW);
      delay(100);
      return;
    }
    else
    {
      counter--;
    }
  }
  
  if(RR)
  {
    digitalWrite(6, LOW);
    digitalWrite(4, LOW);
    digitalWrite(7, HIGH);
    analogWrite(5, 180);
    analogWrite(11, 0);
  }
  else if(LL)
  {
    digitalWrite(6, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(7, LOW);
    analogWrite(5, 0);
    analogWrite(11, 150);
  }
  else if(MR)
  {
    digitalWrite(6, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(7, HIGH);
    analogWrite(5, 160);
    analogWrite(11, 70);
  }
  else if(ML)
  {
    digitalWrite(6, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(7, LOW);
    analogWrite(5, 70);
    analogWrite(11, 128); //128
  }
  else
  {
    digitalWrite(6, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(7, LOW);
    analogWrite(5, 160);
    analogWrite(11, 128);
  }
}






//Initialize over good quality paper?

//Sensors (CHANGED NAMES DUE TO AMBIGUITY)
//sensor0 = A0 (LL)
//sensor1 = A1 (ML)
//sensor2 = A2 (MR)
//sensor3 = A3 (RR)

//LEDs
//left_led = 6
//go_led = 4
//right_led = 7

//Motors
//motor_left = 5
//motor_right = 11

//Initial Readings (Over White) (ADDED)
int read0 = 0;
int read1 = 0;
int read2 = 0;
int read3 = 0;

//STOP
int counter = 0;

void setup() {
  // put your setup code here, to run once:
  //Transistors
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);

  //LEDs
  pinMode(6,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(7,OUTPUT);
  
  //Wheels
  pinMode(5,OUTPUT);
  pinMode(11,OUTPUT);

  //Initial Readings over White (ADDED)
  read0 = analogRead(A0);
  read1 = analogRead(A1);
  read2 = analogRead(A2);
  read3 = analogRead(A3);
}

void loop() {
  //STOP
  if(counter == 2)
  {
    analogWrite(5, 0);
    analogWrite(11, 0);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    return;
  }
  
  //Transistor
  int LL = ((read0 - analogRead(A0)) > 100);
  int ML = ((read1 - analogRead(A1)) > 100);
  int MR = ((read2 - analogRead(A2)) > 100);
  int RR = ((read3 - analogRead(A3)) > 100);
  //MAYBE I AM TOO PARANOID TO IMPLEMENT LL AND RR

  //CONDITIONALS (NEEDS EXPERIMENTATION FOR MOTOR AND DELAY VALUES)
  if((LL+ML+MR+RR) >= 3)
  {
    counter++;
    analogWrite(5, 160);
    analogWrite(11, 128);
    delay(60);
    LL = ((read0 - analogRead(A0)) > 100);
    ML = ((read1 - analogRead(A1)) > 100);
    MR = ((read2 - analogRead(A2)) > 100);
    RR = ((read3 - analogRead(A3)) > 100);
    if((LL+ML+MR+RR) >= 3)
    {
      counter++;
      analogWrite(5, 0);
      analogWrite(11, 0);
      digitalWrite(6, HIGH);
      digitalWrite(4, LOW);
      digitalWrite(7, HIGH);
      delay(100);
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      delay(100);
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
      delay(100);
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      delay(100);
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
      delay(100);
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      delay(100);
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
      delay(100);
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      delay(100);
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
      delay(100);
      digitalWrite(2, LOW);
      digitalWrite(6, LOW);
      delay(100);
      return;
    }
    else
    {
      counter--;
    }
  }
  
  if(RR)
  {
    digitalWrite(6, LOW);
    digitalWrite(4, LOW);
    digitalWrite(7, HIGH);
    analogWrite(5, 180);
    analogWrite(11, 0);
  }
  else if(LL)
  {
    digitalWrite(6, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(7, LOW);
    analogWrite(5, 0);
    analogWrite(11, 150);
  }
  else if(MR)
  {
    digitalWrite(6, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(7, HIGH);
    analogWrite(5, 160);
    analogWrite(11, 0);
  }
  else if(ML)
  {
    digitalWrite(6, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(7, LOW);
    analogWrite(5, 0);
    analogWrite(11, 128); //128
  }
  else
  {
    digitalWrite(6, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(7, LOW);
    analogWrite(5, 160);
    analogWrite(11, 128);
  }
}


