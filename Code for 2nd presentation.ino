#define BLYNK_PRINT Serial
 
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SoftwareSerial.h>
#include <SimpleTimer.h>
 
char auth[] = "Q73mBD0LcPCXZucsHgScapeYswG4zZki";
// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "ZONG MBB-E8231-6E63";
char pass[] = "6266729584";
 
SimpleTimer timer;
 
// This function sends Arduino's up time every second to Virtual Pin (1).
// In the app, Widget's reading frequency should be set to PUSH. This means
// that you define how often to send data to Blynk App.
void myTimerEvent()
{
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V1, millis() / 1000);
  
}
 
int reed_s = D0; // Reed sensor
 
int flag = 0; 
 
void setup()
{
  // Debug console
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
 pinMode(reed_s, INPUT_PULLUP); 
  timer.setInterval(1000L,sensorvalue1); 
}
void loop()
{
  Blynk.run();
  timer.run(); // Initiates BlynkTimer   
 
}
 
void sensorvalue1()
{
 
if((digitalRead(reed_s) == LOW) && ( flag == 0  ))
{
  Blynk.virtualWrite(V2,0 ); //turns off the led
  Blynk.virtualWrite(V3,255 ); // turns on the led
 Blynk.notify("Door Closed!!!"); 
  flag = 1; 
}
 
if((digitalRead(reed_s) == HIGH) && ( flag == 1) )
{
  Blynk.virtualWrite(V2,255 ); // turns on the led
  Blynk.virtualWrite(V3,0 ); // turns off the led 
  Blynk.notify("Door Opened!!!"); 
  flag = 0; 
  
}
 
}
