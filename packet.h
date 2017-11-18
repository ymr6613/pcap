#ifndef PACKET_H
#define PACKET_H

#include <QMainWindow>

namespace Ui {
class Packet;
}

class Packet : public QMainWindow
{
    Q_OBJECT

public:
    explicit Packet(QWidget *parent = 0);
    ~Packet();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Packet *ui;
};

#endif // PACKET_H
