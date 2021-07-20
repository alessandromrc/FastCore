#include <FastCore.h>

void setup()
{
  Serial.begin(9600);
  pinMode(9, OUTPUT);
}


FastCore Writer;

void loop()
{
  int initial = 0;
  int final = 0;
  initial = micros();

  for (int i = 0; i < 500; i++)
  {
    Writer.FastWrite(9, HIGH);
    Writer.FastWrite(9, LOW);
  }

  final = micros();
  Serial.print("Time for custom digitalwrite: ");
  Serial.print(final - initial);
  Serial.println(" us");

  initial = micros();

  for (int i = 0; i < 500; i++)
  {
    digitalWrite(9, HIGH);
    digitalWrite(9, LOW);
  }

  final = micros();
  Serial.print("Time for original digitalwrite: ");
  Serial.print(final - initial);
  Serial.println(" us");
  while (1);
}
