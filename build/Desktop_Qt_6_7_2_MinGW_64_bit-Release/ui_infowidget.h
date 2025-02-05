/********************************************************************************
** Form generated from reading UI file 'infowidget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFOWIDGET_H
#define UI_INFOWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InfoWidget
{
public:
    QLabel *labelImage;

    void setupUi(QWidget *InfoWidget)
    {
        if (InfoWidget->objectName().isEmpty())
            InfoWidget->setObjectName("InfoWidget");
        InfoWidget->resize(510, 420);
        InfoWidget->setMaximumSize(QSize(510, 420));
        labelImage = new QLabel(InfoWidget);
        labelImage->setObjectName("labelImage");
        labelImage->setGeometry(QRect(10, 10, 493, 399));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelImage->sizePolicy().hasHeightForWidth());
        labelImage->setSizePolicy(sizePolicy);
        labelImage->setMinimumSize(QSize(493, 399));
        labelImage->setMaximumSize(QSize(380, 400));
        labelImage->setPixmap(QPixmap(QString::fromUtf8(":/images/images/Info.png")));
        labelImage->setScaledContents(true);
        labelImage->setAlignment(Qt::AlignmentFlag::AlignCenter);

        retranslateUi(InfoWidget);

        QMetaObject::connectSlotsByName(InfoWidget);
    } // setupUi

    void retranslateUi(QWidget *InfoWidget)
    {
        InfoWidget->setWindowTitle(QCoreApplication::translate("InfoWidget", "Form", nullptr));
        labelImage->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class InfoWidget: public Ui_InfoWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFOWIDGET_H
