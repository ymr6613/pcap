#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "packet.h"
Packet *f;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)

{
    f=new Packet();
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    f->show();
}
