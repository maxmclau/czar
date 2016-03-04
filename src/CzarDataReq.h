// The MIT License (MIT)
// Copyright (c) 2016 Maxmillion McLaughlin

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.

#ifndef _CZAR_DATA_REQ_H
#define _CZAR_DATA_REQ_H

#define CZAR_DATA_REQ_ENDPOINT     1;

enum {
  CZAR_DATA_REQ_READING,
  CZAR_DATA_REQ_UPDATE
};

struct CzarDataPacket_t {
  uint8_t type;
};

struct CzarDataReq_t : public NWK_DataReq_t {
   CzarDataReq_t(void(*conf)(struct NWK_DataReq_t *req)) {
      dstEndpoint = CZAR_DATA_REQ_ENDPOINT;
      srcEndpoint = CZAR_DATA_REQ_ENDPOINT;
      options = NWK_OPT_ACK_REQUEST;

      confirm = conf;
   }

   CzarDataPacket_t *packet;
};

#endif // _CZAR_DATA_REQ_H
