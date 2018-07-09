#include "aircraft_1.h"
#include "ui_aircraft_1.h"
#include "string"
#include "sstream"
#include "QMessageBox"
#include "buydetail.h"
#include "QFile"
#include <QTextStream>
#include <math.h>
#include <QDebug>
#include <sstream>



QString select_seats[21][2];
QString bill_info[10];
QString Ticket_Data[6];
int SelectCount=0,SelectedSeats=1,EconomyCount=0,BusinesCount=0;
QString LabelCount;
QString tiket_data[30];
bool NeedReserv=true;
int info_count=1,Sell_Tikets=0,Returned_Tiket=0,Sell_Economy=0,Sell_Busines=0,All_Price=0;
QString TicketNumber;
int ticketNumber=1;
QFile fbill("bill.txt");
QTextStream Bwriter (&fbill);




void Aircraft_1::HideFormBuy()
{
    ui->label_FIO->hide();
    ui->label_Passport->hide();
    ui->label_place->hide();
    ui->label_Passport_2->hide();
    ui->lineEdit_seat->hide();
    ui->lineEdit->hide();
    ui->lineEdit_3->hide();
    ui->lineEdit_4->hide();
    ui->pushNextTiket->hide();
    ui->label_header->hide();
}

void Aircraft_1::SetBill()
{
    setlocale(LC_ALL,"Russian");
    QTextStream BwriterN (&fbill);
    fbill.open( QIODevice::ReadWrite | QIODevice::Text);
    BwriterN.readLine();
    for (int i=0;i<4;i++)
    {
        QStringList TEMP = BwriterN.readLine().split('\t');
        bill_info[i]=TEMP[1];
    }
    fbill.close();

    fbill.open( QIODevice::WriteOnly | QIODevice::Text);

    Sell_Tikets=Sell_Tikets+bill_info[0].toInt();
    Sell_Economy=Sell_Economy+bill_info[1].toInt();
    Sell_Busines=Sell_Busines+bill_info[2].toInt();
    All_Price=All_Price+bill_info[3].toInt();

    BwriterN <<"Рейс Пенза - Лос-Анджелес"<<"\n";
    BwriterN <<"Проданное билетов:"<<"\t"+QString::number(Sell_Tikets)+"\n";
    BwriterN <<"Проданно Эконом-класс:"<< "\t"+QString::number(Sell_Economy)+"\n";
    BwriterN <<"Проданно Бизнес-класс:"<< "\t"+QString::number(Sell_Busines)+"\n";
    BwriterN <<"Общая стоимость:"<<"\t"+QString::number(All_Price);
    fbill.close();
    Sell_Economy=0;
    Sell_Busines=0;
    Sell_Tikets=0;


}

