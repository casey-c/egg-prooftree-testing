#ifndef STEPCONTAINER_H
#define STEPCONTAINER_H

#include <QWidget>
#include <QVBoxLayout>
#include "stepitem.h"
#include <QList>

namespace Ui {
class StepContainer;
}

class StepContainer : public QWidget
{
    Q_OBJECT

public:
    explicit StepContainer(QWidget *parent = 0);
    ~StepContainer();

    void addStep();

private:
    Ui::StepContainer *ui;

    QList<StepItem*> itemList;

    QVBoxLayout* vlayout;
    int count;
    QString str;

    void updateWidths();
};

#endif // STEPCONTAINER_H
