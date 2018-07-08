#include "aircraft_1.h"
#include "ui_aircraft_1.h"
#include "string"
#include "sstream"
#include "QMessageBox"

QString select_seats[21][2];
int SelectCount=0,SelectedSeats=1,EconomyCount=0,BusinesCount=0;
QString LabelCount;
bool NeedReserv=true;

Aircraft_1::Aircraft_1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Aircraft_1)
{
    ui->setupUi(this);

            connect(ui->pushSeats_1,SIGNAL(clicked()),this,SLOT(aircraft_1_seats()));
            connect(ui->pushSeats_2,SIGNAL(clicked()),this,SLOT(aircraft_1_seats()));
            connect(ui->pushSeats_3,SIGNAL(clicked()),this,SLOT(aircraft_1_seats()));
            connect(ui->pushSeats_4,SIGNAL(clicked()),this,SLOT(aircraft_1_seats()));
            connect(ui->pushSeats_5,SIGNAL(clicked()),this,SLOT(aircraft_1_seats()));
            connect(ui->pushSeats_6,SIGNAL(clicked()),this,SLOT(aircraft_1_seats()));
            connect(ui->pushSeats_7,SIGNAL(clicked()),this,SLOT(aircraft_1_seats()));
            connect(ui->pushSeats_8,SIGNAL(clicked()),this,SLOT(aircraft_1_seats()));
            connect(ui->pushSeats_9,SIGNAL(clicked()),this,SLOT(aircraft_1_seats()));
            connect(ui->pushSeats_10,SIGNAL(clicked()),this,SLOT(aircraft_1_seats()));
            connect(ui->pushSeats_11,SIGNAL(clicked()),this,SLOT(aircraft_1_seats()));
            connect(ui->pushSeats_12,SIGNAL(clicked()),this,SLOT(aircraft_1_seats()));
            connect(ui->pushSeats_13,SIGNAL(clicked()),this,SLOT(aircraft_1_seats()));
            connect(ui->pushSeats_14,SIGNAL(clicked()),this,SLOT(aircraft_1_seats()));
            connect(ui->pushSeats_15,SIGNAL(clicked()),this,SLOT(aircraft_1_seats()));
            connect(ui->pushSeats_16,SIGNAL(clicked()),this,SLOT(aircraft_1_seats()));
            connect(ui->pushSeats_17,SIGNAL(clicked()),this,SLOT(aircraft_1_seats()));
            connect(ui->pushSeats_18,SIGNAL(clicked()),this,SLOT(aircraft_1_seats()));
            connect(ui->pushSeats_19,SIGNAL(clicked()),this,SLOT(aircraft_1_seats()));
            connect(ui->pushSeats_20,SIGNAL(clicked()),this,SLOT(aircraft_1_seats()));

}

Aircraft_1::~Aircraft_1()
{
    delete ui;
}

void ChangeColor(QPushButton *seats, int mode)
{
    if(mode==1)
    {
       if (select_seats[seats->text().toInt()][1]=="Economy")
        {
            seats->setStyleSheet(
                           "color: black; "
                           "background-color: #EDF24B; "
                           "border-width: 2px; "
                           "border-color: black;"
                           "border-style: solid;"
                           "border-radius: 4;"
                           "padding: 3px;"
                           "font-size: 12px;"
                           "padding-left: 5px;"
                           "padding-right: 5px;"
                           );
       }
       else
       {
           seats->setStyleSheet(
                          "color: black; "
                          "background-color: #EDF24B; "
                          "border-width: 2px; "
                          "border-color:#F24B61;"
                          "border-style: solid;"
                          "border-radius: 4;"
                          "padding: 3px;"
                          "font-size: 12px;"
                          "padding-left: 5px;"
                          "padding-right: 5px;"
                          );
       }
    }

    else if(mode==2)
    {
        if(select_seats[seats->text().toInt()][1]=="Economy")
        {
        seats->setStyleSheet(
                             "color: black; "
                             "background-color: #1EB4E6; "
                             "border-width: 2px; "
                             "border-color: black;"
                             "border-style: solid;"
                             "border-radius: 4;"
                             "padding: 3px;"
                             "font-size: 12px;"
                             "padding-left: 5px;"
                             "padding-right: 5px;"
                             );
        }
        else
        {
            seats->setStyleSheet(
                                 "color: black; "
                                 "background-color: #1EB4E6; "
                                 "border-width: 2px; "
                                 "border-color: #F24B61;"
                                 "border-style: solid;"
                                 "border-radius: 4;"
                                 "padding: 3px;"
                                 "font-size: 12px;"
                                 "padding-left: 5px;"
                                 "padding-right: 5px;"
                                 );

        }
    }


}

void Aircraft_1::CheckTiketType(QPushButton *seats, int mode)
{
    if(mode==2)
    {
        if (select_seats[seats->text().toInt()][1]=="Economy")
        {
            EconomyCount--;
            ui->label_13->setText(QString::number(EconomyCount));


        }
        else
        {
            BusinesCount--;
            ui->label_14->setText(QString::number(BusinesCount));
        }

    }
    else  if(mode==1)
    {
        if (select_seats[seats->text().toInt()][1]=="Economy")
        {
            EconomyCount++;
            ui->label_13->setText(QString::number(EconomyCount));

        }
        else
        {
            BusinesCount++;
            ui->label_14->setText(QString::number(BusinesCount));
        }

    }
}

void Aircraft_1::SetPrice()
{
int xEco,xBus,result;
xEco=ui->label_13->text().toInt();
xBus=ui->label_14->text().toInt();
result=(xEco*2000)+(xBus*4000);
QString::number(result);
ui->label_16->setText(QString::number(result));
}
void Aircraft_1::aircraft_1_seats()
{
    NeedReserv=true;
    QPushButton *seats = (QPushButton *) sender();


    if(select_seats[seats->text().toInt()][0]=="selected")
        {
            ChangeColor(seats,2);
            select_seats[seats->text().toInt()][0]="unselected";
            SelectCount--;
            LabelCount = QString::number(SelectCount);
            ui->label_5->setText(LabelCount);
            CheckTiketType(seats,2);

        }
    else
    {
      ChangeColor(seats,1);
      CheckTiketType(seats,1);
      select_seats[seats->text().toInt()][0]="selected";
      SelectCount++;
      LabelCount = QString::number(SelectCount);
      ui->label_5->setText(LabelCount);
    }

    SetPrice();

}


void Aircraft_1::on_ConfirmBusines_2_clicked()
{
    int ReservBC=ui->lineEdit->text().toInt();
    if (ReservBC>20)
    {
        QMessageBox::warning(this,"Некорректный ввод","Колличество мест не должно превышать: 20");
    }else
    {
    for(int i=1;i<=ReservBC;i++)
        select_seats[i][1]="Busines";
    for(int i=ReservBC+1;i<21;i++)
        select_seats[i][1]="Economy";
    }
}



void Aircraft_1::on_accept_tiket_clicked()
{

}
