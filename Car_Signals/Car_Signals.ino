/*
	Blink an LED
*/
int headLights = 0, emerg = 0, lLeft = 0, lRight = 0;

void readInput()
{
	lRight = digitalRead(10);	// Right Signal

	lLeft = digitalRead(13);	// Left Signal

	headLights = digitalRead(11);	// Headlights

	emerg = digitalRead(12);	// Emergency
}

void resetLEDs()
{
	digitalWrite(2, LOW);
	digitalWrite(5, LOW);
	
	digitalWrite(3, LOW);
	digitalWrite(4, LOW);
	digitalWrite(7, LOW);
	digitalWrite(8, LOW);

	digitalWrite(3, LOW);
	digitalWrite(8, LOW);

	digitalWrite(4, LOW);
	digitalWrite(7, LOW);
}

void turnOffLEDs()
{
	if(headLights)
	{
		digitalWrite(2, LOW);
		digitalWrite(5, LOW);
	}

	if(emerg)
	{
		digitalWrite(3, LOW);
		digitalWrite(4, LOW);
		digitalWrite(7, LOW);
		digitalWrite(8, LOW);
	}


	if(lLeft)
	{
		digitalWrite(3, LOW);
		digitalWrite(8, LOW);
	}	

	if(lRight)
	{
		digitalWrite(4, LOW);
		digitalWrite(7, LOW);
	}
}

void turnOnLEDs()
{
	if(headLights)
	{
		digitalWrite(2, HIGH);
		digitalWrite(5, HIGH);
	}

	if(emerg)
	{
		digitalWrite(3, HIGH);
		digitalWrite(4, HIGH);
		digitalWrite(7, HIGH);
		digitalWrite(8, HIGH);
	}


	if(lLeft)
	{
		digitalWrite(3, HIGH);
		digitalWrite(8, HIGH);
	}	

	if(lRight)
	{
		digitalWrite(4, HIGH);
		digitalWrite(7, HIGH);
	}	
}

void blinkLights()
{
	if(headLights)	
		turnOnLEDs();
	else
		turnOffLEDs();

	if(emerg)	
	{
		turnOnLEDs();
		delay(500);	
		turnOffLEDs();
	}
        else
                turnOffLEDs();

	if(lLeft)	
	{
		turnOnLEDs();
		delay(500);	
		turnOffLEDs();
	}
        else
                turnOffLEDs();
                
	if(lRight)	
	{
		turnOnLEDs();
		delay(500);	
		turnOffLEDs();
	}
        else
                turnOffLEDs();
}

void setup() 
{
	pinMode(10, INPUT);	// Right Signal
	pinMode(13, INPUT);	// Left Signal
	pinMode(11, INPUT);	// Headlights 
	pinMode(12, INPUT);	// Emergency

	pinMode(2, OUTPUT);	// Headlight Left
	pinMode(3, OUTPUT);	// Signal Left
	pinMode(4, OUTPUT);	// Signal Right
	pinMode(5, OUTPUT);	// Headlight Right
//	pinMode(6, OUTPUT);	// 
	pinMode(7, OUTPUT);	// Signal Right
	pinMode(8, OUTPUT);	// Signal Left
}

void loop() 
{
// millis()/1000;
	readInput();
	//blinkLights();
	//resetLEDs();
	if(headLights)
	{
		digitalWrite(2, HIGH);
		digitalWrite(5, HIGH);
	}
	else
	{
		digitalWrite(2, LOW);
		digitalWrite(5, LOW);
	}

	if(emerg)
	{
		digitalWrite(3, HIGH);
		digitalWrite(4, HIGH);
		digitalWrite(7, HIGH);
		digitalWrite(8, HIGH);
                delay(500);
                digitalWrite(3, LOW);
		digitalWrite(4, LOW);
		digitalWrite(7, LOW);
		digitalWrite(8, LOW);
                delay(500);
	}
	else
	{
		digitalWrite(3, LOW);
		digitalWrite(4, LOW);
		digitalWrite(7, LOW);
		digitalWrite(8, LOW);
	}


	if(lLeft)
	{
		digitalWrite(3, HIGH);
		digitalWrite(8, HIGH);
	        delay(500);
                digitalWrite(3, LOW);
		digitalWrite(8, LOW);
                delay(500);
        }
	else
	{
		digitalWrite(3, LOW);
		digitalWrite(8, LOW);
	}	

	if(lRight)
	{
		digitalWrite(4, HIGH);
		digitalWrite(7, HIGH);
                delay(500);
                digitalWrite(4, LOW);
		digitalWrite(7, LOW);
                delay(500);
	}
	else
	{
		digitalWrite(4, LOW);
		digitalWrite(7, LOW);
	}

//	delay(300);
}

