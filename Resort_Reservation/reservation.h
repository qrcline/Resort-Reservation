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

    void on_adultSelection_valueChanged(int arg1);

    void on_childrenSelection_valueChanged(int arg1);

    void on_roomSelection_currentIndexChanged(int index);

private:
    Ui::Reservation *ui;
    QString reservationName;
    bool parking=false;
    int nights=0;
    int roomType=0;

    struct room
    {
        QString name;
        int roomType;
        int price;
        int maxPeople;
    }sQueen,aQueen,sKing,aKing;







    void setBackground();
    void setRooms();
};

#endif // RESERVATION_H
