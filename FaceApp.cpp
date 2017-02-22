#include "FaceApp.h"


FaceApp::FaceApp(HardwareSerial &uart, uint32_t baud): m_puart(&uart)
{
  _baud = baud;
  _valid = false;
}

void FaceApp::begin(void)
{
  m_puart->begin(_baud);
  while (m_puart->available() > 0)
  {
    m_puart->read();
  }
}

bool FaceApp::valid(void)
{
  return _valid;
}

void FaceApp::routine(void)
{
  while (m_puart->available() > 0)
  {
    char nullByte = char(m_puart->read());
    if (nullByte == '\n')
    {
      comdata[data_p] = nullByte;
      data_p = 0;

      if ((char)comdata[0] == 'A')
      {
        strtok(comdata, ",");
        dataRoll = atof(strtok(NULL, ","));
        dataYaw = atof(strtok(NULL, ","));
        dataPitch = atof(strtok(NULL, ","));
        dataFace= atoi(strtok(NULL, ","));
        dataX = atoi(strtok(NULL, ","));
        dataY = atoi(strtok(NULL, ";"));
        _valid = true;
      }
      else
      {
        _valid = false;
      }
    }
    else
    {
      comdata[data_p] = nullByte ;
      data_p++ ;
    }
  }
}

int FaceApp::getX(void)
{
  return dataX;
}

int FaceApp::getY(void)
{
  return dataY;
}

int FaceApp::getFace(void)
{
  return dataFace;
}

float FaceApp::getRoll(void)
{
  return dataRoll;
}

float FaceApp::getYaw(void)
{
  return dataYaw;
}

float FaceApp::getPitch(void)
{
  return dataPitch;
}
