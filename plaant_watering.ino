int trigPin=12;
int echoPin=13;
int relay1=4;
int relay2=6;
int mois = A0;
int distance, duration,water;
void setup() {
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  pinMode(relay1,OUTPUT);
  pinMode(relay2,OUTPUT);
  pinMode(mois,INPUT);
  Serial.begin(9600); 
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); 
  Serial.println("with Arduino UNO R3");
}
void loop() {
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  duration = pulseIn(echoPin, HIGH);
  
  distance = duration * 0.034 / 2;
  
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  if(distance>=7)
  {
    while(distance>3)
    digitalWrite(relay1,LOW);
  }
  digitalWrite(relay1,HIGH);
  delay(1000);
 
   water=analogRead(A0);
   Serial.println("Analog output of soil sensor: ");
   Serial.print(water);
   if(water>400)
  {
    while(water>=300)
    digitalWrite(relay2,LOW);
  }
  digitalWrite(relay2,HIGH);
  
  
   delay(1000);
}
