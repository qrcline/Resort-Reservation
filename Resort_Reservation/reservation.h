#ifndef RESERVATION_H
#define RESERVATION_H

#include <QMainWindow>

namespace Ui {
class Reservation;
}

class Reservation : public QMainWindow
{
    Q_OBJECT

public:
    explicit Reservation(QWidget *parent = nullptr);
    ~Reservation();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Reservation *ui;
    QString reservationName;
    bool parking=false;
    int nights=0;



};

#endif // RESERVATION_H
