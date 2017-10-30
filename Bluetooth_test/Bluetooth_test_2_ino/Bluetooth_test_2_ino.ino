char value;
int ledpin = 13;


void setup()

{
pinMode(ledpin, OUTPUT);
Serial.begin(9600);
}


void loop()

{
if(Serial.available())
{;}

value = Serial.read();

if( value == 'X' )
{

digitalWrite(ledpin, LOW);
Serial.println("LEDOFF");
}

if (value == 'x' )
{
digitalWrite(ledpin, HIGH);
Serial.println("LEDON");

}

}
