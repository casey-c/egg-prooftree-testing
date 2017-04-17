#ifndef STEPITEM_H
#define STEPITEM_H

#include <QWidget>

namespace Ui {
class StepItem;
}

class StepItem : public QWidget
{
    Q_OBJECT

public:
    explicit StepItem(QWidget *parent = 0, int c = 0, QString t = "");
    ~StepItem();

    int getPrefWidth();
    QString getNum();

private:
    Ui::StepItem *ui;
};

#endif // STEPITEM_H
