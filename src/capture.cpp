#include <pcap.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stdint.h>
#include <QDebug>
#include <QString>
#include <QtGlobal>
#include "ethhdr.h"
#include "mac.h"
#include "ip.h"
#include "iphdr.h"
#include "udp.h"
#include "capture.h"

#define PACKET_SIZE (sizeof(struct DHCPPacket))
#define UDP 17
#define Ipv4 0x0800
#define SERVER 67
#define CLIENT 68




void usage() {
    printf("syntax: pcap-test <interface>\n");
    printf("sample: pcap-test wlan0\n");
}

typedef struct {
    char* dev_;
} Param;

Param param = {
    .dev_ = NULL
};

bool parse(Param* param, int argc, char* argv[]) {
    if (argc != 2) {
        usage();
        return false;
    }
    param->dev_ = argv[1];
    return true;
}

bool isDHCP(libnet_udp_hdr* udphdr){
    uint16_t sport = ntohs(udphdr->uh_sport);
    uint16_t dport = ntohs(udphdr->uh_dport);

    qDebug() << sport << dport;
    return ((sport == SERVER) && (dport == CLIENT)) || ((sport == CLIENT) &&(dport == SERVER));

}

Mac info_packet(const u_char* packet){

    struct ethernet_hdr* ethhdr = (struct ethernet_hdr*)packet;
    Mac dmac  = ethhdr->dmac_;
    Mac smac = ethhdr->smac_;
    uint16_t ether_type = ntohs(ethhdr->ether_type);
    if((ether_type != Ipv4) && !dmac.isBroadcast()) return Mac::nullMac();

    struct libnet_ipv4_hdr* iphdr = (struct libnet_ipv4_hdr*)(packet +sizeof(ethernet_hdr));
    uint8_t ip_p = iphdr->ip_p;
    uint16_t iphdr_len = iphdr->ip_hl*4;
    qDebug() << iphdr_len;

    if(ip_p != UDP) return Mac::nullMac();

    struct libnet_udp_hdr* udphdr = (struct libnet_udp_hdr*)(packet +14 +iphdr_len) ;
    if(isDHCP(udphdr)){

        std::cout << std::string(smac) << std::endl;
        return smac;
    }

    else return Mac::nullMac();

}


void CaptureThread::run() {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t* pcap = pcap_open_live(qPrintable(intfName_), BUFSIZ, 1,1, errbuf);
    if (pcap == NULL) {
        fprintf(stderr, "pcap_open_live(%s) return null - %s\n", qPrintable(intfName_), errbuf);
        return;
    }

    while (true) {
        struct pcap_pkthdr* header;
        const u_char* packet;
        int res = pcap_next_ex(pcap, &header, &packet);
        if (res == 0) continue;
        if (res == PCAP_ERROR || res == PCAP_ERROR_BREAK) {
            printf("pcap_next_ex return %d(%s)\n", res, pcap_geterr(pcap));
            break;
        }
        //printf("%u bytes captured\n", header->caplen);
        Mac mac = info_packet(packet);
        if(!mac.isNull()){
            emit captured(mac);
        }
    }

    pcap_close(pcap);
}
