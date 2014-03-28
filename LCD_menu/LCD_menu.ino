/*
  LiquidCrystal Library - Hello World

Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the 
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.
 
 This sketch prints "Hello World!" to the LCD
 and shows the time.
 
  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
 
 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe
 
 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystal
 */

#define bRIGHT  0
#define bUP     1
#define bDOWN   2
#define bLEFT   3
#define bSELECT 4
#define bNONE   5

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
int analogIN = 0, bP = 5; // 5 for NONE no button pressed
// Menu vars
int var1 = 0, var2  = 0, var3  = 0; // options under ea
int conf = 0;	// 0 for false, 1 for true; 
int menuState = 0;// 0; var1; 1; var2, 2; var3, 4; displayData

void menuStateInc()
{
	if(menuState < 2)
		menuState += 1;
	else
  		menuState = 0;
// menuState < 2 ? menuState += 1 : menuState = 0;
}

void menuStateDec()
{
	if(menuState > 0)
		menuState -= 1;
	else
		menuState = 2;
// menuState > 0 ? menuState -= 1 : menuState = 2;
}
int getButton()
{
   analogIN = analogRead(0);      // read the value from the sensor 
 // my buttons when read are centered at these valies: 0, 144, 329, 504, 741
 // we add approx 50 to those values and check to see if we are close
 if (analogIN > 1000) return bNONE; // We make this the 1st option for speed reasons since it will be the most likely result
 // For V1.1 us this threshold
 if (analogIN < 50)   return bRIGHT;  
 if (analogIN < 250)  return bUP; 
 if (analogIN < 450)  return bDOWN; 
 if (analogIN < 650)  return bLEFT; 
 if (analogIN < 850)  return bSELECT;  

 // For V1.0 comment the other threshold and use the one below:
/*
 if (adc_key_in < 50)   return btnRIGHT;  
 if (adc_key_in < 195)  return btnUP; 
 if (adc_key_in < 380)  return btnDOWN; 
 if (adc_key_in < 555)  return btnLEFT; 
 if (adc_key_in < 790)  return btnSELECT;   
*/

 return bNONE;  // when all others fail, return this...
}

void setup() 
{
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  // Print a message to the LCD.
//  lcd.setCursor(0, 0);
 // lcd.print("Press:");
//  lcd.setCursor(0, 1);
//  lcd.print("None.");
}

void loop() 
{
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  //lcd.setCursor(offS, 1);
  // print the number of seconds since reset:
  //lcd.print(millis()/1000);
  
//delay(500);
    
//  bP = getButton();

	// Cycle through menu state;
	switch(getButton())
	{
		case bSELECT:   // User wants to start selection
			do
			{
				delay(300);  // Slow down processing
                                // Display current menu selection
		        	switch(menuState)
                      		{	 
					case 0: // Display var 1
						lcd.setCursor(0, 0);
						lcd.print("Data: Var 1");
	
						lcd.setCursor(0, 1);
                                                //lcd.print("----------------");
						lcd.print(var1);
					break;
					case 1:
						lcd.setCursor(0, 0);
						lcd.print("Data: Var 2");
	
						lcd.setCursor(5, 1);
						lcd.print(var2);
					break;
					case 2:
						lcd.setCursor(0, 0);
						lcd.print("Data: Var 3");
	
						lcd.setCursor(10, 1);
						lcd.print(var3);
					break;
				} 

				// Allow modify menu selection
		        	switch(getButton())
				{	 
					case bUP:	// increment menu state
						menuState < 2 ? menuState += 1 : menuState = 0;
					break;
					case bDOWN:
						menuState > 0 ? menuState -= 1 : menuState = 2;
					break;
					case bRIGHT: 	// Modify var
						do
						{
							// Display current menu selection
							switch(menuState)
							{	 
								case 0: // Display var 1
									lcd.setCursor(0, 0);
									lcd.print("Data: Var 1");
				
									lcd.setCursor(0, 1);
									lcd.print(var1);
								break;
								case 1:
									lcd.setCursor(0, 0);
									lcd.print("Data: Var 2");
				
									lcd.setCursor(5, 1);
									lcd.print(var2);
								break;
								case 2:
									lcd.setCursor(0, 0);
									lcd.print("Data: Var 3");
				
									lcd.setCursor(10, 1);
									lcd.print(var3);
								break;
							} 

							// Allow modify of var
							switch(menuState)
							{
								case 0: // Display var 1
									switch(getButton())
									{
										case bUP:	// increment variable
											var1 += 1;
										break;
										case bDOWN:
											var1 -= 1;
										break;
						
									}
								break;
								case 1:
									switch(getButton())
									{
										case bUP:	// increment variable
											var2 += 1;
										break;
										case bDOWN:
											var2 -= 1;
										break;
						
									}
								break;
								case 2:
									switch(getButton())
									{
										case bUP:	// increment variable
											var3 += 1;
										break;
										case bDOWN:
											var3 -= 1;
										break;
									}
								break;
							}
						}while(getButton() != bLEFT);
					break;
				} 
			}while(getButton() != bLEFT); // Loop until finish selecting w/ bSELECT
		break;
		case bNONE:
			// Draw data:
			lcd.setCursor(0, 0);
			lcd.print("Data:");
	
			lcd.setCursor(0, 1);
			lcd.print(var1);

			lcd.setCursor(5, 1);
			lcd.print(var2);

			lcd.setCursor(10, 1);
			lcd.print(var3);
		break;
	}

	//lcd.setCursor(0, 1);
/*
	if(getButton() == bSELECT)	// Enter modify vals in cur menu
	{
case 
		while(getButton()!=bSELEC)
		{
			switchkk
		}

	}
*/

/*
  switch(bP)
  {
    case 0:
      lcd.print("Right.");
    break;
    case 1:
      lcd.print("Up.");
    break;
    case 2:
      lcd.print("Down.");
    break;
    case 3:
      lcd.print("Left.");
    break;
    case 4:
      lcd.print("Select.");
    break;
    case 5:
      lcd.print("None.");
    break;
  }
*/
}

