int  SensorPin = A5;
int led = 7;  
float SensorOut = 0;
float SensorVo = 0;
float  Dust = 0;
float Voltage_noDust = 0.9; //value from datasheet
float  K = 0.5;             //Sensitivity from the datasheet 0.5V/ugm/m^3
int fume_disipation=  2;
double power_time = 0;

void setup()
{
  pinMode(led,OUTPUT);
  pinMode(fume_disipation,OUTPUT);
  Serial.begin(115200);
  delay(10);
  digitalWrite (fume_disipation, HIGH);
  delay(5000);
  digitalWrite (fume_disipation, LOW);

}

void loop()
{
  digitalWrite(led,LOW);          //turning on the sensor led
  delayMicroseconds(280);         //wait for 0.28ms
  SensorOut = analogRead(SensorPin);    //read the sensor output voltage
  delayMicroseconds(50);                //wait for 50us
  digitalWrite(led,HIGH);               //turning  off sensor led the led
  delayMicroseconds(9670);              //wait for (10000-280-50)=9670us
  SensorVo = SensorOut*(5.0/1024);      //calculating sensor output voltage with 5V input
  Dust = (SensorVo-Voltage_noDust)*100/K;     //calculating Dust density(ugm)/m^3
  
  if ( Dust < 0)
  {
    Dust = 0.00;
  }
Serial.println(Dust);  

if (Dust > 100){
 digitalWrite (fume_disipation, HIGH);
 power_time = millis();
}
else  {
  if ((millis() - power_time) >= 5000){
    digitalWrite (fume_disipation, LOW);
  }
 
}
}
