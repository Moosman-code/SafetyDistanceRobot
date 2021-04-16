int buzzerPin = 13;
int triggerPin = 10;
int echoPin = 9;
int time;
int frequency;
int distance;
int redLightPin = 8;
int yellowLightPin = 7;
int greenLightPin = 6;

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  Serial.begin(115200);
pinMode (buzzerPin, OUTPUT);
pinMode (triggerPin, OUTPUT);
pinMode (echoPin, INPUT);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
}

void loop()
{  
  digitalWrite(triggerPin, HIGH);
  delay(10);
  digitalWrite(triggerPin, LOW);
  time = pulseIn(echoPin, HIGH);
  
  distance = (time*0.034) / 2;
  if (distance <= 49)
  {
    digitalWrite(redLightPin, HIGH);
    digitalWrite(yellowLightPin, LOW);
    digitalWrite(greenLightPin, LOW);
    digitalWrite(buzzerPin, HIGH);
    tone(13, 500, 200);
    lcd.setCursor(0, 0);
    lcd.print("Too close");
    lcd.setCursor(0, 1);
    lcd.print(distance);
    delay(10);
  }
  else if(distance >= 50 && distance <= 99){
    digitalWrite(redLightPin, HIGH);
    digitalWrite(yellowLightPin, LOW);
    digitalWrite(greenLightPin, LOW);
  Serial.println("More distance");
    Serial.println(distance);
    digitalWrite(buzzerPin, HIGH);
    tone(13, 400, 200);
    lcd.setCursor(0, 0);
    lcd.print("More distance");
    lcd.setCursor(0, 1);
    lcd.print(distance);    
    delay(10);
  }
  else if(distance >= 100 && distance <= 149){
    digitalWrite(yellowLightPin, HIGH);
    digitalWrite(redLightPin, LOW);
    digitalWrite(greenLightPin, LOW);
  Serial.println("Step back!!!");
    Serial.println(distance);
    digitalWrite(buzzerPin, HIGH);
    tone(13, 300, 200);
    lcd.setCursor(0, 0);
    lcd.print("Step back!!!");
    lcd.setCursor(0, 1);
    lcd.print(distance);
    delay(10);
  }
  else if(distance >= 150 && distance <= 169){
    digitalWrite(yellowLightPin, HIGH);
    digitalWrite(redLightPin, LOW);
    digitalWrite(greenLightPin, LOW);
  Serial.println("Keep distance");
    Serial.println(distance);
    digitalWrite(buzzerPin, HIGH);
    tone(13, 100, 200);
    lcd.setCursor(0, 0);
    lcd.print("Keep distance");
    lcd.setCursor(0, 1);
    lcd.print(distance);
    delay(10);
  }
  else if(distance >= 170){
    digitalWrite(greenLightPin, HIGH);
    digitalWrite(yellowLightPin, LOW);
    digitalWrite(redLightPin, LOW);
  	Serial.println("OK");
    Serial.println(distance);
    lcd.setCursor(0, 0);
    lcd.print("OK");
    lcd.setCursor(0, 1);
    lcd.print(distance);
    delay(10);
  }
  lcd.clear();
}
 