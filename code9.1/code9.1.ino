/*
 * Arduino Keypad calculator Program
 */

//header files

#include <LiquidCrystal.h> 
#include <Keypad.h> 

// Four rows
const byte ROWS = 4;
 
// Three columns
const byte COLS = 4;
 
// Define the Keymap
char keys[ROWS][COLS] = 
{
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

// Connect keypad ROW0, ROW1, ROW2 and ROW3 to these Arduino pins.
byte rowPins[ROWS] = { 0, 1, 2, 3 };

// Connect keypad COL0, COL1 and COL2 to these Arduino pins.
byte colPins[COLS] = { 4, 5, 6, 7 }; 

//  Create the Keypad
Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS ); 

//Pins to which LCD is connected
const int rs = 8, en = 9, d4 = 10, d5 = 11, d6 = 12, d7 = 13; 

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

 //variables
 long Num1,Num2,Number;
 char key,action;
 boolean result = false;
 
void setup()
{
  //We are using a 16*2 LCD display
  lcd.begin(16, 2); 
  lcd.print("DIY Calculator");

  // set the cursor to column 0, line 1
  lcd.setCursor(0, 1);   
  lcd.print("-CircuitDigest");  
  
  delay(2000);

  //Then clean it
  lcd.clear(); 
}

void loop() 
{

  //storing pressed key value in a char
  key = kpd.getKey(); 
  
  if (key!=NO_KEY)
    DetectButtons();
  if (result==true)
    CalculateResult();
    
  DisplayResult();   
}

void DetectButtons()
{ 
     lcd.clear(); 

     //If cancel Button is pressed
    if (key=='*')
    {
      Serial.println ("Button Cancel");
      Number=Num1=Num2=0;
      result=false;
     }

     //If Button 1 is pressed
     if (key == '1')
    {
      Serial.println ("Button 1"); 
      if (Number==0)
        Number=1;
      else
        Number = (Number*10) + 1; //Pressed twice
    }

     //If Button 4 is pressed
     if (key == '4') 
    {
      Serial.println ("Button 4"); 
      if (Number==0)
        Number=4;
      else
        Number = (Number*10) + 4; //Pressed twice
    }

     //If Button 7 is pressed
     if (key == '7') 
    {
      Serial.println ("Button 7");
      if (Number==0)
        Number=7;
      else
        Number = (Number*10) + 7; //Pressed twice
    } 

    //Button 0 is Pressed
    if (key == '0')
    {
      Serial.println ("Button 0"); 
      if (Number==0)
        Number=0;
      else
        Number = (Number*10) + 0; //Pressed twice
    }

     //Button 2 is Pressed
     if (key == '2') 
    {
      Serial.println ("Button 2"); 
      if (Number==0)
        Number=2;
      else
        Number = (Number*10) + 2; //Pressed twice
    }
    
     if (key == '5')
    {
      Serial.println ("Button 5"); 
      if (Number==0)
        Number=5;
      else
        Number = (Number*10) + 5; 
    }
    
     if (key == '8')
    {
      Serial.println ("Button 8"); 
      if (Number==0)
        Number=8;
      else
        Number = (Number*10) + 8; 
    }   
  
    if (key == '#')
    {
      Serial.println ("Button Equal"); 
      Num2=Number;
      result = true;
    }
    
     if (key == '3')
    {
      Serial.println ("Button 3"); 
      if (Number==0)
        Number=3;
      else
        Number = (Number*10) + 3; 
    }
    
     if (key == '6')
    {
      Serial.println ("Button 6"); 
      if (Number==0)
        Number=6;
      else
        Number = (Number*10) + 6; //Pressed twice
    }
    
     if (key == '9')
    {
      Serial.println ("Button 9");
      if (Number==0)
        Number=9;
      else
        Number = (Number*10) + 9; 
    } 
     
     if (key == 'A' || key == 'B' || key == 'C' || key == 'D') //Detecting Buttons on Column 4
    {
      Num1 = Number;    
      Number =0;
      if (key == 'A')
     {
      Serial.println ("Addition");
      action = '+';
     }
      if (key == 'B')
     {
      Serial.println ("Subtraction");
      action = '-';
     }
      if (key == 'C')
     {
      Serial.println ("Multiplication");
      action = '*';
     }
      if (key == 'D')
     {
      Serial.println ("Devesion"); 
      action = '/';
     }  
     
    delay(100);
  }
  
}

void CalculateResult()
{
  if (action=='+')
    Number = Num1+Num2;
  if (action=='-')
    Number = Num1-Num2;
  if (action=='*')
    Number = Num1*Num2;
  if (action=='/')
    Number = Num1/Num2; 
}

void DisplayResult()
{
  // set the cursor to column 0, line 1
  lcd.setCursor(0, 0);   
  lcd.print(Num1);
  lcd.print(action);
  lcd.print(Num2); 
  
  if (result==true)
  {
    lcd.print(" =");

    //Display the result
    lcd.print(Number);
  } 
  
  lcd.setCursor(0, 1);

  //Display the result
  lcd.print(Number);
}
