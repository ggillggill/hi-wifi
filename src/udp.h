#pragma once
#pragma pack(push,1)
struct libnet_udp_hdr
{
    uint16_t uh_sport;       /* soure port */
    uint16_t uh_dport;       /* destination port */
    uint16_t uh_ulen;        /* length */
    uint16_t uh_sum;         /* checksum */
};


#pragma pack(pop)
