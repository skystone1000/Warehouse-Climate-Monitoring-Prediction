float temp;
void setup() 
{
  Serial.begin(9600);
}

void loop() {
  temp = analogRead(A0);
  Serial.print("Temperature = ");
  Serial.print(temp);
  Serial.println();
  delay(1000);
}
