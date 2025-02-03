#ifndef INPUTHELPER_H
#define INPUTHELPER_H

#include <QString>
#include <QLineEdit>
#include <QRegularExpression>

class InputHelper
{
public:
    void updatePlaceholderTexts();
    static QString filterDigitsOnly(const QString &input);
    static void setPlaceholders(QLineEdit *depthLineEdit, QLineEdit *wellDiameterLineEdit,
                                QLineEdit *columnDiameterLineEdit, QLineEdit *innerDiameterLineEdit,
                                QLineEdit *wallThicknessLineEdit, QLineEdit *cementHeightLineEdit,
                                QLineEdit *cavernosityCoeffLineEdit);
    static QString replaceCommaWithDot(const QString &input);
    static bool isValidNumber(const QString &input);
    static void updatePlaceholderTexts(QLineEdit* fields[], const QString& placeholderText);
};

#endif // INPUTHELPER_H
