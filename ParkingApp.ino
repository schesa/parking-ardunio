const int trigPin = 5;
const int echoPin = 6;

const int left_digit = 2;
const int right_digit = 3;

const int pk = 7;

const int dA0= 11;
const int dA1= 12;
const int dA2= 13;

long duration;
int cm;

int places = 0;

void setup() {
  Serial.begin(9600);
  
  pinMode(dA0, OUTPUT);
  pinMode(dA1, OUTPUT);
  pinMode(dA2, OUTPUT);
  pinMode(pk, OUTPUT);
  
  pinMode(left_digit, OUTPUT);
  pinMode(right_digit, OUTPUT);
  
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW); 
  pinMode(echoPin, INPUT);

  hide_pk();
}

void show_a(){
  digitalWrite(dA0, LOW);  
  digitalWrite(dA1, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(dA2, LOW);   // turn the LED on (HIGH is the voltage level
  delay(1);
}
void show_b(){
  digitalWrite(dA0, HIGH);  
  digitalWrite(dA1, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(dA2, LOW);   // turn the LED on (HIGH is the voltage level
  delay(1);
}
void show_c(){
  digitalWrite(dA0, LOW);  
  digitalWrite(dA1, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(dA2, LOW);   // turn the LED on (HIGH is the voltage level
  delay(1);
}
void show_d(){
  digitalWrite(dA0, HIGH);  
  digitalWrite(dA1, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(dA2, LOW);   // turn the LED on (HIGH is the voltage level
  delay(1);
}
void show_e(){
  digitalWrite(dA0, LOW);  
  digitalWrite(dA1, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(dA2, HIGH);   // turn the LED on (HIGH is the voltage level
  delay(1);
}
void show_f(){
  digitalWrite(dA0, HIGH);  
  digitalWrite(dA1, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(dA2, HIGH);   // turn the LED on (HIGH is the voltage level
  delay(1);
}

void show_pk(){
  digitalWrite(pk,HIGH);
  delay(1);
}

void hide_pk(){
  digitalWrite(pk,LOW);
}

void show_digit(int digit){
  hide_pk();
  switch(digit){
    case 0:
      show_a();
      show_b();
      show_c();
      show_d();
      show_e();
      show_f();
    break;
    case 1:
      show_b();
      show_c();
    break;
    case 2:
      show_a();
      show_b();
      show_pk();
      show_e();
      show_d();
    break;
    case 3:
      show_a();
      show_b();
      show_pk();
      show_c();
      show_d();
    break;
    case 4:
      show_f();
      show_b();
      show_pk();
      show_c();
    break;
    case 5:
      show_a();
      show_f();
      show_d();
      show_pk();
      show_c();
    break;
    
    case 6:
      show_e();
      show_f();
      show_d();
      show_pk();
      show_c();
      show_a();
    break;
    
    case 7:
      show_a();
      show_b();
      show_c();
    break;
    
    case 8:
      show_a();
      show_b();
      show_c();
      show_d();
      show_e();
      show_f();
      show_pk();
    break;
    case 9:
      show_a();
      show_b();
      show_c();
      show_d();
      show_f();
      show_pk();
    break;
    }
}

void show_right_digit(){
  digitalWrite(left_digit, LOW); 
  digitalWrite(right_digit, HIGH);
}

void show_left_digit(){
  digitalWrite(left_digit, HIGH); 
  digitalWrite(right_digit, LOW);
}

void show_number(int number){
  if(number < 10 && number >=0){
//    show_green()     
    show_right_digit();
    show_digit(number);
    show_left_digit();
    show_digit(0);
  }else if (number >99 || number < 0){
//    show_red()
    places=0;
  }else{
//    show_green()
    show_right_digit();
    show_digit(number%10);
    show_left_digit();
    show_digit(number/10);
  }
}

void loop() {
  show_number(places);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  Serial.print("Duration - ");
  Serial.println(duration);
  cm = duration*0.034/2;
  Serial.print("Cm - ");
  Serial.println(cm);

 if(cm<5)
    places++;
}

