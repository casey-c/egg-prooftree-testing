#include "stepitem.h"
#include "ui_stepitem.h"
#include <QDebug>
#include <QFontMetrics>

StepItem::StepItem(QWidget* parent, int c, QString t) :
    QWidget(parent),
    ui(new Ui::StepItem)
{
    ui->setupUi(this);
    ui->label_2->setText(QString::number(c));
    ui->label->setText(t);

    // Palette stuff
    QPalette palette = ui->frame->palette();
    palette.setColor( backgroundRole(), QColor( 140, 140, 160 ) );

    ui->frame->setPalette(palette);
    ui->frame->setAutoFillBackground(false);
}

StepItem::~StepItem()
{
    delete ui;
}

void StepItem::mousePressEvent(QMouseEvent *event)
{
    QWidget::mousePressEvent(event);
    qDebug() << "Clicked widget " << ui->label_2->text();
    ui->frame->setFrameStyle(QFrame::Panel | QFrame::Sunken);
}

void StepItem::mouseReleaseEvent(QMouseEvent *event)
{
    QWidget::mouseReleaseEvent(event);
    //qDebug() << "Released widget" << ui->label_2->text();


    // Doesn't work
    //if (this->underMouse())
        //qDebug() << "Under mouse";
    //else
        //qDebug() << "Not under mouse";

    ui->frame->setFrameStyle(QFrame::Panel | QFrame::Raised);
}

void StepItem::enterEvent(QEvent *event)
{
    QWidget::enterEvent(event);
    //qDebug() << "Entered widget" << ui->label_2->text();
    ui->frame->setAutoFillBackground(true);
}

void StepItem::leaveEvent(QEvent *event)
{
    QWidget::leaveEvent(event);
    //qDebug() << "Left widget" << ui->label_2->text();
    ui->frame->setAutoFillBackground(false);
}
