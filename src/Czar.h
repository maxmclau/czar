#ifndef _CZAR_H_
#define _CZAR_H_

#include <Arduino.h>
//#include <EEPROM.h>

#include <lwm.h>
#include "lwm/phy/phy.h"
#include "lwm/hal/hal.h"
#include "lwm/sys/sys.h"
#include "lwm/nwk/nwk.h"

#ifdef PHY_ATMEGARFR2
  #include "lwm/phy/atmegarfr2.h"
#endif // PHY_ATMEGARFR2

struct CzarEepromStruct {

  byte networkSecurityKey[16];

  uint8_t dataRate;
  uint8_t transmitPower;

  int8_t channel;
  int16_t panId;
  int16_t address;
};

class CzarController {

  public:
    CzarController();
    ~CzarController();

    void setup();
    void loop();

    void listen(uint8_t endpoint, bool (*handler)(NWK_DataInd_t *ind));

    void joinGroup(uint16_t groupAddress);
    void leaveGroup(uint16_t groupAddress);
    bool isInGroup(uint16_t groupAddress);

    void setDataRate(const uint8_t dataRate);
    void setTransmitPower(const uint8_t txPower);
    void setChannel(const uint8_t channel);
    void setPanId(const int16_t panId);
    void setAddress(const int16_t address);

    uint16_t getGroupAddress();

    uint8_t getDataRate();
    uint8_t getTransmitPower();
    int8_t getChannel();
    int16_t getPanId();
    int16_t getAddress();

    const char* getTransmitPowerDb();
    const char* getDataRateKbps();

  private:
    uint16_t _groupAddress;
    uint8_t _dataRate;
    uint8_t _transmitPower;
    uint8_t _channel;
    uint16_t _panId;
    uint16_t _address;
};

extern CzarController Czar;

#endif
