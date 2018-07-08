#ifndef LISTOFFLIGHT_H
#define LISTOFFLIGHT_H

#include <QMainWindow>

namespace Ui {
class ListOfFlight;
}

class ListOfFlight : public QMainWindow
{
    Q_OBJECT

public:
    explicit ListOfFlight(QWidget *parent = 0);
    ~ListOfFlight();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ListOfFlight *ui;
};

#endif // LISTOFFLIGHT_H
