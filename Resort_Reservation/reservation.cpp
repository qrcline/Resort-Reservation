#include "reservation.h"
#include "ui_reservation.h"
#include "iostream"
#include "string"
#include <QDate>
#include <QMessageBox>




Reservation::Reservation(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Reservation)
{
    ui->setupUi(this);

    //Sets the background
        setBackground();

    ui->nextButton->setEnabled(false);


}

Reservation::~Reservation()
{
    delete ui;
}

void Reservation::setBackground()
{
    QPixmap bkgnd(":/Resources/Shale.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}


void Reservation::on_nextButton_clicked()
{
    double finalTotal=0;
    double costRoomNight=0;


    ui->stackedWidget->setCurrentIndex(1);
}

void Reservation::on_adultSelection_valueChanged(int arg1)
{
    std::cout<<ui->adultSelection->value();
}

void Reservation::on_childrenSelection_valueChanged(int arg1)
{

}

void Reservation::on_roomSelection_currentIndexChanged(int index)
{

}
