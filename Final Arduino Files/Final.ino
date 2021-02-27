#include <MQ2.h>

#include <DHT.h>


#include <Wire.h> 
     

// Uncomment whatever type you're using!
#define DHTTYPE DHT11   // DHT 11 
#define flame_sensor A1
#define vibration A3
#define DHTPIN A0
#define mq A2
#define air_quality A4
int vib;
int val;
int flame_detected;
int a=1, b=0;
int gas_value;
int lpg, co, smoke;
MQ2 mq2(mq);
DHT dht(DHTPIN, DHTTYPE);

String M;
String A;
String N;
String S;
String I;
String Total;
 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
    pinMode(vibration,INPUT);
    pinMode(flame_sensor, INPUT);
    pinMode(flame_sensor, INPUT);
    pinMode(air_quality,INPUT);
    dht.begin();
    mq2.begin();


    

}

void loop() {
  // put your main code here, to run repeatedly:
     //---------------------------------------------------------------------------------------Vibration-------------------------------------------------------------------------------------

  val=digitalRead(vibration);
   vib= vibrate();
   //---------------------------------------------------------------------------------------DHT-------------------------------------------------------------------------------------
 // Wait a few seconds between measurements.
//  delay(2000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
   //---------------------------------------------------------------------------------------IRFflame-------------------------------------------------------------------------------------
  flame_detected = digitalRead(flame_sensor);
  int fire=flame();
   //---------------------------------------------------------------------------------------MQ135-------------------------------------------------------------------------------------
gas_value=analogRead(air_quality);


   //---------------------------------------------------------------------------------------MQ22-------------------------------------------------------------------------------------
float* values= mq2.read(false); //set it false if you don't want to print the values in the Serial
  lpg = mq2.readLPG();
  
  
 
  
  co = mq2.readCO();
  
  smoke = mq2.readSmoke();
  
delay(2000);
   //---------------------------------------------------------------------------------------Converting To String-------------------------------------------------------------------------------------
M=String(vib);
A=String(h);
N=String(t);
S=String(fire);
I=String(gas_value);
String R=",";
Serial.print(R);
Serial.print(M);
Serial.print(R);
Serial.print(A);
Serial.print(R);
Serial.print(N);
Serial.print(R);
Serial.print(S);
Serial.print(R);
Serial.print(I);
Serial.print(R);
Serial.print(lpg);
Serial.print(R);
Serial.print(co);
Serial.print(R);
Serial.print(smoke);
Serial.print(R);
Serial.println();
/*
Total=M+R+A+R+N+R+S+R+I+R+lpg1+R+co1+R+smoke1;
Serial.println(Total);
*/

}

int vibrate(){
 
  if(val==1)
  {
    return a;
   }
   else{
    return b;
    }
 
  }
  int flame()
  {
    if (flame_detected == 0)
  {
    return a;
  }
  else
  {
    return b;
  }
  
    }