int Aircraft_1::GetPrice(QPushButton *seats)
{
    QFile TempTicket ("Ticket_"+seats->text()+".txt");
    QTextStream TicketR (&TempTicket);
    TempTicket.open(QIODevice::ReadOnly|QIODevice::Text);
    TicketR.readLine();
    for (int i=0; i<4;i++)
    {

        if(i==2)
        {
            QStringList Price = TicketR.readLine().split(' ');
            return Price[1].toInt();
        }
        else
        {
           QStringList Price = TicketR.readLine().split(' ');
        }
    }

}

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
            SetSeatsType();
            EconomyCount=0;
            BusinesCount=0;
            HideFormBuy();
            setlocale(LC_ALL,"Russian");
            fbill.open( QIODevice :: WriteOnly | QIODevice::Text);

            Bwriter <<"Рейс Пенза - Лос-Анджелес "<< "\n";
            Bwriter <<"Проданное билетов:"<<"\t0 \n";
            Bwriter <<"Проданно Эконом-класс: "<< "\t0 \n";
            Bwriter <<"Проданно Бизнес-класс : "<<"\t0 \n";
            Bwriter <<"Общая стоимость: "<<"\t0";
            fbill.close();



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
            Sell_Economy++;
       }
       else
       {
           seats->setStyleSheet(
                          "color: black; "
                          "background-color: #EDF24B; "
                          "border-width: 2px; "
                          "border-color:#00FF26;"
                          "border-style: solid;"
                          "border-radius: 4;"
                          "padding: 3px;"
                          "font-size: 12px;"
                          "padding-left: 5px;"
                          "padding-right: 5px;"
                          );
           Sell_Busines++;
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
        Sell_Economy--;
        }
        else
        {
            seats->setStyleSheet(
                                 "color: black; "
                                 "background-color: #1EB4E6; "
                                 "border-width: 2px; "
                                 "border-color: #00FF26;"
                                 "border-style: solid;"
                                 "border-radius: 4;"
                                 "padding: 3px;"
                                 "font-size: 12px;"
                                 "padding-left: 5px;"
                                 "padding-right: 5px;"
                                 );
            Sell_Busines++;

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
int xEco,xBus,result,Kof_Ec,Kof_Bc;
xEco=ui->label_13->text().toInt();
xBus=ui->label_14->text().toInt();
Kof_Ec=ui->lineEdit_Eprice->text().toInt();
Kof_Bc=ui->lineEdit_Bprice->text().toInt();

result=(xEco*Kof_Ec)+(xBus*Kof_Bc);
All_Price=result;
QString::number(result);
ui->label_16->setText(QString::number(result));
}
void Aircraft_1::aircraft_1_seats()
{
    NeedReserv=true;
    QPushButton *seats = (QPushButton *) sender();

    if(select_seats[seats->text().toInt()][0]!="buy" && select_seats[seats->text().toInt()][0]!="register" )
    {

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
    else
    {
     QMessageBox::StandardButton ask =  QMessageBox::question(this,"Возврат билета","Вы дейсвительно хотите вернуть биллет?",QMessageBox::Yes | QMessageBox::No);
     if(ask==QMessageBox::StandardButton::Yes)
     {
          Sell_Tikets=-1;
          ChangeColor(seats,2);
          select_seats[seats->text().toInt()][0]="unselected";
          int numberF =  seats->text().toInt();
          QString name = "../Ticket_"+QString::number(numberF)+".txt";
          QFile::remove(name);
          if (numberF>4)
          {

              All_Price=-GetPrice(seats);
              Sell_Economy=-1;
          }
          else
          {
              All_Price=-GetPrice(seats);
              Sell_Busines=-1;
          }
          SetBill();
     }
    }

}

void Aircraft_1::SetSeatsType()
{
    for(int i=1;i<=4;i++)
        select_seats[i][1]="Busines";
    for(int i=5;i<21;i++)
        select_seats[i][1]="Economy";
    for(int i=1;i<21;i++)
        select_seats[i][0]="unselected";
}

void SetBuy(QPushButton *seats,int mode)
{
    if(mode==1)
    {
        seats->setStyleSheet(
                             "color: black; "
                             "background-color: red; "
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
                             "background-color: red; "
                             "border-width: 2px; "
                             "border-color: #00FF26;"
                             "border-style: solid;"
                             "border-radius: 4;"
                             "padding: 3px;"
                             "font-size: 12px;"
                             "padding-left: 5px;"
                             "padding-right: 5px;"
                             );

    }

}

void Aircraft_1::ShowFormBuy()
{
    ui->label_FIO->show();
    ui->label_Passport->show();
    ui->label_place->show();
    ui->label_Passport_2->show();
    ui->lineEdit_seat->show();
    ui->lineEdit->show();
    ui->lineEdit_3->show();
    ui->lineEdit_4->show();
    ui->pushNextTiket->show();
    ui->label_header->show();
    ui->label_header->setText("Введите данные о пассажирах");
}

void Aircraft_1::SetSeat()
{
    while (select_seats[info_count][0]!="buy" )
    {
        info_count++;
        if (info_count==21)
        {
            info_count=0;
            HideFormBuy();
            SetBill();
            break;
        }
    }
    if (info_count!=0)
    ui->lineEdit_seat->setText(QString::number(info_count));

}

void Aircraft_1::GetTiketInfo()
{
    Ticket_Data[0]=ui->lineEdit->text();
    Ticket_Data[1]=ui->lineEdit_seat->text();
    Ticket_Data[2]=ui->lineEdit_3->text();
    Ticket_Data[3]=ui->lineEdit_4->text();
    TicketNumber="Ticket_"+Ticket_Data[1]+".txt";
    ticketNumber++;

    if(ui->lineEdit_seat->text().toInt()>4)
    {
        Ticket_Data[4]=ui->lineEdit_Eprice->text();
    }
    else
    {
        Ticket_Data[4]=ui->lineEdit_Bprice->text();
    }

    QFile ticket(TicketNumber);
    ticket.open( QIODevice :: WriteOnly | QIODevice::Text);
    QTextStream writer (&ticket);

    writer<<"Data Of Passenger "<<"\n";
    writer <<"Name: "<< Ticket_Data[0]+'\r\n';
    writer <<"Place: "<< Ticket_Data[1]+'\r\n';
    writer <<"Price: "<< Ticket_Data[4]+'\r\n';
    writer <<"Pasport: "<< Ticket_Data[2]+'\r\n';
    writer <<"Date Of Birthday: "<< Ticket_Data[3]+'\r\n';
    ticket.close();
    Sell_Tikets++;
    ui->lineEdit->setText("");
    ui->lineEdit_seat->setText("");
    ui->lineEdit_3->setText("");
    ui->lineEdit_4->setText("");

}


void Aircraft_1::on_accept_tiket_clicked()
{
    ShowFormBuy();
    info_count=1;

    for(int i=1;i<21;i++)
    {
        if(select_seats[i][0]=="selected")
        {
         select_seats[i][0]="buy";    
        switch (i)
        {
        case 1:
                SetBuy(ui->pushSeats_1,2);
            break;
        case 2:
SetBuy(ui->pushSeats_2,2);
            break;
        case 3:
SetBuy(ui->pushSeats_3,2);
            break;
        case 4:
SetBuy(ui->pushSeats_4,2);
            break;
        case 5:
SetBuy(ui->pushSeats_5,1);
            break;
        case 6:
SetBuy(ui->pushSeats_6,1);
            break;
        case 7:
SetBuy(ui->pushSeats_7,1);
            break;
        case 8:
SetBuy(ui->pushSeats_8,1);
            break;
        case 9:
SetBuy(ui->pushSeats_9,1);
            break;
        case 10:
SetBuy(ui->pushSeats_10,1);
            break;
        case 11:
SetBuy(ui->pushSeats_11,1);
            break;
        case 12:
SetBuy(ui->pushSeats_12,1);
            break;
        case 13:
SetBuy(ui->pushSeats_13,1);
            break;
        case 14:
SetBuy(ui->pushSeats_14,1);
            break;
        case 15:
SetBuy(ui->pushSeats_15,1);
            break;
        case 16:
SetBuy(ui->pushSeats_16,1);
            break;
        case 17:
SetBuy(ui->pushSeats_17,1);
            break;
        case 18:
SetBuy(ui->pushSeats_18,1);
            break;
        case 19:
SetBuy(ui->pushSeats_19,1);
            break;
        case 20:
SetBuy(ui->pushSeats_20,1);
            break;
        default:
            break;
        }
        }
    }
    SetSeat();
    EconomyCount=0;
    BusinesCount=0;
    SelectCount=0;
    ui->label_16->setText("0");
    ui->label_13->setText("0");
    ui->label_14->setText("0");
    ui->label_5->setText("0");




}

void Aircraft_1::on_pushNextTiket_clicked()
{
    QString Line_1=ui->lineEdit->text();
    QString Line_2=ui->lineEdit_3->text();
    QString Line_3=ui->lineEdit_4->text();

    if (Line_1==""|Line_2==""|Line_3=="")
    {
        if (Line_1=="")
        {
            ui->label_FIO->setStyleSheet("color:red;");
        }
        else
        {
            ui->label_FIO->setStyleSheet("color:black;");
        }
        if (Line_2=="")
        {
            ui->label_Passport->setStyleSheet("color:red;");
        }
        else
        {
            ui->label_Passport->setStyleSheet("color:black;");
        }
        if (Line_3=="")
        {
            ui->label_Passport_2->setStyleSheet("color:red;");
        }
        else
        {
            ui->label_Passport_2->setStyleSheet("color:black;");
        }
        QMessageBox::warning(this,"Ошибка","Заполните все поля");
    }
    else
    {
    ui->label_FIO->setStyleSheet("color:black;");
    ui->label_Passport->setStyleSheet("color:black;");
    ui->label_Passport_2->setStyleSheet("color:black;");
     GetTiketInfo();
     if(info_count!=0)
         {
             select_seats[info_count][0]="register";
             SetSeat();
         }
    }

}



