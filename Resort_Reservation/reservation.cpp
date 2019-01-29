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
   // ui->nextButton->setEnabled(false);
    setRooms();



}


Reservation::~Reservation()
{
    delete ui;
}

QString Reservation::ToDollar(double price )
{
    QString output= QString::number(price,'f',2); // Sets precission to 2 decimal places and converts to string
    //TODO add comma for over 100 dollars use function
    return "$"+output;
}


void Reservation::calculateTotal()
{
    double roomPrice=0.00;
    switch (ui->roomSelection->currentIndex()) {

    case 0: roomPrice=S_QUEEN;
        break;
    case 1:roomPrice=A_QUEEN;
        break;
    case 2: roomPrice=S_KING;
        break;
    case 3:roomPrice=A_KING;

    }
    double parkingFee=0.00;
    if(ui->parkingYes->isChecked())
        parkingFee=PARKING;
    int nights=ui->nights->value();



     ui->subtotalPg1->setText(ToDollar((roomPrice+parkingFee)*nights));

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

void Reservation::on_roomSelection_currentIndexChanged(int index)
{
    calculateTotal();
}

//Person Selection
void Reservation::on_adultSelection_valueChanged(int adultSelection)
{

    int selectedRoom=ui->roomSelection->currentIndex();
        int maxPeople=4;
   if((selectedRoom==2||selectedRoom==3))
             maxPeople=3;


    int childrenSelection=ui->childrenSelection->value();

    ui->childrenSelection->setMaximum((maxPeople-adultSelection));
    //ui->adultSelection->setMaximum(maxPeople-childrenSelection);
    calculateTotal();


}

void Reservation::on_childrenSelection_valueChanged(int childrenSelection)
{
    int selectedRoom=ui->roomSelection->currentIndex();
    int maxPeople=4;
    if((selectedRoom==2||selectedRoom==3))
         maxPeople=3;

    int adultSelection =ui->adultSelection->value();

    //ui->childrenSelection->setMaximum((maxPeople-adultSelection));
    ui->adultSelection->setMaximum(maxPeople-childrenSelection);
    calculateTotal();
}

//Navigation
void Reservation::on_backButton_clicked()
{
    //Page 2 back to page 1
    ui->stackedWidget->setCurrentIndex(0);
}

void Reservation::on_payButton_clicked()
{
    //Page 2 to page 3
     ui->stackedWidget->setCurrentIndex(2);
}

void Reservation::on_closeButton_clicked()
{
    //Closes app
    QApplication::quit();
}
void Reservation::on_nextButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void Reservation::on_nights_valueChanged(const QString &arg1)
{
    calculateTotal();
}

void Reservation::on_parkingNo_clicked()
{
    calculateTotal();
}

void Reservation::on_parkingYes_clicked()
{
    calculateTotal();
}
