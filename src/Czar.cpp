#include <Arduino.h>

#include <Czar.hh>

Czar::Czar() {
}

Czar::~Czar() { }

void Czar::setup() {
  SYS_Init();
  PHY_RandomReq();

  Serial.begin( 115200 );
}

void Czar::loop() {
  SYS_TaskHandler();
}