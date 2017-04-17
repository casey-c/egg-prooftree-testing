#include "stepitem.h"
#include "ui_stepitem.h"

StepItem::StepItem(QWidget *parent, int c, QString t) :
    QWidget(parent),
    ui(new Ui::StepItem)
{
    ui->setupUi(this);
    ui->label_2->setText(QString::number(c));
    ui->label->setText(t);
}

StepItem::~StepItem()
{
    delete ui;
}

int StepItem::getPrefWidth()
{
    return ui->frame->width();
}

QString StepItem::getNum()
{
    return ui->label_2->text();
}

