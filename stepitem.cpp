#include "stepitem.h"
#include "ui_stepitem.h"
#include <QDebug>
#include <QFontMetrics>

StepItem::StepItem(QWidget *parent, int c, QString t) :
    QWidget(parent),
    ui(new Ui::StepItem)
{
    ui->setupUi(this);
    ui->label_2->setText(QString::number(c));
    ui->label->setText(t);

    // Set up the initial widths
    prefWidth = ui->label->width() + ui->label_2->width() + 10;
    qDebug() << "Set initial prefWidth to " << QString::number(prefWidth);
}

StepItem::~StepItem()
{
    delete ui;
}

int StepItem::getPrefWidth()
{
    return prefWidth;
    //return ui->label->width() + ui->label_2->width() + 5;
    //return ui->frame->width();
}

QString StepItem::getNum()
{
    return ui->label_2->text();
}

