#include "reservation.h"
#include "ui_reservation.h"

Reservation::Reservation(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Reservation)
{
    ui->setupUi(this);

    QPixmap bkgnd(":/Resources/Shale.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

Reservation::~Reservation()
{
    delete ui;
}

void Reservation::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}
