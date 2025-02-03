#include "inputhelper.h"

bool InputHelper::isValidNumber(const QString &input)
{
    QRegularExpression regex("^-?\\d*\\.?\\d+$");
    return regex.match(input).hasMatch();
}

QString InputHelper::replaceCommaWithDot(const QString &input)
{
    QString result = input; // Создаём копию строки
    result.replace(",", "."); // Изменяем копию
    return result; // Возвращаем изменённую копию
}

QString InputHelper::filterDigitsOnly(const QString &input)
{
    QString filteredInput;
    for (QChar c : input) {
        if (c.isDigit() || c == '.' || c == '-') {
            filteredInput.append(c);
        }
    }
    return filteredInput;
}

void InputHelper::setPlaceholders(QLineEdit *depthLineEdit, QLineEdit *wellDiameterLineEdit,
                                  QLineEdit *columnDiameterLineEdit, QLineEdit *innerDiameterLineEdit,
                                  QLineEdit *wallThicknessLineEdit, QLineEdit *cementHeightLineEdit,
                                  QLineEdit *cavernosityCoeffLineEdit) {
    if (depthLineEdit) depthLineEdit->setPlaceholderText("H (м)");
    if (wellDiameterLineEdit) wellDiameterLineEdit->setPlaceholderText("D (м)");
    if (columnDiameterLineEdit) columnDiameterLineEdit->setPlaceholderText("d1 (м)");
    if (innerDiameterLineEdit) innerDiameterLineEdit->setPlaceholderText("d2 (м)");
    if (wallThicknessLineEdit) wallThicknessLineEdit->setPlaceholderText("t (м)");
    if (cementHeightLineEdit) cementHeightLineEdit->setPlaceholderText("h (м)");
    if (cavernosityCoeffLineEdit) cavernosityCoeffLineEdit->setPlaceholderText("K");
}

void InputHelper::updatePlaceholderTexts(QLineEdit* fields[], const QString& normalizedText)
{
    for (int i = 0; i < 6; ++i) {
        if (fields[i]) {
            fields[i]->setText(normalizedText); // Устанавливаем текст
        }
    }
}
