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
    void on_nextButton_clicked();

private:
    Ui::Reservation *ui;
    QString reservationName;
    bool parking=false;
    int nights=0;
    int roomType=0;




    void setBackground();
};

#endif // RESERVATION_H
