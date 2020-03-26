// This #include statement was automatically added by the Particle IDE.
#include <HC_SR04.h>

double cm = 0.0;
int led = D7;

int trigPin = D4;
int echoPin = D5;

HC_SR04 rangefinder = HC_SR04(trigPin, echoPin);

void setup() 
{
    Spark.variable("cm", &cm, DOUBLE);
    pinMode(led, OUTPUT);
    pinMode(D0, OUTPUT);
}

void loop() 
{
    digitalWrite(D0, LOW);
    digitalWrite(led, HIGH);
    cm = rangefinder.getDistanceCM();
    Particle.publish("distance", String(cm), PRIVATE);
    delay(15000);
    
    digitalWrite(led, LOW);
    delay(15000);
}