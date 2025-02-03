#ifndef INFOWIDGET_H
#define INFOWIDGET_H

#include <QDialog>

namespace Ui {
class InfoWidget;
}

class InfoWidget : public QDialog {
    Q_OBJECT

public:
    explicit InfoWidget(QWidget *parent = nullptr);
    ~InfoWidget();

private:
    Ui::InfoWidget *ui;
};

#endif // INFOWIDGET_H
