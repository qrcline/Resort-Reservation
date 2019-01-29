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
    setRooms();





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

void Reservation::setRooms()
{
    sQueen.name="Standard 2 Queen -$284/Night";
    sQueen.price=284;
    sQueen.roomType=1;
    sQueen.maxPeople=4;

    aQueen.name="Atrium 2 Queen -$325/Night";
    aQueen.price=325;
    aQueen.roomType=2;
    aQueen.maxPeople=4;

    sKing.name="Standard King-$290/Night";
    sKing.price=290;
    sKing.roomType=3;
    sKing.maxPeople=3;

    aKing.name="Atrium King-$350/Night";
    aKing.price=350;
    aKing.roomType=4;
    aKing.maxPeople=3;
}

//TODO
void Reservation::on_nextButton_clicked()
{
    double finalTotal=0;
    double costRoomNight=0;


    ui->stackedWidget->setCurrentIndex(1);
}


void Reservation::on_adultSelection_valueChanged(int arg1)
{

    int selectedRoom=ui->roomSelection->currentIndex();
    if(selectedRoom==1||selectedRoom==2)
        int maxPeople=4;
    else((selectedRoom==3||selectedRoom==4));
            int maxPeople=3;

    int adultSelection =ui->adultSelection->value();
    int childrenSelection=ui->childrenSelection->value();

    ui->childrenSelection->setMaximum((maxPeople-adultSelection));
    ui->adultSelection->setMaximum(maxPeople-childrenSelection);





}

void Reservation::on_childrenSelection_valueChanged(int arg1)
{

}

void Reservation::on_roomSelection_currentIndexChanged(int index)
{

}
