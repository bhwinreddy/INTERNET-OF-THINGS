void setup()
{
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(10,OUTPUT);
}

void loop()
{
  digitalWrite(13,1);
  digitalWrite(12,1);
  digitalWrite(10,1);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(13,0);
  digitalWrite(12,1);
  digitalWrite(10,1);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(13,1);
  digitalWrite(12,0);
  digitalWrite(10,1);
  delay(1000);
  digitalWrite(13,1);
  digitalWrite(12,1);
  digitalWrite(10,0);
  delay(1000);
  digitalWrite(13,0);
  digitalWrite(12,0);
  digitalWrite(10,1);
  delay(1000);
  digitalWrite(13,1);
  digitalWrite(12,0);
  digitalWrite(10,0);
  delay(1000);
  digitalWrite(13,0);
  digitalWrite(12,1);
  digitalWrite(10,0);
  delay(1000);
  
  
}