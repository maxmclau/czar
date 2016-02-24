#ifndef _CZAR_H_
#define _CZAR_H_

#include <Arduino.h>

class CzarController {
  public:
    CzarController();
    ~CzarController();

    void setup();
    void loop();

  protected:
    void checkStateChange();

};

extern CzarController Czar;

#endif
