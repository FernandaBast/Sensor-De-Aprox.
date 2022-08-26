const int trigPin = 26;
const int echoPin = 32;
const int buzzer = 19;
const int led3 = 21;
const int led2 = 25;
const int led1 = 18;


long duration;
int distance;
int safetyDistance;
 
void setup() {
pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT); 
pinMode(buzzer, OUTPUT);
pinMode(led3, OUTPUT);
pinMode(led2, OUTPUT);
pinMode(led1, OUTPUT);
Serial.begin(115200); 
}
 
void loop() {

digitalWrite(trigPin, LOW);
delay(2);
 

digitalWrite(trigPin, HIGH);
delay(10);
digitalWrite(trigPin, LOW);
 
duration = pulseIn(echoPin, HIGH);

distance= (duration*0.034)/2;
 
safetyDistance = distance;
if (distance <=25)
{
  digitalWrite(buzzer, HIGH);
  delay(500);
  digitalWrite(buzzer, LOW);
  delay(500);
}
else
{
  digitalWrite(buzzer, LOW);
}
if (distance <=50)
{
  digitalWrite(led1, HIGH);
}
else
{
  digitalWrite(led1, LOW);
}
if (distance <=75)
{
  digitalWrite(led2, HIGH);
}
else
{
  digitalWrite(led2, LOW);
}
if (distance <=100)
{
  digitalWrite(led3, HIGH);
}
else
{
  digitalWrite(led3, LOW);
}
 

Serial.print("Distance: ");
Serial.println(distance);
}
