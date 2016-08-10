#ifndef TYPES_H
#define TYPES_H

#include <stdint.h>

typedef struct {
  uint16_t id;
  uint16_t qr;
  uint16_t opcode;
  uint16_t aa;
  uint16_t tc;
  uint16_t rd;
  uint16_t rs;
  uint16_t rcode;
  uint16_t qdcount;
  uint16_t ancount;
  uint16_t nscount;
  uint16_t arcount;
} header;

typedef struct {
  header* header;
} message;

#endif
