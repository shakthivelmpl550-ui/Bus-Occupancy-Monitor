#include <LiquidCrystal.h>

#define BUTTON 4
#define LED 2
#define BUZZER 15

LiquidCrystal lcd(21,22,19,23,25,26);

int students = 0;
int maxSeats = 50;
int availableSeats = 0;

int fullCount = 0;

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
  if(digitalRead(BUTTON) == LOW)
  {
    students++;

    availableSeats = maxSeats - students;

    Serial.print("Students : ");
    Serial.println(students);

    Serial.print("Available Seats : ");
    Serial.println(availableSeats);

    displayData();

    while(digitalRead(BUTTON)==LOW)
    {
      delay(10);
    }

    delay(300);
  }
}

void displayData()
{
  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("Stud:");
  lcd.print(students);

  lcd.setCursor(10,0);
  lcd.print("A:");
  lcd.print(availableSeats);

  if(students > 50)
  {
    fullCount++;
  }
  else
  {
    fullCount = 0;
  }

  lcd.setCursor(0,1);

  if(fullCount >= 3)
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
