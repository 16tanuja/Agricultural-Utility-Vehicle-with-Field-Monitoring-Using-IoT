#define BLYNK_TEMPLATE_ID "TMPL3_TvbxzJB"
#define BLYNK_TEMPLATE_NAME "Agri vehicle"
#define BLYNK_AUTH_TOKEN "NbFkjjOkRlVlHKWtSO1tukMBWgRFToKx"
#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
//#include <ESP32Servo.h>


 
char auth[] = BLYNK_AUTH_TOKEN; 
 


char ssid[] = "kpi";
char pass[] = "12345678";

BlynkTimer timer;
#define soilPin 18 
int fw1=32;
int bw1=33;
int fw2=25;
int bw2=26;


int cut=23;
int pump=14;

void setup() 
{
 
Serial.begin(115200);
   WiFi.begin(ssid, pass);
   
  int wifi_ctr = 0;
  while (WiFi.status() != WL_CONNECTED)
  {
  delay(500);
  Serial.print(".");
  }
  Serial.println("WiFi connected");
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);

pinMode(fw1,OUTPUT);
pinMode(bw1,OUTPUT);
pinMode(fw2,OUTPUT);
pinMode(bw2,OUTPUT);
pinMode(soilPin,INPUT);
pinMode(pump,OUTPUT);
 
pinMode(cut,OUTPUT);

digitalWrite(cut,HIGH);

 

void loop() {
  
  
Blynk.run();
 soilMoisture();
}
 void soilMoisture(){
  int soilMoisture = digitalRead(soilPin);
 if (soilMoisture==0) {  // If soil is dry AND no rain
    digitalWrite(pump, HIGH);  // Turn ON the water pump
  } else {
    digitalWrite(pump, LOW);  // Turn OFF the water pump
  }
  }


BLYNK_WRITE(V0)
{
  int pinstate1=param.asInt();
  if(pinstate1==1)
  {
    digitalWrite(fw1,HIGH);
    digitalWrite(fw2,HIGH);
    digitalWrite(bw1,LOW);
  digitalWrite(bw2,LOW);
  }
  else
   
 {
    digitalWrite(fw1,LOW);
    digitalWrite(fw2,LOW);
    digitalWrite(bw1,LOW);
  digitalWrite(bw2,LOW);
  }
}

 BLYNK_WRITE(V1)
{
  int pinstate2=param.asInt();
  if(pinstate2==1)
  {
    digitalWrite(fw1,LOW);
    digitalWrite(fw2,LOW);
    digitalWrite(bw1,HIGH);
  digitalWrite(bw2,HIGH);
  }
  else
  { 
    digitalWrite(fw1,LOW);
    digitalWrite(fw2,LOW);
    digitalWrite(bw1,LOW);
    digitalWrite(bw2,LOW);
  }
}

 BLYNK_WRITE(V2)
{
  int pinstate3=param.asInt();
  if(pinstate3==1)
  {
    digitalWrite(fw1,HIGH);
    digitalWrite(fw2,LOW);
    digitalWrite(bw1,LOW);
  digitalWrite(bw2,HIGH);
  }
  else
  { 
    digitalWrite(fw1,LOW);
    digitalWrite(fw2,LOW);
    digitalWrite(bw1,LOW);
    digitalWrite(bw2,LOW);
  }
}

 
BLYNK_WRITE(V3)
{
  int pinstate9=param.asInt();
  if(pinstate9==1)
  {
    digitalWrite(fw1,LOW);
    digitalWrite(fw2,HIGH);
    digitalWrite(bw1,HIGH);
  digitalWrite(bw2,LOW);
  }
  else
   
 {
    digitalWrite(fw1,LOW);
    digitalWrite(fw2,LOW);
    digitalWrite(bw1,LOW);
  digitalWrite(bw2,LOW);
  }
}


BLYNK_WRITE(V4)
{
  int pinstate6=param.asInt();
  if(pinstate6==1)
  {
    digitalWrite(cut,HIGH);
  }
  else
 {
    digitalWrite(cut,LOW);
  }
}
