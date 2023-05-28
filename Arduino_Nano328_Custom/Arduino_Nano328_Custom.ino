#include <SPI.h>
#include <Wire.h>
#include <EEPROM.h>
#include <Servo.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

Adafruit_BME280 bme;

//Include Device Specific Header From Sketch>>Import Library (In This Case LinxChipkitMax32.h)
//Also Include Desired LINX Listener From Sketch>>Import Library (In This Case LinxSerialListener.h)
#include <LinxArduinoNano328.h>
#include <LinxSerialListener.h>
 
//Create A Pointer To The LINX Device Object We Instantiate In Setup()
LinxArduinoNano328* LinxDevice;

//Initialize LINX Device And Listener
int BME280_data();
void setup()
{
  bme.begin(0x77);
  //Instantiate The LINX Device
  LinxDevice = new LinxArduinoNano328();
  
  //The LINXT Listener Is Pre Instantiated, Call Start And Pass A Pointer To The LINX Device And The UART Channel To Listen On
  LinxSerialConnection.Start(LinxDevice, 0);
  LinxSerialConnection.AttachCustomCommand(1, BME280_data);  
}
void loop()
{
  //Listen For New Packets From LabVIEW
  LinxSerialConnection.CheckForCommands();
  
  //Your Code Here, But It will Slow Down The Connection With LabVIEW
}

int BME280_data (unsigned char numInputBytes, unsigned char* input, unsigned char* numResponseBytes, unsigned char* response)
{
  *numResponseBytes = 2;
  
  byte bme_temp_array1 = (byte)bme.readTemperature();
  byte bme_humi_array2 = (byte)bme.readHumidity();
  response[0] = bme_temp_array1;
  response[1] = bme_humi_array2;
  return 0;
  } 

  class Ato{
    int a =3;
  };
