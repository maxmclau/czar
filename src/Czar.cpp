// The MIT License (MIT)
//
// Copyright (c) 2016 Maxmillion McLaughlin <maxmclau.com>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.

#include <Arduino.h>
#include "Czar.h"

CzarController Czar;

CzarController::CzarController() { }

CzarController::~CzarController() { }

void CzarController::init(bool isVerbose) {
	_isVerbose = isVerbose;

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
    NWK_Busy();
		_groupAddress = groupAddress;
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

void CzarController::setReceiverState(bool receiverState) {
  PHY_SetRxState(receiverState);
  _receiverState = receiverState;
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

void CzarController::setBand(const uint8_t band) {
	PHY_SetBand(band);
	_band = band;
}

void CzarController::setChannel(const uint8_t channel) {
  PHY_SetChannel(channel);
  _channel = channel;
}

void CzarController::setPanId(const uint16_t panId) {
  NWK_SetPanId(panId);
  _panId = panId;
}

void CzarController::setAddress(const uint16_t address) {
  NWK_SetAddr(address);
  _address = address;
}

uint16_t CzarController::getGroupAddress(void) {
  return _groupAddress;
}

bool CzarController::getReceiverState(void) {
  return _receiverState;
}

uint8_t CzarController::getDataRate(void) {
  return _dataRate;
}

uint8_t CzarController::getTransmitPower(void) {
  return _transmitPower;
}

uint8_t CzarController::getBand(void) {
  return _band;
}

uint8_t CzarController::getChannel(void) {
  return _channel;
}

uint16_t CzarController::getPanId(void) {
  return _panId;
}

uint16_t CzarController::getAddress(void) {
  return _address;
}

const char* CzarController::getTransmitPowerDb(void) {
  switch (_transmitPower) {
    case 0:
      return "3.5 dBm";
      break;
    case 1:
      return "3.3 dBm";
      break;
    case 2:
      return "2.8 dBm";
      break;
    case 3:
      return "2.3 dBm";
      break;
    case 4:
      return "1.8 dBm";
      break;
    case 5:
      return "1.2 dBm";
      break;
    case 6:
      return "0.5 dBm";
      break;
    case 7:
      return "-0.5 dBm";
      break;
    case 8:
      return "-1.5 dBm";
      break;
    case 9:
      return "-2.5 dBm";
      break;
    case 10:
      return "-3.5 dBm";
      break;
    case 11:
      return "-4.5 dBm";
      break;
    case 12:
      return "-6.5 dBm";
      break;
    case 13:
      return "-8.5 dBm";
      break;
    case 14:
      return "-11.5 dBm";
      break;
    case 15:
      return "-16.5 dBm";
      break;
    default:
      return "Unknown";
      break;
  }
}

const char* CzarController::getDataRateKbps(void) {
  switch (_dataRate) {
    case 0:
      return "250 kb/s";
      break;
    case 1:
      return "500 kb/s";
      break;
    case 2:
      return "1 Mb/s";
      break;
    case 3:
      return "2 Mb/s";
      break;
    default:
      return "Unknown";
      break;
  }
}
