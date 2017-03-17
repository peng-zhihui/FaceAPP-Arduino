#ifndef FaceApp_h
#define FaceApp_h
#include "Arduino.h"
#include <inttypes.h>
#include <SoftwareSerial.h>

class FaceApp
{
  public:
    FaceApp(SoftwareSerial &uart, uint32_t baud = 9600);

    int getX(void);
    int getY(void);
    int getFace(void);
    float getRoll(void);
    float getYaw(void);
    float getPitch(void);
    void begin(void);
    void routine(void);
    bool valid(void);
  private:
  	SoftwareSerial *m_puart;
    char comdata[100], data_p; 
    int  dataX, dataY, dataFace;
    float dataRoll,dataYaw,dataPitch;
    uint32_t _baud;
    bool _valid;
};

#endif
