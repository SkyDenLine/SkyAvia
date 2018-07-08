#include "listofflight.h"
#include "ui_listofflight.h"
#include "aircraft_1.h"

ListOfFlight::ListOfFlight(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ListOfFlight)
{
    ui->setupUi(this);
}

ListOfFlight::~ListOfFlight()
{
    delete ui;
}

void ListOfFlight::on_pushButton_clicked()
{
    Aircraft_1 Aircraft_1_Layot;
    Aircraft_1_Layot.setModal(true);
    Aircraft_1_Layot.exec();
}
