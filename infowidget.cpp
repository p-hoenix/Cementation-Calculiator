#include "infowidget.h"
#include "ui_infowidget.h"
#include <QDebug>

InfoWidget::InfoWidget(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InfoWidget) {
    ui->setupUi(this);

    // Загружаем изображение
    QPixmap image(":/images/info.png");
}

InfoWidget::~InfoWidget() {
    delete ui;
}
