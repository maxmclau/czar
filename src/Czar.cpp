#include <Arduino.h>

#include <Czar.hh>

CzarController Czar;

CzarController::CzarController() {
}

CzarController::~CzarController() { }

void CzarController::setup() {
  SYS_Init();

  Serial.begin( 115200 );
}

void CzarController::loop() {
  SYS_TaskHandler();
}