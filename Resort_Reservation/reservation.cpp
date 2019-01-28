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
    ui->stackedWidget->setCurrentIndex(1);
}
