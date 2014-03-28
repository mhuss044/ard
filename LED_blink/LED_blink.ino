/*
	Blink an LED
*/

int menuState = 0;// 0; var1; 1; var2, 2; var3, 4; displayData

void setup() 
{
	pinMode(2, OUTPUT);
}

void loop() 
{
  //lcd.print(millis()/1000);

	delay(1000);
	digitalWrite(2, HIGH);
	delay(1000);
	digitalWrite(2, LOW);
}

