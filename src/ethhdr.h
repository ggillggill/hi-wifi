#pragma once
#include "mac.h"
/*
 *  Ethernet II header
 *  Static header size: 14 bytes
 */
#pragma pack(push,1)
struct ethernet_hdr
{
    Mac dmac_;
    Mac smac_;
    uint16_t ether_type;                 /* protocol */
};

#pragma pack(pop)


