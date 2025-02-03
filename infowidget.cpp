#include "infowidget.h"
#include "ui_infowidget.h"
#include <QDebug>

InfoWidget::InfoWidget(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InfoWidget) {
    ui->setupUi(this);

    // Загружаем изображение
    QPixmap image(":/images/info.png");

    if (image.isNull()) {
        qDebug() << "Ошибка: изображение не загружено!";
    } else {
        ui->labelImage->setPixmap(image.scaled(ui->labelImage->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
}

InfoWidget::~InfoWidget() {
    delete ui;
}
