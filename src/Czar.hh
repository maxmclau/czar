#ifndef _CZAR_HH_
#define _CZAR_HH_

//#define DEBUG
#ifdef DEBUG
#  define D(x) x
#else
#  define D(x)
#endif

#include <Arduino.h>

#include <lwm/sys/sysConfig.h>
#include <lwm/phy/phy.h>
#include <lwm/hal/hal.h>
#include <lwm/sys/sys.h>
#include <lwm/nwk/nwk.h>
#include <lwm/sys/sysTimer.h>
#include <lwm/phy/atmegarfr2.h>

class CzarController {

  public:
    CzarController();
    ~CzarController();

    void setup();
    void loop();

  protected:
    // Name of the sketch (e.g. "Bootstrap")
    const char *sketchName;
};

extern CzarController Czar;

#endif
