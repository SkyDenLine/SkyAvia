#include "buydetail.h"
#include "ui_buydetail.h"
#include "aircraft_1.h"
#include "QFile"
#include <QTextStream>
#include "stdio.h"

QString info[5];

BuyDetail::BuyDetail(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BuyDetail)
{
    ui->setupUi(this);
    SetBillData();
}

BuyDetail::~BuyDetail()
{
    delete ui;
}

void BuyDetail::SetBillData()
{
    QFile Bill ("bill.txt");
    Bill.open(QIODevice::ReadOnly|QIODevice::Text);
    QTextStream bill_s (&Bill);
    bill_s.readLine();
    for (int i=0;i<4;i++)
    {
        QStringList TEMP = bill_s.readLine().split('\t');
        info[i]=TEMP[1];
    }
    ui->All->setText(info[0]);
    ui->SE->setText(info[1]);
    ui->SB->setText(info[2]);
    ui->ALLP->setText(info[3]);


  Bill.close();
}
