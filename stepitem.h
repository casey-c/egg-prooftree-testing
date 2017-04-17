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
    explicit StepItem(QWidget* parent = 0, int c = 0, QString t = "");
    ~StepItem();

private:
    Ui::StepItem *ui;

    // OVERRIDE Mouse events
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);

    void enterEvent(QEvent* event);
    void leaveEvent(QEvent* event);
};

#endif // STEPITEM_H
