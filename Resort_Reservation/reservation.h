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

    void on_backButton_clicked();

    void on_payButton_clicked();

    void on_closeButton_clicked();

    void on_nights_valueChanged(const QString &arg1);

    void on_parkingNo_clicked();

    void on_parkingYes_clicked();

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

    const double S_QUEEN=284.00;
    const double A_QUEEN=325.00;
    const double S_KING=290.00;
    const double A_KING=350.00;
    const double PARKING=12.75;
    const double RESORT_FEE=15.00;
    const double TAX=0.15;








    void setBackground();
    void setRooms();
    void calculateTotal();
    QString ToDollar(double);
};

#endif // RESERVATION_H
