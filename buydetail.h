#ifndef BUYDETAIL_H
#define BUYDETAIL_H

#include <QDialog>


namespace Ui {
class BuyDetail;
}

class BuyDetail : public QDialog
{
    Q_OBJECT

public:
    explicit BuyDetail(QWidget *parent = 0);
    ~BuyDetail();

private:
    Ui::BuyDetail *ui;
    void SetBillData();
};

#endif // BUYDETAIL_H
