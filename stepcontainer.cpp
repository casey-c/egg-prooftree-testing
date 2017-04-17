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
    StepItem* newStep = new StepItem(this, count++, str);
    vlayout->addWidget(newStep);
    itemList.append(newStep);

    updateWidths();
}

void StepContainer::updateWidths()
{
    for (StepItem* item : itemList)
    {
        item->setMinimumWidth(ui->scrollArea->width() - 35);
        item->setMaximumWidth(ui->scrollArea->width() - 35);
    }
}

void StepContainer::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    updateWidths();
}
