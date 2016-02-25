#include <Arduino.h>
#include "Czar.h"

CzarController Czar;

CzarController::CzarController() {

}

CzarController::~CzarController() { }

void CzarController::setup() {
  SYS_Init();
}

void CzarController::loop() {
  SYS_TaskHandler();
}

void CzarController::listen(uint8_t endpoint, bool (*handler)(NWK_DataInd_t *ind)) {
  NWK_OpenEndpoint(endpoint, handler);
}

void CzarController::joinGroup(uint16_t groupAddress) {
  if (!isInGroup(groupAddress)) {
    NWK_GroupAdd(groupAddress);
  }
}

void CzarController::leaveGroup(uint16_t groupAddress) {
  if (isInGroup(groupAddress)) {
    NWK_GroupRemove(groupAddress);
  }
}

bool CzarController::isInGroup(uint16_t groupAddress) {
  return NWK_GroupIsMember(groupAddress);
}

void CzarController::setDataRate(const uint8_t dataRate) {
  /* Page 123 of the 256RFR2 datasheet
      0   250 kb/s  | -100 dBm
      1   500 kb/s  |  -96 dBm
      2   1000 kb/s |  -94 dBm
      3   2000 kb/s |  -86 dBm
  */
  TRX_CTRL_2_REG_s.oqpskDataRate = dataRate;
  _dataRate = dataRate;
}

void CzarController::setTransmitPower(const uint8_t transmitPower) {
  /* Page 116 of the 256RFR2 datasheet
      0   3.5 dBm
      1   3.3 dBm
      2   2.8 dBm
      3   2.3 dBm
      4   1.8 dBm
      5   1.2 dBm
      6   0.5 dBm
      7  -0.5 dBm
      8  -1.5 dBm
      9  -2.5 dBm
      10 -3.5 dBm
      11 -4.5 dBm
      12 -6.5 dBm
      13 -8.5 dBm
      14 -11.5 dBm
      15 -16.5 dBm
  */
  PHY_SetTxPower(transmitPower);
  _transmitPower = transmitPower;
}

void CzarController::setChannel(const uint8_t channel) {
  PHY_SetChannel(channel);
  _channel = channel;
}

void CzarController::setPanId(const int16_t panId) {
  NWK_SetPanId(panId);
  _panId = panId;
}

void CzarController::setAddress(const int16_t address) {
  NWK_SetAddr(address);
  _address = address;
}

uint16_t CzarController::getGroupAddress() {
  return _groupAddress;
}

uint8_t CzarController::getDataRate() {
  return _dataRate;
}

uint8_t CzarController::getTransmitPower() {
  return _transmitPower;
}

int8_t CzarController::getChannel() {
  return _channel;
}

int16_t CzarController::getPanId() {
  return _panId;
}

int16_t CzarController::getAddress() {
  return _address;
}

const char* CzarController::getTransmitPowerDb() {
  switch (_transmitPower) {
    case 0:
      return PSTR("3.5 dBm");
      break;
    case 1:
      return PSTR("3.3 dBm");
      break;
    case 2:
      return PSTR("2.8 dBm");
      break;
    case 3:
      return PSTR("2.3 dBm");
      break;
    case 4:
      return PSTR("1.8 dBm");
      break;
    case 5:
      return PSTR("1.2 dBm");
      break;
    case 6:
      return PSTR("0.5 dBm");
      break;
    case 7:
      return PSTR("-0.5 dBm");
      break;
    case 8:
      return PSTR("-1.5 dBm");
      break;
    case 9:
      return PSTR("-2.5 dBm");
      break;
    case 10:
      return PSTR("-3.5 dBm");
      break;
    case 11:
      return PSTR("-4.5 dBm");
      break;
    case 12:
      return PSTR("-6.5 dBm");
      break;
    case 13:
      return PSTR("-8.5 dBm");
      break;
    case 14:
      return PSTR("-11.5 dBm");
      break;
    case 15:
      return PSTR("-16.5 dBm");
      break;
    default:
      return PSTR("Unknown");
      break;
  }
}

const char* CzarController::getDataRateKbps() {
  switch (_dataRate) {
    case 0:
      return PSTR("250 kb/s");
      break;
    case 1:
      return PSTR("500 kb/s");
      break;
    case 2:
      return PSTR("1 Mb/s");
      break;
    case 3:
      return PSTR("2 Mb/s");
      break;
    default:
      return PSTR("Unknown");
      break;
  }
}
