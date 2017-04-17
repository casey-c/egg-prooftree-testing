#include "stepcontainer.h"
#include "ui_stepcontainer.h"
#include "stepitem.h"
#include <QDebug>
#include <QScrollBar>

#define SCROLL_OFFSET 44

StepContainer::StepContainer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StepContainer)
{
    count = 0;
    str = "STEP";
    ui->setupUi(this);

    vlayout = new QVBoxLayout;
    vlayout->setSizeConstraint(QLayout::SetMinAndMaxSize);
    vlayout->setSpacing(4);

    QWidget* inner = new QWidget(ui->scrollArea);
    ui->scrollArea->setWidget(inner);
    inner->setLayout(vlayout);

    // Add some default steps
    StepItem* s1 = new StepItem(this, count++, "Premise");
    vlayout->addWidget(s1);
    itemList.append(s1);

    StepItem* s2 = new StepItem(this, count++, "Double-cut removal");
    vlayout->addWidget(s2);
    itemList.append(s2);

    StepItem* s3 = new StepItem(this, count++, "Deiteration");
    vlayout->addWidget(s3);
    itemList.append(s3);

    StepItem* s4 = new StepItem(this, count++, "Insertion");
    vlayout->addWidget(s4);
    itemList.append(s4);

    StepItem* s5 = new StepItem(this, count++, "Deletion");
    vlayout->addWidget(s5);
    itemList.append(s5);
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

    // Scroll to bottom (kinda ugly)
    ui->scrollArea->widget()->adjustSize();
    qApp->processEvents();
    ui->scrollArea->verticalScrollBar()->setValue(
                ui->scrollArea->verticalScrollBar()->maximum() );
}

void StepContainer::updateWidths()
{
    for (StepItem* item : itemList)
    {
        item->setMinimumWidth(ui->scrollArea->width() - SCROLL_OFFSET);
        item->setMaximumWidth(ui->scrollArea->width() - SCROLL_OFFSET);
    }
}

void StepContainer::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    updateWidths();
}
