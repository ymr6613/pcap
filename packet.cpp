#include "packet.h"
#include "ui_packet.h"
#include <QFileDialog>
#include <QDebug>
#include <QFile>
#include <QByteArray>
#include <QDataStream>
#include "form.h"
Packetform ph;

PacketStream ps;
int numb=0,A[2000],Pos[2000];
int max=0,min=9999;
int k,pos,size;
QString n,p,s;
Packet::Packet(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Packet)
{
    ui->setupUi(this);
}

Packet::~Packet()
{
    delete ui;
}

void Packet::on_pushButton_clicked()
{
    QString fName = QFileDialog::getOpenFileName(0,"Open file", "", "CAP files (*.*cap)");
      qDebug() << fName;
      if (fName == "")
      { return;}
QFile file(fName);
      if (!file.open(QIODevice::ReadOnly))
      {
          qDebug()<<"Error of open file";
          return;
      }
     long int lenh=30;
     for(int i=0;i<2000;i++)
     {
         A[i]=0;
         Pos[i]=0;
     }
ui->lineEdit->setText(fName);
file.read((char*)&ps.fHeader, 24);
ui->B->append("Заголовок файла:");
ui->B->append("Magic: "+ QString::number(ps.fHeader.magic));
ui->B->append("Version Major: "+ QString::number(ps.fHeader.version_major));
ui->B->append("Version Minor: "+ QString::number(ps.fHeader.version_minor));
ui->B->append("thiszone: " + QString::number(ps.fHeader.thiszone));
ui->B->append("sigfigs: "  +QString::number(ps.fHeader.sigfigs));
ui->B->append("snaplen: "  +QString::number(ps.fHeader.snaplen));
ui->B->append("linktype: " +QString::number(ps.fHeader.linktype));
ui->B->append("\n");

while (file.pos()<file.size())
{
    k++;
    numb++;
    file.read((char*)&ph.pHeader,2);
    lenh=lenh+ph.pHeader.caplen+14;

    if (lenh<file.size()) file.seek(lenh);
     else file.seek(file.size());
    n="Packet "+ QString::number(numb);
    ui->B->append(n);
    p="Pos ="+ QString::number(file.pos());
    ui->B->append(p);
    s="Size packet =" +QString::number(ph.pHeader.caplen);
    ui->B->append(s);
    ui->B->append(" ");
    A[k]=ph.pHeader.caplen;
    Pos[k]=file.pos()+8;

}


}

