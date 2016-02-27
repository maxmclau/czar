#ifndef _CZAR_H_
#define _CZAR_H_

#include <Arduino.h>

#include <lwm.h>
#include "lwm/phy/phy.h"
#include "lwm/hal/hal.h"
#include "lwm/sys/sys.h"
#include "lwm/nwk/nwk.h"

#ifdef PHY_ATMEGARFR2
  #include "lwm/phy/atmegarfr2.h"
#endif // PHY_ATMEGARFR2

struct CzarConfiguration {
  uint16_t groupAddress = 0xFFFF;
  uint8_t dataRate = 0;
  uint8_t transmitPower = 0;
  uint8_t channel = 20;
  uint16_t panId =  0xFFFF;
  uint16_t address = 0;
};

class CzarController {

  public:
    CzarController();
    ~CzarController();

    void setup(uint16_t eepromAddress, bool isVerbose);
    void loop();

    void listen(uint8_t endpoint, bool (*handler)(NWK_DataInd_t *ind));

    void joinGroup(uint16_t groupAddress);
    void leaveGroup(uint16_t groupAddress);
    bool isInGroup(uint16_t groupAddress);

    void setSecurityKey(const uint8_t *securityKey);
    void setDataRate(const uint8_t dataRate);
    void setTransmitPower(const uint8_t transmitPower);
    void setChannel(const uint8_t channel);
    void setPanId(const int16_t panId);
    void setAddress(const int16_t address);

    uint16_t getGroupAddress(void);

    uint8_t getDataRate();
    uint8_t getTransmitPower();
    int8_t getChannel();
    int16_t getPanId();
    int16_t getAddress();

    const char* getTransmitPowerDb();
    const char* getDataRateKbps();

  private:
    CzarConfiguration _configuration;
    bool _isVerbose;

    CzarConfiguration getConfigurationFromEeprom(uint16_t eepromAddress);
};

extern CzarController Czar;

#endif // _CZAR_H_
