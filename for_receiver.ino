//Include Libraries
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

//create an RF24 object
RF24 radio(9, 8);  // CE, CSN
unsigned long t;
//address through which two modules communicate.
const byte address[6] = "julia";

void setup()
{
  pinMode(5, OUTPUT);//define pin5 an output
  while (!Serial);
  Serial.begin(9600);

  //Serial.println("Start");

  radio.begin();

  //set the address
  radio.openReadingPipe(0, address);

  //Set module as receiver
  radio.startListening();
}

void loop()
{
  //Read the data if available in buffer
  if (radio.available())
  {
    char text[32] = {0};
    radio.read(&text, sizeof(text));
    Serial.println(text);
    t = millis();//define the variable t
  }

  if (millis() - t > 45000) {//if the time is over 45000ms, the transpistor gets on with 255 and wait 5s and gets off.

    analogWrite(5, 255);
    delay(5000);
    analogWrite(5, 0);
  }
  else if (millis() - t > 35000) { //if the time is over 35000ms, the transpistor gets on with 255 and wait 5s and gets off.
    analogWrite(5, 220);
    delay(5000);
    analogWrite(5, 0);
  }
  else if (millis() - t > 25000) { //if the time is over 25000ms, the transpistor gets on with 255 and wait 5s and gets off.
    analogWrite(5, 190);
    delay(5000);
    analogWrite(5, 0);
  }
  else if (millis() - t > 15000) { //if the time is over 15000ms, the transpistor gets on with 255 and wait 5s and gets off.
    analogWrite(5, 160);
    delay(5000);
    analogWrite(5, 0);
  }
  else if (millis() - t > 5000) { //if the time is over 5000ms, the transpistor gets on with 255 and wait 5s and gets off.
    analogWrite(5, 130);
    delay(5000);
    analogWrite(5, 0);
  }
  Serial.println(millis() - t); //show the result of the time on the screen
}
