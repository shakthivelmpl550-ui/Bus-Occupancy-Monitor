#include <LiquidCrystal.h>

// Pins
#define BUTTON 4
#define LED 2
#define BUZZER 15

// LCD pins
LiquidCrystal lcd(21, 22, 19, 23, 25, 26);


// Variables
int students = 0;


void setup()
{
  Serial.begin(115200);

  pinMode(BUTTON, INPUT_PULLUP);

  pinMode(LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);


  lcd.begin(16,2);

  lcd.setCursor(0,0);
  lcd.print("BUS MONITOR");

  lcd.setCursor(0,1);
  lcd.print("Starting...");

  delay(2000);

  lcd.clear();

  displayData();
}



void loop()
{

  // Student entry button
  if(digitalRead(BUTTON) == LOW)
  {

    students++;

    Serial.print("Students : ");
    Serial.println(students);


    displayData();


    // wait for button release
    while(digitalRead(BUTTON)==LOW)
    {
      delay(10);
    }


    delay(300);
  }

}



// Display function
void displayData()
{

  lcd.clear();


  lcd.setCursor(0,0);
  lcd.print("Students:");
  lcd.print(students);



  lcd.setCursor(0,1);


  if(students > 50)
  {

    lcd.print("FULL ALERT");

    digitalWrite(LED,HIGH);
    digitalWrite(BUZZER,HIGH);

  }

  else
  {

    lcd.print("NORMAL");

    digitalWrite(LED,LOW);
    digitalWrite(BUZZER,LOW);

  }

}