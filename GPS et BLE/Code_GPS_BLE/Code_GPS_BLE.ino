//1. Includes necessary libraries for BLE and GPS functionality.

#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>
#include <BLE2902.h>
#include <TinyGPSPlus.h>
#include <SoftwareSerial.h>

//2. Defines various UUIDs for BLE characteristics.

#define SERVICE_UUID          "4fafc201-1fb5-459e-8fcc-c5c9c331914b"  // Define the UUID for the BLE service
#define CHARACTERISTIC_UUID   "beb5483e-36e1-4688-b7f5-ea07361b26a8"  // Define the UUID for the BLE characteristic
#define CODEPARTY_UUID        "d8ad52e7-f1ca-4ece-8d54-5503caa52300"  // Define the UUID for the group code characteristic
#define LAT_UUID              "59a8c4a1-1d1e-4422-bfe6-244e6e701ff9"  // Define the UUID for the latitude characteristic
#define LONG_UUID             "515756e8-b9ba-41b7-bb29-e7b006f25a9d"  // Define the UUID for the longitude characteristic
#define UTILISATEUR_UUID      "827c47fd-74aa-4cdd-ad85-81ebb39c04d8"  // Define the UUID for the user name characteristic

//3. Initializes variables and flags for BLE connection status, GPS data, and user information.

BLEServer* pServer =                  NULL;  // Pointer to the BLE server instance
BLECharacteristic* pCharacteristic =  NULL;  // Pointer to the BLE characteristic instance
BLECharacteristic* pCodeParty =       NULL;  // Pointer to the group code characteristic instance
BLECharacteristic* pLat =             NULL;  // Pointer to the latitude characteristic instance
BLECharacteristic* pLong =            NULL;  // Pointer to the longitude characteristic instance
BLECharacteristic* pUtilisateur =     NULL;  // Pointer to the user name characteristic instance

BLEDescriptor *pDescr;                        // Pointer to the BLE descriptor instance
BLE2902 *pBLE2902;                             // Pointer to the BLE2902 instance

bool deviceConnected = false;    // Flag to indicate whether a device is connected
bool oldDeviceConnected = false; // Flag to indicate previous device connection status

float longitudeval[10];  // Array to store longitude values
float latitudeval[10];   // Array to store latitude values

uint32_t numero_utilisateur = 0;  // Variable to store user ID
uint32_t code_party;               // Variable to store group code

String nom_utilisateur;                    // Variable to store user name
String Liste_nom_utilisateur[10];          // Array to store user names
int num = 0;                               // Variable to store the number of users

//4. Defines callback classes for BLE server and characteristic events.

// Callback class for BLE server events
class MyServerCallbacks: public BLEServerCallbacks {
    void onConnect(BLEServer* pServer) {
      deviceConnected = true;
    };

    void onDisconnect(BLEServer* pServer) {
      deviceConnected = false;
    }
};

// Callback class for BLE characteristic events
class CharacteristicCallBack: public BLECharacteristicCallbacks {
  bool isNumeric(String str) {
    // Check if the string contains only numeric characters
    for (size_t i = 0; i < str.length(); i++) {
      // If any character is not a digit or a minus sign (for negative numbers), return false
      if (!isdigit(str.charAt(i)) && str.charAt(i) != '-') {
        return false;
      }
    }
    // If all characters are digits or minus sign, return true
    return true;
  }
  void onWrite(BLECharacteristic *pChar) override { 
    std::string pChar2_value_stdstr = pChar->getValue();
    String pChar2_value_string = String(pChar2_value_stdstr.c_str());
    if (isNumeric(pChar2_value_string)){

      int code_user = pChar2_value_string.toInt();
      Serial.println("Code entré: " + String(code_user)); 

    }
    else 
    {


      nom_utilisateur = pChar2_value_string;

      Liste_nom_utilisateur[num]= nom_utilisateur;
      num++;

      Serial.println(nom_utilisateur); 

      code_party = random(10000, 99999);
      Serial.println("Code généré: " + code_party); 
      pCodeParty->setValue(code_party);
      pCodeParty->notify();
    }

  }

};

//5. Sets up GPS communication using SoftwareSerial and initializes BLE service, characteristics, and descriptors.
// GPS 
static const int RXPin = 46, TXPin = 45;    // Define RX and TX pins for SoftwareSerial
static const uint32_t GPSBaud = 9600;       // Define baud rate for GPS module

TinyGPSPlus gps;                            // Instance of TinyGPSPlus for parsing GPS data

SoftwareSerial GPSSerial(RXPin, TXPin);    // SoftwareSerial instance for GPS communication


