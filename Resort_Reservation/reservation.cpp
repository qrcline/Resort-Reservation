#include "reservation.h"
#include "ui_reservation.h"
#include "iostream"
#include <string>
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
     ui->payButton->setEnabled(false);
    setRooms();
    ui->arrivalDateInput->setDate(QDate::currentDate());
    ui->arrivalDateInput->setMinimumDateTime(QDateTime::currentDateTime());
    ui->cardExpiration->setInputMask("99/9999;_");
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
    QString roomName;
    switch (ui->roomSelection->currentIndex()) {

    case 0:
        roomPrice=sQueen.price;
        roomName=sQueen.name;
        break;
    case 1:
        roomPrice=aQueen.price;
        roomName=aQueen.name;
        break;
    case 2:
        roomPrice=sKing.price;
        roomName=sKing.name;
        break;
    case 3:
        roomPrice=aKing.price;
        roomName=aKing.name;

    }
    double parkingFee=0.00;
    QString parking="NO";
    if(ui->parkingYes->isChecked())
    {
        parking="YES";
        parkingFee=PARKING;
    }
    int nights=ui->nights->value();


    double roomTotal=roomPrice*nights;
    double parkingTotal=parkingFee*nights;
    double resortFTotal=RESORT_FEE*nights;
    double taxTotal=TAX*roomTotal;
    double totalDue=roomTotal+parkingTotal+resortFTotal+taxTotal;
     ui->subtotalPg1->setText(ToDollar((roomPrice+parkingFee)*nights));
     ui->roomTotal->setText(ToDollar(roomTotal));
     ui->parkingTotal->setText(ToDollar(parkingTotal));
     ui->resortFeeTotal->setText(ToDollar(resortFTotal));
     ui->taxTotal->setText(ToDollar(taxTotal));
     ui->totalDue->setText(ToDollar(totalDue));

     //Confirmation page values
     ui->totalNightsConfirmation->setText(QString::number(nights));
     ui->parkingConfirmation->setText(parking);
     int children=ui->childrenSelection->value();
     int adults=ui->adultSelection->value();
     ui->occupantsConfirmation->setText("Children: "+QString::number(children)+ ", Adults: "+QString::number(adults));
     ui->roomTypeConfirmation->setText(roomName);
     ui->finalTotalConfirmation->setText(ToDollar(totalDue));

     ui->arrivalDateConfirmation->setText( ui->arrivalDateInput->date().toString());    



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
    sQueen.name="Standard 2 Queen";
    sQueen.price=284;
    sQueen.roomType=1;
    sQueen.maxPeople=4;

    aQueen.name="Atrium 2 Queen";
    aQueen.price=325;
    aQueen.roomType=2;
    aQueen.maxPeople=4;

    sKing.name="Standard King-";
    sKing.price=290;
    sKing.roomType=3;
    sKing.maxPeople=3;

    aKing.name="Atrium King";
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
    QMessageBox msgBox;
    msgBox.setText("Payment Confirmed");
    msgBox.exec();
     ui->stackedWidget->setCurrentIndex(2);
     ui->creditCardConfirmation->setText(ui->cardNumber->text().right(4));
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

void Reservation::on_reservationName_textChanged(const QString &arg1)
{
    ui->nextButton->setEnabled(true);
     calculateTotal();
}

//Credit Card Buttons
void Reservation::on_visaButton_clicked()
{
    ui->cardNumber->clear();
    ui->cardNumber->clearMask();
    ui->cardNumber->setInputMask("4999-9999-9999-9999");
    ui->cardNumber->setText("4");
}

void Reservation::on_discoverButton_clicked()
{
    ui->cardNumber->clear();
    ui->cardNumber->clearMask();
    ui->cardNumber->setInputMask("699-9999-9999-9999");
    ui->cardNumber->setText("6");
}

void Reservation::on_mCardButton_clicked()
{
    ui->cardNumber->clear();
    ui->cardNumber->clearMask();
    ui->cardNumber->setInputMask("5999-9999-9999-9999");
    ui->cardNumber->setText("5");
}

void Reservation::on_amexButton_clicked()
{
     ui->cardNumber->clear();
     ui->cardNumber->clearMask();
    ui->cardNumber->setInputMask("3999-999999-99999");
    ui->cardNumber->setText("3");
}

void Reservation::on_cardNumber_textChanged(const QString &arg1)
{
    int max=19;
    QString button= ui->buttonGroup->checkedButton()->text();
    if(button == "AMERICAN EXPRESS")
        max=17;

    if(max==(ui->cardNumber->text().length()))
        ui->payButton->setEnabled(true);

}


