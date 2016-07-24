// Example testing sketch for various DHT humidity/temperature sensors
// Written by ladyada, public domain

//#include "DHT.h"
//
//// Temperature sensors
//#define DHTout 2     // Outside sensor
//#define DHTins 3     // Inside sensor
//#define DHTTYPE DHT11   // DHT 11

// PIR sensor inside

int Switch_Comedor = 10;   // override swith for R_Comedor

int R_comedor = 6;
int PIRins = 4;
int motion1Detect= 0;
int manual1Switch = 0;

// PIR sensor outside

int Switch_Galeria = 11;   // override swith for R_Galeria

int R_Galeria = 7;
int PIRout = 5;
int motion2Detect= 0;
int manual2Switch = 0;

int Switch_Perim = 12;   // override swith for R_Perim

int R_Perim = 8;
int manual3Switch = 0;



// NOTE: If using a board with 3.3V logic like an Arduino Due connect pin 1
// to 3.3V instead of 5V!

//DHT dhtout(DHTout, DHTTYPE);
//DHT dhtins(DHTins, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("DHTxx test!");
//
//  dhtout.begin();
//  dhtins.begin();


// PIR sensor inside
pinMode(R_comedor, OUTPUT);
pinMode(PIRins, INPUT);
pinMode(Switch_Comedor, INPUT);
digitalWrite(R_comedor, HIGH);

// PIR sensor outside
pinMode(R_Galeria, OUTPUT);
pinMode(PIRout, INPUT);
pinMode(Switch_Galeria, INPUT);
digitalWrite(R_Galeria, HIGH);

pinMode(R_Perim, OUTPUT);
pinMode(Switch_Perim, INPUT);
digitalWrite(R_Perim, HIGH);

}

void loop() {
//  delay(2000); // Wait a few seconds between measurements.

//
//  float h_out = dhtout.readHumidity();
//  float h_ins = dhtins.readHumidity();
//  // Read temperature as Celsius (the default)
//  float t_out = dhtout.readTemperature();
//  float t_ins = dhtins.readTemperature();
//
//  if (isnan(h_out) || isnan(t_out) || isnan(h_ins) || isnan(t_ins)) {
//    Serial.println("Failed to read from DHT sensor!");
//    return;
//  }
//


//// Temperature sensor
//  Serial.print("Outside Humidity: ");
//  Serial.print(h_out);
//  Serial.print(" %\t");
//  Serial.print("Ourside Temperature: ");
//  Serial.print(t_out);
//  Serial.print(" *C \t");
//    Serial.print("Outside Humidity: ");
//  Serial.print(h_ins);
//  Serial.print(" %\t");
//  Serial.print("Ourside Temperature: ");
//  Serial.print(t_ins);
//  Serial.println(" *C \t");

// PIR Sensor inside

manual1Switch = digitalRead (Switch_Comedor);

motion1Detect = digitalRead(PIRins);
if (motion1Detect == HIGH)
     {
     digitalWrite(R_comedor, LOW);
     // delay (180000); //Optional 3 minute delayed off
     // digitalWrite(R_comedor, LOW);
     } 

else if (manual1Switch == HIGH) // Manual On
{
  digitalWrite(R_comedor, LOW);
}
else // Manual Off

{
  digitalWrite(R_comedor, HIGH);
}

// PIR Sensor outside

manual2Switch = digitalRead (Switch_Galeria);

motion2Detect = digitalRead(PIRout);
if (motion2Detect == HIGH)
     {
     digitalWrite(R_Galeria, LOW);
     // delay (180000); //Optional 3 minute delayed off
     // digitalWrite(R_comedor, LOW);
     } 

else if (manual2Switch == HIGH) // Manual On
{
  digitalWrite(R_Galeria, LOW);
}
else // Manual Off

{
  digitalWrite(R_Galeria, HIGH);
}

manual3Switch = digitalRead(Switch_Perim);

if (manual3Switch == HIGH) // Manual On
{
  digitalWrite(R_Perim, LOW);
}
else // Manual Off

{
  digitalWrite(R_Perim, HIGH);
}


////

////


}
