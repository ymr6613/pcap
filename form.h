#ifndef FORM_H
#define FORM_H
#include <QObject>
#include <QVector>

struct PcapHeader
{
    qint32 caplen;
    qint32 len;

};

class Packetform
{
//protected:
//unsigned int caplen;
//unsigned int len;

public:
//Packetform();
//~Packetform();

PcapHeader pHeader;
unsigned char data[2000];



};
struct PcapFHeader
{
    qint32 magic;
    qint16 version_major;
    qint16 version_minor;
    qint32 thiszone;     /* gmt to local correction */
    qint32 sigfigs;    /* accuracy of timestamps */
    qint32 snaplen;    /* max length saved portion of each pkt */
    qint32 linktype;   /* data link type (LINKTYPE_*) */
    qint32 Packet;


};
class PacketStream
{
public:

    PcapFHeader fHeader;
    QVector <Packetform> packets;
};
#endif // FORM_H