void setup()
{
  //6. Starts the BLE service and advertising.
  Serial.begin(115200);  // Initialize serial communication
  GPSSerial.begin(GPSBaud);  // Initialize SoftwareSerial for GPS communication

  // Create the BLE Device
  BLEDevice::init("ESP32");

  // Create the BLE Server
  pServer = BLEDevice::createServer();
  pServer->setCallbacks(new MyServerCallbacks());

  // Create the BLE Service
  BLEService *pService = pServer->createService(SERVICE_UUID);

  // Create BLE characteristics for various data types
  // Create a BLE Characteristic
  pCharacteristic = pService->createCharacteristic(
                      CHARACTERISTIC_UUID,
                      BLECharacteristic::PROPERTY_NOTIFY
                    );                   

  // Create a BLE Code
  pCodeParty = pService->createCharacteristic(
                      CODEPARTY_UUID,
                      BLECharacteristic::PROPERTY_NOTIFY
                    );                   



  // Create a BLE Lat
  pLat = pService->createCharacteristic(
                      LAT_UUID,
                      BLECharacteristic::PROPERTY_NOTIFY
                    );        
                    
  // Create a BLE Long
  pLong = pService->createCharacteristic(
                      LONG_UUID,
                      BLECharacteristic::PROPERTY_NOTIFY
                    );                        

  // Create a BLE Utilisateur
  pUtilisateur = pService->createCharacteristic(
                      UTILISATEUR_UUID,
                      BLECharacteristic::PROPERTY_READ |
                      BLECharacteristic::PROPERTY_WRITE
                    );    


  // Create BLE descriptor and set notifications
  pDescr = new BLEDescriptor((uint16_t)0x2901);
  pDescr->setValue("A very interesting variable");
  pCharacteristic->addDescriptor(pDescr);
  
  pBLE2902 = new BLE2902();
  pBLE2902->setNotifications(true);

  pCharacteristic->addDescriptor(pBLE2902);
  pCodeParty->addDescriptor(pBLE2902);


  pLat->addDescriptor(pBLE2902);
  pLong->addDescriptor(pBLE2902);
  

  pUtilisateur->addDescriptor(new BLE2902());
  pUtilisateur->setCallbacks(new CharacteristicCallBack());

  


  // Start the service
  pService->start();

  // Start advertising
  BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
  pAdvertising->addServiceUUID(SERVICE_UUID);
  pAdvertising->setScanResponse(false);
  pAdvertising->setMinPreferred(0x0);  // set value to 0x00 to not advertise this parameter
  BLEDevice::startAdvertising();
  Serial.println("Waiting a client connection to notify...");
}

void loop()
{
  // Parse GPS data
  //7. Parses GPS data and notifies connected devices with user information and GPS coordinates.
  while (GPSSerial.available() > 0)
    if (gps.encode(GPSSerial.read()))
      displayInfo();

    // Check if a device is connected
    if (deviceConnected) {
      // Variable to control whether to use simulated data or real GPS data
      int test=1;
      if (test==1){
        // Simulated data for testing
        Liste_nom_utilisateur[1] = "Bob";
        longitudeval[1] = 1.918939;
        latitudeval[1] = 47.845010;
        Liste_nom_utilisateur[2] = "Eve";
        longitudeval[2] = 1.918989;
        latitudeval[2] = 47.845500;
      }
        
      for(int i = 0; i < num; i++){
        // Notify user ID and user name
        numero_utilisateur=i+1;
        pCharacteristic->setValue(numero_utilisateur);
        pCharacteristic->notify();
        Serial.println(Liste_nom_utilisateur[i]+numero_utilisateur);
        pUtilisateur->setValue(std::string(Liste_nom_utilisateur[i].c_str()));
        pUtilisateur->notify();
        
        delay(100);

        // Notify longitude
        longitudeval[0] = gps.location.lng(), 6;
        Serial.println(longitudeval[i]);
        pLong->setValue(longitudeval[i]);
        pLong->notify();

        delay(100);
        Serial.println("-------------");

        // Notify latitude
        latitudeval[0] = gps.location.lat(), 6;
        Serial.println(latitudeval[i]);
        pLat->setValue(latitudeval[i]);
        pLat->notify();
        
        Serial.println("-------------");
        delay(1000);
      }
    }

    // Handle device connection and disconnection events
    if (!deviceConnected && oldDeviceConnected) {
        delay(500); // give the bluetooth stack the chance to get things ready
        pServer->startAdvertising(); // restart advertising
        Serial.println("start advertising");
        oldDeviceConnected = deviceConnected;
    }
    // connecting
    if (deviceConnected && !oldDeviceConnected) {
        // do stuff here on connecting
        oldDeviceConnected = deviceConnected;
    }

  // Check if GPS module is not detected
  if (millis() > 5000 && gps.charsProcessed() < 10)
  {
    Serial.println(F("No GPS detected: check wiring."));
    while(true);
  }
}

// Function to display GPS information
void displayInfo()
{
  Serial.print(F("Location: ")); 
  if (gps.location.isValid())
  {
    Serial.print(gps.location.lat(), 6);
    Serial.print(F(","));
    Serial.print(gps.location.lng(), 6);
  }
  else
  {
    Serial.print(F("INVALID"));
  }

  Serial.print(F("  Date/Time: "));
  if (gps.date.isValid())
  {
    Serial.print(gps.date.month());
    Serial.print(F("/"));
    Serial.print(gps.date.day());
    Serial.print(F("/"));
    Serial.print(gps.date.year());
  }
  else
  {
    Serial.print(F("INVALID"));
  }

  Serial.print(F(" "));
  if (gps.time.isValid())
  {
    if (gps.time.hour() < 10) Serial.print(F("0"));
    Serial.print(gps.time.hour());
    Serial.print(F(":"));
    if (gps.time.minute() < 10) Serial.print(F("0"));
    Serial.print(gps.time.minute());
    Serial.print(F(":"));
    if (gps.time.second() < 10) Serial.print(F("0"));
    Serial.print(gps.time.second());
    Serial.print(F("."));
    if (gps.time.centisecond() < 10) Serial.print(F("0"));
    Serial.print(gps.time.centisecond());
  }
  else
  {
    Serial.print(F("INVALID"));
  }

  Serial.println();
}

