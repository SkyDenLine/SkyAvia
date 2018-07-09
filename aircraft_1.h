#ifndef AIRCRAFT_1_H
#define AIRCRAFT_1_H

#include <QDialog>

namespace Ui {
class Aircraft_1;
}

class Aircraft_1 : public QDialog
{
    Q_OBJECT

public:
    explicit Aircraft_1(QWidget *parent = 0);
    ~Aircraft_1();


private:
    Ui::Aircraft_1 *ui;



private slots:
    void aircraft_1_seats();
    void CheckTiketType(QPushButton *seats, int mode);
    void SetPrice();
    void SetSeatsType();
    void on_accept_tiket_clicked();
    void ShowFormBuy();
    void GetTiketInfo();
    void SetSeat();
    void on_pushNextTiket_clicked();
    void HideFormBuy();
    void SetBill();
    int GetPrice(QPushButton *seats);
};

#endif // AIRCRAFT_1_H
