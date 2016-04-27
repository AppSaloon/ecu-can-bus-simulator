#include <mcp_can.h>
#include <SPI.h>

MCP_CAN CAN(10);                                      // Set CS to pin 10

INT32U canId = 0x000;

unsigned char len = 0;
unsigned char buf[8];
char str[20];

String BuildMessage="";
int MSGIdentifier=0;


void setup() {
  Serial.begin(115200);

START_INIT:

    if(CAN_OK == CAN.begin(CAN_500KBPS))                   // init can bus : baudrate = 500k
    {
        Serial.println("CAN BUS Shield init ok!");
    }
    else
    {
        Serial.println("CAN BUS Shield init fail");
        Serial.println("Init CAN BUS Shield again");
        delay(100);
        goto START_INIT;
    }
}

void loop()
{
    char rndCoolantTemp=random(1,200);
    char rndRPM=random(1,55);
    char rndSpeed=random(0,255);
    char rndIAT=random(0,255);
    char rndMAF=random(0,255);
    char rndAmbientAirTemp=random(0,200);
    char rndCAT1Temp=random(1,55);
    
    //GENERAL ROUTINE
    unsigned char SupportedPID[8] =       {1,2,3,4,5,6,7,8};
    unsigned char MilCleared[7] =         {4, 65, 63, 34, 224, 185, 147}; 
    
    //SENSORS
    unsigned char CoolantTemp[7] =        {4, 65, 5, rndCoolantTemp, 0, 185, 147};  
    unsigned char rpm[7] =                {4, 65, 12, rndRPM, 224, 185, 147};
    unsigned char vspeed[7] =             {4, 65, 13, rndSpeed, 224, 185, 147};
    unsigned char IATSensor[7] =          {4, 65, 15, rndIAT, 0, 185, 147};
    unsigned char MAFSensor[7] =          {4, 65, 16, rndMAF, 0, 185, 147};
    unsigned char AmbientAirTemp[7] =     {4, 65, 70, rndAmbientAirTemp, 0, 185, 147};
    unsigned char CAT1Temp[7] =           {4, 65, 60, rndCAT1Temp, 224, 185, 147};
    unsigned char CAT2Temp[7] =           {4, 65, 61, rndCAT1Temp, 224, 185, 147};
    unsigned char CAT3Temp[7] =           {4, 65, 62, rndCAT1Temp, 224, 185, 147};
    unsigned char CAT4Temp[7] =           {4, 65, 63, rndCAT1Temp, 224, 185, 147};
    
    if(CAN_MSGAVAIL == CAN.checkReceive())  
    {
      
      CAN.readMsgBuf(&len, buf); 
        canId = CAN.getCanId();
        Serial.print("<");Serial.print(canId);Serial.print(",");
        for(int i = 0; i<len; i++)    // print the data
        {
            Serial.print(buf[i]);Serial.print("\t");
        }
        Serial.println();
        BuildMessage="";
    }
    
}
