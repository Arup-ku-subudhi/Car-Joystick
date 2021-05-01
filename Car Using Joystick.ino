const int IN1=3;  //HIGH to Forward (right wheel)
const int IN2=4;  //HIGH to Backward (right wheel)
const int IN3=5;  //HIGH to Forward (left wheel)
const int IN4=6;  //HIGH to Backward (left wheel)
const int ena=A2; // TO control Speed of left wheel
const int enb=A3; // To control Speed of right wheel

int xpotPin = A0;
int ypotPin = A1; // Define UNO board A1 pin connect the Ioystick y
int swPin = 9;   // Define UNO board digital 9 pin connect the Ioystick sw

int xval = 0;
int yval = 0;
int swval= 0;
void setup()
{
  Serial.begin(9600);
  pinMode(swPin,INPUT_PULLUP);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(ena,OUTPUT);
  pinMode(enb,OUTPUT);
}
void loop() {
  int xval = analogRead(xpotPin);
  int yval = analogRead(ypotPin);
  int swval = digitalRead(swPin);
  delay(1000);
  Serial.print("xval : ");
  Serial.print(xval);
  Serial.print(" yval : ");
  Serial.println(yval);
  if( xval>290 && xval<340)
  {
    if(yval>600 && yval<700){neutral();}
  }
  else if(xval<100 && yval>550)
  {
    forward();
  }
  else if(xval<500 && yval>900)
  {
    left();
  }
  else if(xval<100 && yval<100)
  {
    right();
  }
  else if(xval>600 && yval>600)
  {
    backward();  
  }
}
void neutral()
{
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
}
void forward()
{
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  analogWrite(ena,300);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  analogWrite(enb,300);
}

void backward()
{
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  analogWrite(ena,300);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  analogWrite(enb,300);
}

void right()
{
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  analogWrite(ena,300);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  analogWrite(enb,300);
}

void left()
{
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  analogWrite(ena,300);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  analogWrite(enb,300);
}
