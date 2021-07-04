        //Full code is not added.
                 /*Defence Entrance Security System*/           
                      //Keypad LCD Lock Part

#include <Keypad.h>
#include <LiquidCrystal.h>

const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {A0, A1, A2, A3}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {A4, A5, 2, 3}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

// 16x2 LCD 
#define rs 10 
#define en 8 
#define d4 7  
#define d5 6  
#define d6 5 
#define d7 4 
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

String password = "1234";
String mypassword;

int redled = 12;
int lock = 13;

int counter = 0; 
int attempts = 0; 
int max_attempts = 3; 

void setup(){
  Serial.begin(9600);
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  
  pinMode(redled, OUTPUT);
  pinMode(lock, OUTPUT);
  
  digitalWrite(redled, LOW);
  digitalWrite(lock, LOW);
  delay(500);
  Serial.println("\n Enter the PIN");
  lcd.print("Enter the PIN");
}
  
void loop()
{
}
