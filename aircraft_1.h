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
    void on_ConfirmBusines_2_clicked();
    void CheckTiketType(QPushButton *seats, int mode);
    void SetPrice();
    void on_ConfirmBusines_3_clicked();
    void on_accept_tiket_clicked();
};

#endif // AIRCRAFT_1_H
