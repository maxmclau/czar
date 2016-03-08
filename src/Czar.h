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

#ifndef _CZAR_H
#define _CZAR_H

#include <Arduino.h>

#include "lwm/phy/phy.h"
#include "lwm/hal/hal.h"
#include "lwm/sys/sys.h"
#include "lwm/nwk/nwk.h"

#ifdef PHY_ATMEGARFR2
  #include "lwm/phy/atmegarfr2.h"
#endif // PHY_ATMEGARFR2

#include "CzarCommandReq.h"
#include "CzarDataReq.h"

class CzarController {

  public:
    CzarController();
    ~CzarController();

    void init(bool isVerbose);
    void loop();

    void listen(uint8_t endpoint, bool (*handler)(NWK_DataInd_t *ind));

    void joinGroup(uint16_t groupAddress);
    void leaveGroup(uint16_t groupAddress);
    bool isInGroup(uint16_t groupAddress);

    void setReceiverState(bool receiverState);
    void setDataRate(const uint8_t dataRate);
    void setTransmitPower(const uint8_t transmitPower);
    void setBand(const uint8_t band);
    void setChannel(const uint8_t channel);
    void setPanId(const uint16_t panId);
    void setAddress(const uint16_t address);

    uint16_t getGroupAddress(void);

    bool getReceiverState(void);
    uint8_t getDataRate(void);
    uint8_t getTransmitPower(void);
    uint8_t getBand(void);
    uint8_t getChannel(void);
    uint16_t getPanId(void);
    uint16_t getAddress(void);

    const char* getTransmitPowerDb(void);
    const char* getDataRateKbps(void);

    void appDataConf(NWK_DataReq_t *req);

  private:
		uint16_t  _groupAddress;

		bool      _receiverState;
		uint8_t   _dataRate;
		uint8_t   _transmitPower;
		uint8_t   _band;
		uint8_t   _channel;
		uint16_t  _panId;
		uint16_t  _address;

		bool _isVerbose;

};

extern CzarController Czar;

#endif // _CZAR_H

/*
    struct infoReq_t : public NWK_DataReq_t {
       infoReq_t()
       {
          dstEndpoint = 1;
          srcEndpoint = 1;
          options = NWK_OPT_ACK_REQUEST;
       }

       char  info[];
    } _infoReq;

    struct commandReq_t : public NWK_DataReq_t {
       commandReq_t()
       {
          dstEndpoint = 2;
          srcEndpoint = 2;
          options = NWK_OPT_ACK_REQUEST;
          strcpy(newVar, "Hello");

          confirm     = &commandReqConf;
       }

       uint8_t duration;

       char  newVar[20];

    } _commandReq;
*/
