#include "stepcontainer.h"
#include "ui_stepcontainer.h"
#include "stepitem.h"
#include <QDebug>

StepContainer::StepContainer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StepContainer)
{
    count = 0;
    str = "STEP";
    ui->setupUi(this);

    vlayout = new QVBoxLayout;
    vlayout->setSizeConstraint(QLayout::SetMinAndMaxSize);

    QWidget* inner = new QWidget(ui->scrollArea);
    ui->scrollArea->setWidget(inner);
    inner->setLayout(vlayout);
}

StepContainer::~StepContainer()
{
    delete ui;
}

void StepContainer::addStep()
{
    //qDebug() << "Adding a step";
    //str = str + "STEP";

    StepItem* newStep = new StepItem(this, count++, str);
    vlayout->addWidget(newStep);
    itemList.append(newStep);
    newStep->show();

    //updateWidths();
}

void StepContainer::updateWidths()
{
    //int maxPref = 0;
    for (StepItem* item : itemList)
    {
        //item->show();
        qDebug() << item->getNum() << ": "
                 << QString::number(item->getPrefWidth()) << "width";
    }

}
