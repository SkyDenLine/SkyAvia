#include "buydetail.h"
#include "ui_buydetail.h"
#include "aircraft_1.h"
#include "QFile"
#include <QTextStream>
#include "QTextCodec"
#include "locale"
#include "stdio.h"

QString info[5];

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

void BuyDetail::SetBillData()
{

}
