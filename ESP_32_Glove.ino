
#include "BluetoothSerial.h" //Header File for Serial Bluetooth, will be added by default into Arduino

BluetoothSerial ESP_BT; //Object for Bluetooth

int incoming;

// Peltier 1 
int M1P1 = 12; 
int M1P2 = 13;
// Peltier 2
int M2P1 = 27; 
int M2P2 = 14; 
// Peltier 3 
int M3P1 = 26; 
int M3P2 = 25;
// Peltier  4
int M4P1 = 33; 
int M4P2 = 32;
// Peltier 5 
int M5P1 = 19; 
int M5P2 = 21;


void setup() {
  // sets the pins as outputs:
    // P1 
    pinMode(M1P1, OUTPUT);
    pinMode(M1P2, OUTPUT);
    // P2 
    pinMode(M2P1, OUTPUT);
    pinMode(M2P2, OUTPUT);
    // P3 
    pinMode(M3P1, OUTPUT);
    pinMode(M3P2, OUTPUT);
    // P4 
    pinMode(M4P1, OUTPUT);
    pinMode(M4P2, OUTPUT);
    // P5 
    pinMode(M5P1, OUTPUT);
    pinMode(M5P2, OUTPUT);
  

  Serial.begin(115200);
  ESP_BT.begin("VR_Gloves"); //Name of your Bluetooth Signal
  Serial.println("Bluetooth Device is Ready to Pair");
}

void loop() {

  if (ESP_BT.available()) //Check if we receive anything from Bluetooth
  {
    incoming = ESP_BT.read(); //Read what we recevive 
    Serial.print("Received:"); Serial.println(incoming);

    if (incoming == 49) // 1 - Hot
        {
        digitalWrite(M1P1, LOW);
        digitalWrite(M1P2, HIGH); 
        digitalWrite(M2P1, LOW);
        digitalWrite(M2P2, HIGH); 
        digitalWrite(M3P1, LOW);
        digitalWrite(M3P2, HIGH); 
        digitalWrite(M4P1, LOW);
        digitalWrite(M4P2, HIGH); 
        digitalWrite(M5P1, LOW);
        digitalWrite(M5P2, HIGH); 
        }
        
    if (incoming == 48) // 0 - Stop 
        {
        digitalWrite(M1P1, LOW);
        digitalWrite(M1P2, LOW); 
        digitalWrite(M2P1, LOW);
        digitalWrite(M2P2, LOW); 
        digitalWrite(M3P1, LOW);
        digitalWrite(M3P2, LOW); 
        digitalWrite(M4P1, LOW);
        digitalWrite(M4P2, LOW); 
        digitalWrite(M5P1, LOW);
        digitalWrite(M5P2, LOW); 
        } 
    if (incoming == 50) // 2 - Cold 
        {
        digitalWrite(M1P2, LOW);
        digitalWrite(M1P1, HIGH); 
        digitalWrite(M2P2, LOW);
        digitalWrite(M2P1, HIGH); 
        digitalWrite(M3P2, LOW);
        digitalWrite(M3P1, HIGH); 
        digitalWrite(M4P2, LOW);
        digitalWrite(M4P1, HIGH); 
        digitalWrite(M5P2, LOW);
        digitalWrite(M5P1, HIGH); 
        } 
  }
  delay(20);
}