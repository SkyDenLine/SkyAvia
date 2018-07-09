#include "buydetail.h"
#include "ui_buydetail.h"
#include "aircraft_1.h"


BuyDetail::BuyDetail(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BuyDetail)
{
    ui->setupUi(this);
}

BuyDetail::~BuyDetail()
{
    delete ui;
}
