#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QComboBox>
#include <QTextEdit>
#include <QMessageBox>
#include <cmath>
#include <QDockWidget>
#include "InfoWidget.h"
#include <QDoubleValidator>
#include <QIntValidator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupValidators();  // Добавляем валидацию

    // Установка заголовка окна
    setWindowTitle("Калькулятор цементувания обсадних колон");

    //Подсказки на кнопки
    ui->calculateD1Button->setToolTip("Розрахувати діаметр колони");
    ui->calculateD1Button_2->setToolTip("Розрахувати діаметр колони");
    ui->calculateD1Button_3->setToolTip("Розрахувати діаметр колони");
    ui->calculateD1Button_4->setToolTip("Розрахувати діаметр колони");
    ui->calculateD1Button_5->setToolTip("Розрахувати діаметр колони");
    ui->calculateD1Button_6->setToolTip("Розрахувати діаметр колони");

    ui->calculateD2Button->setToolTip("Розрахувати внутрішній діаметр колони");
    ui->calculateD2Button_2->setToolTip("Розрахувати внутрішній діаметр колони");
    ui->calculateD2Button_3->setToolTip("Розрахувати внутрішній діаметр колони");
    ui->calculateD2Button_4->setToolTip("Розрахувати внутрішній діаметр колони");
    ui->calculateD2Button_5->setToolTip("Розрахувати внутрішній діаметр колони");
    ui->calculateD2Button_6->setToolTip("Розрахувати внутрішній діаметр колони");

    ui->calculateTButton->setToolTip("Розрахувати товщину стінки колони");
    ui->calculateTButton_2->setToolTip("Розрахувати товщину стінки колони");
    ui->calculateTButton_3->setToolTip("Розрахувати товщину стінки колони");
    ui->calculateTButton_4->setToolTip("Розрахувати товщину стінки колони");
    ui->calculateTButton_5->setToolTip("Розрахувати товщину стінки колони");
    ui->calculateTButton_6->setToolTip("Розрахувати товщину стінки колони");

    connect(ui->About, &QAction::triggered, this, &MainWindow::about);
    connect(ui->calculateD1Button, &QPushButton::clicked, this, &MainWindow::on_calculateD1Button_clicked);
    connect(ui->calculateD2Button, &QPushButton::clicked, this, &MainWindow::on_calculateD2Button_clicked);
    connect(ui->calculateTButton, &QPushButton::clicked, this, &MainWindow::on_calculateTButton_clicked);

    connect(ui->showDetailedInfo, &QPushButton::clicked, this, &MainWindow::showDetailedInfo);

    // Подключаем обработку ввода для всех полей
    connect(ui->depthLineEdit, &QLineEdit::textChanged, this, &MainWindow::normalizeInput);
    connect(ui->wellDiameterLineEdit, &QLineEdit::textChanged, this, &MainWindow::normalizeInput);
    connect(ui->columnDiameterLineEdit, &QLineEdit::textChanged, this, &MainWindow::normalizeInput);
    connect(ui->innerDiameterLineEdit, &QLineEdit::textChanged, this, &MainWindow::normalizeInput);
    connect(ui->wallThicknessLineEdit, &QLineEdit::textChanged, this, &MainWindow::normalizeInput);
    connect(ui->cementHeightLineEdit, &QLineEdit::textChanged, this, &MainWindow::normalizeInput);
    connect(ui->cavernosityCoeffLineEdit, &QLineEdit::textChanged, this, &MainWindow::normalizeInput);

    connect(ui->depthLineEdit_2, &QLineEdit::textChanged, this, &MainWindow::normalizeInput);
    connect(ui->wellDiameterLineEdit_2, &QLineEdit::textChanged, this, &MainWindow::normalizeInput);
    connect(ui->columnDiameterLineEdit_2, &QLineEdit::textChanged, this, &MainWindow::normalizeInput);
    connect(ui->innerDiameterLineEdit_2, &QLineEdit::textChanged, this, &MainWindow::normalizeInput);
    connect(ui->wallThicknessLineEdit_2, &QLineEdit::textChanged, this, &MainWindow::normalizeInput);
    connect(ui->cementHeightLineEdit_2, &QLineEdit::textChanged, this, &MainWindow::normalizeInput);
    connect(ui->cavernosityCoeffLineEdit_2, &QLineEdit::textChanged, this, &MainWindow::normalizeInput);

    connect(ui->depthLineEdit_3, &QLineEdit::textChanged, this, &MainWindow::normalizeInput);
    connect(ui->wellDiameterLineEdit_3, &QLineEdit::textChanged, this, &MainWindow::normalizeInput);
    connect(ui->columnDiameterLineEdit_3, &QLineEdit::textChanged, this, &MainWindow::normalizeInput);
    connect(ui->innerDiameterLineEdit_3, &QLineEdit::textChanged, this, &MainWindow::normalizeInput);
    connect(ui->wallThicknessLineEdit_3, &QLineEdit::textChanged, this, &MainWindow::normalizeInput);
    connect(ui->cementHeightLineEdit_3, &QLineEdit::textChanged, this, &MainWindow::normalizeInput);
    connect(ui->cavernosityCoeffLineEdit_3, &QLineEdit::textChanged, this, &MainWindow::normalizeInput);

    connect(ui->depthLineEdit_4, &QLineEdit::textChanged, this, &MainWindow::normalizeInput);
    connect(ui->wellDiameterLineEdit_4, &QLineEdit::textChanged, this, &MainWindow::normalizeInput);
    connect(ui->columnDiameterLineEdit_4, &QLineEdit::textChanged, this, &MainWindow::normalizeInput);
    connect(ui->innerDiameterLineEdit_4, &QLineEdit::textChanged, this, &MainWindow::normalizeInput);
    connect(ui->wallThicknessLineEdit_4, &QLineEdit::textChanged, this, &MainWindow::normalizeInput);
    connect(ui->cementHeightLineEdit_4, &QLineEdit::textChanged, this, &MainWindow::normalizeInput);
    connect(ui->cavernosityCoeffLineEdit_4, &QLineEdit::textChanged, this, &MainWindow::normalizeInput);

    connect(ui->depthLineEdit_5, &QLineEdit::textChanged, this, &MainWindow::normalizeInput);
    connect(ui->wellDiameterLineEdit_5, &QLineEdit::textChanged, this, &MainWindow::normalizeInput);
    connect(ui->columnDiameterLineEdit_5, &QLineEdit::textChanged, this, &MainWindow::normalizeInput);
    connect(ui->innerDiameterLineEdit_5, &QLineEdit::textChanged, this, &MainWindow::normalizeInput);
    connect(ui->wallThicknessLineEdit_5, &QLineEdit::textChanged, this, &MainWindow::normalizeInput);
    connect(ui->cementHeightLineEdit_5, &QLineEdit::textChanged, this, &MainWindow::normalizeInput);
    connect(ui->cavernosityCoeffLineEdit_5, &QLineEdit::textChanged, this, &MainWindow::normalizeInput);

    connect(ui->depthLineEdit_6, &QLineEdit::textChanged, this, &MainWindow::normalizeInput);
    connect(ui->wellDiameterLineEdit_6, &QLineEdit::textChanged, this, &MainWindow::normalizeInput);
    connect(ui->columnDiameterLineEdit_6, &QLineEdit::textChanged, this, &MainWindow::normalizeInput);
    connect(ui->innerDiameterLineEdit_6, &QLineEdit::textChanged, this, &MainWindow::normalizeInput);
    connect(ui->wallThicknessLineEdit_6, &QLineEdit::textChanged, this, &MainWindow::normalizeInput);
    connect(ui->cementHeightLineEdit_6, &QLineEdit::textChanged, this, &MainWindow::normalizeInput);
    connect(ui->cavernosityCoeffLineEdit_6, &QLineEdit::textChanged, this, &MainWindow::normalizeInput);

    //Проверка на правильность данных
    connect(ui->depthLineEdit, &QLineEdit::textChanged, this, &MainWindow::updateCalculateButtonState);
    connect(ui->wellDiameterLineEdit, &QLineEdit::textChanged, this, &MainWindow::updateCalculateButtonState);
    connect(ui->columnDiameterLineEdit, &QLineEdit::textChanged, this, &MainWindow::updateCalculateButtonState);
    connect(ui->innerDiameterLineEdit, &QLineEdit::textChanged, this, &MainWindow::updateCalculateButtonState);
    connect(ui->wallThicknessLineEdit, &QLineEdit::textChanged, this, &MainWindow::updateCalculateButtonState);
    connect(ui->cementHeightLineEdit, &QLineEdit::textChanged, this, &MainWindow::updateCalculateButtonState);
    connect(ui->cavernosityCoeffLineEdit, &QLineEdit::textChanged, this, &MainWindow::updateCalculateButtonState);

    connect(ui->depthLineEdit_2, &QLineEdit::textChanged, this, &MainWindow::updateCalculateButtonState);
    connect(ui->wellDiameterLineEdit_2, &QLineEdit::textChanged, this, &MainWindow::updateCalculateButtonState);
    connect(ui->columnDiameterLineEdit_2, &QLineEdit::textChanged, this, &MainWindow::updateCalculateButtonState);
    connect(ui->innerDiameterLineEdit_2, &QLineEdit::textChanged, this, &MainWindow::updateCalculateButtonState);
    connect(ui->wallThicknessLineEdit_2, &QLineEdit::textChanged, this, &MainWindow::updateCalculateButtonState);
    connect(ui->cementHeightLineEdit_2, &QLineEdit::textChanged, this, &MainWindow::updateCalculateButtonState);
    connect(ui->cavernosityCoeffLineEdit_2, &QLineEdit::textChanged, this, &MainWindow::updateCalculateButtonState);

    connect(ui->depthLineEdit_3, &QLineEdit::textChanged, this, &MainWindow::updateCalculateButtonState);
    connect(ui->wellDiameterLineEdit_3, &QLineEdit::textChanged, this, &MainWindow::updateCalculateButtonState);
    connect(ui->columnDiameterLineEdit_3, &QLineEdit::textChanged, this, &MainWindow::updateCalculateButtonState);
    connect(ui->innerDiameterLineEdit_3, &QLineEdit::textChanged, this, &MainWindow::updateCalculateButtonState);
    connect(ui->wallThicknessLineEdit_3, &QLineEdit::textChanged, this, &MainWindow::updateCalculateButtonState);
    connect(ui->cementHeightLineEdit_3, &QLineEdit::textChanged, this, &MainWindow::updateCalculateButtonState);
    connect(ui->cavernosityCoeffLineEdit_3, &QLineEdit::textChanged, this, &MainWindow::updateCalculateButtonState);

    connect(ui->depthLineEdit_4, &QLineEdit::textChanged, this, &MainWindow::updateCalculateButtonState);
    connect(ui->wellDiameterLineEdit_4, &QLineEdit::textChanged, this, &MainWindow::updateCalculateButtonState);
    connect(ui->columnDiameterLineEdit_4, &QLineEdit::textChanged, this, &MainWindow::updateCalculateButtonState);
    connect(ui->innerDiameterLineEdit_4, &QLineEdit::textChanged, this, &MainWindow::updateCalculateButtonState);
    connect(ui->wallThicknessLineEdit_4, &QLineEdit::textChanged, this, &MainWindow::updateCalculateButtonState);
    connect(ui->cementHeightLineEdit_4, &QLineEdit::textChanged, this, &MainWindow::updateCalculateButtonState);
    connect(ui->cavernosityCoeffLineEdit_4, &QLineEdit::textChanged, this, &MainWindow::updateCalculateButtonState);

    connect(ui->depthLineEdit_5, &QLineEdit::textChanged, this, &MainWindow::updateCalculateButtonState);
    connect(ui->wellDiameterLineEdit_5, &QLineEdit::textChanged, this, &MainWindow::updateCalculateButtonState);
    connect(ui->columnDiameterLineEdit_5, &QLineEdit::textChanged, this, &MainWindow::updateCalculateButtonState);
    connect(ui->innerDiameterLineEdit_5, &QLineEdit::textChanged, this, &MainWindow::updateCalculateButtonState);
    connect(ui->wallThicknessLineEdit_5, &QLineEdit::textChanged, this, &MainWindow::updateCalculateButtonState);
    connect(ui->cementHeightLineEdit_5, &QLineEdit::textChanged, this, &MainWindow::updateCalculateButtonState);
    connect(ui->cavernosityCoeffLineEdit_5, &QLineEdit::textChanged, this, &MainWindow::updateCalculateButtonState);

    connect(ui->depthLineEdit_6, &QLineEdit::textChanged, this, &MainWindow::updateCalculateButtonState);
    connect(ui->wellDiameterLineEdit_6, &QLineEdit::textChanged, this, &MainWindow::updateCalculateButtonState);
    connect(ui->columnDiameterLineEdit_6, &QLineEdit::textChanged, this, &MainWindow::updateCalculateButtonState);
    connect(ui->innerDiameterLineEdit_6, &QLineEdit::textChanged, this, &MainWindow::updateCalculateButtonState);
    connect(ui->wallThicknessLineEdit_6, &QLineEdit::textChanged, this, &MainWindow::updateCalculateButtonState);
    connect(ui->cementHeightLineEdit_6, &QLineEdit::textChanged, this, &MainWindow::updateCalculateButtonState);
    connect(ui->cavernosityCoeffLineEdit_6, &QLineEdit::textChanged, this, &MainWindow::updateCalculateButtonState);

    // Обновляем состояние кнопки при запуске
    updateCalculateButtonState();


    // Создание виджетов для расчётов
    QWidget *window1 = new QWidget(this);
    QVBoxLayout *layout1 = new QVBoxLayout(window1);
    layout1->addWidget(new QLabel("Расчёт для 1 колонны", window1));

    QWidget *window2 = new QWidget(this);
    QVBoxLayout *layout2 = new QVBoxLayout(window2);
    layout2->addWidget(new QLabel("Расчёт для 2 колонн", window2));

    QWidget *window3 = new QWidget(this);
    QVBoxLayout *layout3 = new QVBoxLayout(window3);
    layout3->addWidget(new QLabel("Расчёт для 3 колонн", window3));

    // Добавляем виджеты в QStackedWidget
    ui->stackedWidget->addWidget(window1);
    ui->stackedWidget->addWidget(window2);
    ui->stackedWidget->addWidget(window3);

    //Добавим подсказки к полям ввода
    ui->depthLineEdit->setPlaceholderText("H (м)");
    ui->wellDiameterLineEdit->setPlaceholderText("D (м)");
    ui->columnDiameterLineEdit->setPlaceholderText("d1 (м)");
    ui->innerDiameterLineEdit->setPlaceholderText("d2 (м)");
    ui->wallThicknessLineEdit->setPlaceholderText("t (м)");
    ui->cementHeightLineEdit->setPlaceholderText("h (м)");
    ui->cavernosityCoeffLineEdit->setPlaceholderText("K");

    ui->depthLineEdit_2->setPlaceholderText("H (м)");
    ui->wellDiameterLineEdit_2->setPlaceholderText("D (м)");
    ui->columnDiameterLineEdit_2->setPlaceholderText("d1 (м)");
    ui->wallThicknessLineEdit_2->setPlaceholderText("t (м)");
    ui->innerDiameterLineEdit_2->setPlaceholderText("d2 (м)");
    ui->cementHeightLineEdit_2->setPlaceholderText("h (м)");
    ui->cavernosityCoeffLineEdit_2->setPlaceholderText("K");

    ui->depthLineEdit_3->setPlaceholderText("H (м)");
    ui->wellDiameterLineEdit_3->setPlaceholderText("D (м)");
    ui->columnDiameterLineEdit_3->setPlaceholderText("d1 (м)");
    ui->wallThicknessLineEdit_3->setPlaceholderText("t (м)");
    ui->innerDiameterLineEdit_3->setPlaceholderText("d2 (м)");
    ui->cementHeightLineEdit_3->setPlaceholderText("h (м)");
    ui->cavernosityCoeffLineEdit_3->setPlaceholderText("K");

    ui->depthLineEdit_4->setPlaceholderText("H (м)");
    ui->wellDiameterLineEdit_4->setPlaceholderText("D (м)");
    ui->columnDiameterLineEdit_4->setPlaceholderText("d1 (м)");
    ui->innerDiameterLineEdit_4->setPlaceholderText("d2 (м)");
    ui->wallThicknessLineEdit_4->setPlaceholderText("t (м)");
    ui->cementHeightLineEdit_4->setPlaceholderText("h (м)");
    ui->cavernosityCoeffLineEdit_4->setPlaceholderText("K");

    ui->depthLineEdit_5->setPlaceholderText("H (м)");
    ui->wellDiameterLineEdit_5->setPlaceholderText("D (м)");
    ui->columnDiameterLineEdit_5->setPlaceholderText("d1 (м)");
    ui->wallThicknessLineEdit_5->setPlaceholderText("t (м)");
    ui->innerDiameterLineEdit_5->setPlaceholderText("d2 (м)");
    ui->cementHeightLineEdit_5->setPlaceholderText("h (м)");
    ui->cavernosityCoeffLineEdit_5->setPlaceholderText("K");

    ui->depthLineEdit_6->setPlaceholderText("H (м)");
    ui->wellDiameterLineEdit_6->setPlaceholderText("D (м)");
    ui->columnDiameterLineEdit_6->setPlaceholderText("d1 (м)");
    ui->wallThicknessLineEdit_6->setPlaceholderText("t (м)");
    ui->innerDiameterLineEdit_6->setPlaceholderText("d2 (м)");
    ui->cementHeightLineEdit_6->setPlaceholderText("h (м)");
    ui->cavernosityCoeffLineEdit_6->setPlaceholderText("K");


    // Устанавливаем начальный виджет
    ui->stackedWidget->setCurrentIndex(0);

    // Подключаем QComboBox для выбора типа колонки
    connect(ui->wellTypeComboBox, SIGNAL(currentIndexChanged(int)),
            this, SLOT(on_wellTypeComboBox_currentIndexChanged(int)));

    // Подключаем кнопку для вычислений
    connect(ui->calculateButton, &QPushButton::clicked, this, &MainWindow::calculateResults);
    connect(ui->calculateButton_2, &QPushButton::clicked, this, &MainWindow::calculateResults_2);
    connect(ui->calculateButton_3, &QPushButton::clicked, this, &MainWindow::calculateResults_3);
    connect(ui->textEdit, &QTextEdit::textChanged, this, &MainWindow::updateErrorLabel);


    // Создаём поле для вывода результатов
    resultsTextEdit = new QTextEdit(this);
    resultsTextEdit->setReadOnly(true);
    layout1->addWidget(resultsTextEdit);

    resultsTextEdit_2 = new QTextEdit(this);
    resultsTextEdit_2->setReadOnly(true);
    layout1->addWidget(resultsTextEdit_2);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showDetailedInfo() {
    if (infoWindow) {
        if (infoWindow->isVisible()) {
            infoWindow->close(); // Если уже открыто, закрываем
        } else {
            infoWindow->show();  // Если закрыто, показываем
        }
        return;
    }

    // Создаём окно один раз
    infoWindow = new InfoWidget(this);

    // Размещаем окно справа от основного
    QPoint mainPos = this->geometry().topRight();  // Правая граница главного окна
    infoWindow->move(mainPos + QPoint(2, 0));     // Смещаем на 2 пикселя вправо

    infoWindow->show();
}

void MainWindow::setupValidators() {
    // Установим валидаторы для полей
    QIntValidator* intValidator = new QIntValidator(0, 1000000, this);  // Для целых чисел от 0 до 1000000
    QDoubleValidator* doubleValidator = new QDoubleValidator(0, 1000000, 2, this);  // Для чисел с плавающей точкой

    // Применяем валидаторы для первой колонки
    ui->depthLineEdit->setValidator(doubleValidator);
    ui->wellDiameterLineEdit->setValidator(doubleValidator);
    ui->columnDiameterLineEdit->setValidator(doubleValidator);
    ui->innerDiameterLineEdit->setValidator(doubleValidator);
    ui->wallThicknessLineEdit->setValidator(doubleValidator);
    ui->cementHeightLineEdit->setValidator(doubleValidator);
    ui->cavernosityCoeffLineEdit->setValidator(doubleValidator);

    // Применяем валидаторы для второй колонки
    ui->depthLineEdit_2->setValidator(doubleValidator);
    ui->wellDiameterLineEdit_2->setValidator(doubleValidator);
    ui->columnDiameterLineEdit_2->setValidator(doubleValidator);
    ui->innerDiameterLineEdit_2->setValidator(doubleValidator);
    ui->wallThicknessLineEdit_2->setValidator(doubleValidator);
    ui->cementHeightLineEdit_2->setValidator(doubleValidator);
    ui->cavernosityCoeffLineEdit_2->setValidator(doubleValidator);

    // Применяем валидаторы для третьей колонки
    ui->depthLineEdit_3->setValidator(doubleValidator);
    ui->wellDiameterLineEdit_3->setValidator(doubleValidator);
    ui->columnDiameterLineEdit_3->setValidator(doubleValidator);
    ui->innerDiameterLineEdit_3->setValidator(doubleValidator);
    ui->wallThicknessLineEdit_3->setValidator(doubleValidator);
    ui->cementHeightLineEdit_3->setValidator(doubleValidator);
    ui->cavernosityCoeffLineEdit_3->setValidator(doubleValidator);

    // Применяем валидаторы для четвертой колонки
    ui->depthLineEdit_4->setValidator(doubleValidator);
    ui->wellDiameterLineEdit_4->setValidator(doubleValidator);
    ui->columnDiameterLineEdit_4->setValidator(doubleValidator);
    ui->innerDiameterLineEdit_4->setValidator(doubleValidator);
    ui->wallThicknessLineEdit_4->setValidator(doubleValidator);
    ui->cementHeightLineEdit_4->setValidator(doubleValidator);
    ui->cavernosityCoeffLineEdit_4->setValidator(doubleValidator);

    // Применяем валидаторы для пятой колонки
    ui->depthLineEdit_5->setValidator(doubleValidator);
    ui->wellDiameterLineEdit_5->setValidator(doubleValidator);
    ui->columnDiameterLineEdit_5->setValidator(doubleValidator);
    ui->innerDiameterLineEdit_5->setValidator(doubleValidator);
    ui->wallThicknessLineEdit_5->setValidator(doubleValidator);
    ui->cementHeightLineEdit_5->setValidator(doubleValidator);
    ui->cavernosityCoeffLineEdit_5->setValidator(doubleValidator);

    // Применяем валидаторы для шестой колонки
    ui->depthLineEdit_6->setValidator(doubleValidator);
    ui->wellDiameterLineEdit_6->setValidator(doubleValidator);
    ui->columnDiameterLineEdit_6->setValidator(doubleValidator);
    ui->innerDiameterLineEdit_6->setValidator(doubleValidator);
    ui->wallThicknessLineEdit_6->setValidator(doubleValidator);
    ui->cementHeightLineEdit_6->setValidator(doubleValidator);
    ui->cavernosityCoeffLineEdit_6->setValidator(doubleValidator);
}

void MainWindow::on_wellTypeComboBox_currentIndexChanged(int index)
{
    // Меняем отображаемый виджет в зависимости от выбранного типа колонки
    ui->stackedWidget->setCurrentIndex(index);
}

void MainWindow::createActions()
{
    // Действие для информации о программе
    QAction *aboutAction = new QAction("Про програму", this);
    connect(aboutAction, &QAction::triggered, this, &abort);

    // Меню Помощь
    QMenu *helpMenu = menuBar()->addMenu("Допомога");
    helpMenu->addAction(aboutAction);
}

void MainWindow::about()
{
    QMessageBox::about(this, "Про програму",
                       "<h2>CementCalc 1.1.0</h2>"
                       "<p><b>Програма для розрахунку матеріалів цементації обсадних колон.</b></p>"
                       "<p>Функціонал:</p>"
                       "<ul>"
                       "<li>Розрахунок об'єму тампонажного розчину</li>"
                       "<li>Облік коефіцієнта кавернозності</li>"
                       "<li>Розрахунок витрати цементу та води</li>"
                       "<li>Гнучке налаштування параметрів свердловини</li>"
                       "</ul>"
                       "<p>Автор: Ігор Скороход</p>"
                       "<p>Контакт: ck.ig.ba@gmail.com<br>"
                       "Телефон: +380 (66) 789-07-56</p>"
                       "<p><i>© 2025 Phoenix group. Усі права захищені.</i></p>");
}

void MainWindow::normalizeInput()
{
    QLineEdit *senderLineEdit = qobject_cast<QLineEdit *>(sender());
    if (senderLineEdit) {
        QString text = senderLineEdit->text();
        text.replace(',', '.');  // Заменяем запятую на точку
        senderLineEdit->setText(text);
    }
}

bool MainWindow::validateInput()
{
    // Проверяем, что все поля заполнены
    QList<QLineEdit *> fields = {
        ui->depthLineEdit,
        ui->wellDiameterLineEdit,
        ui->columnDiameterLineEdit,
        ui->wallThicknessLineEdit,
        ui->cementHeightLineEdit,
        ui->cavernosityCoeffLineEdit,
        ui->depthLineEdit_2,
        ui->wellDiameterLineEdit_2,
        ui->columnDiameterLineEdit_2,
        ui->innerDiameterLineEdit_2,
        ui->cementHeightLineEdit_2,
        ui->cavernosityCoeffLineEdit_2,
        ui->depthLineEdit_3,
        ui->wellDiameterLineEdit_3,
        ui->columnDiameterLineEdit_3,
        ui->innerDiameterLineEdit_3,
        ui->cementHeightLineEdit_3,
        ui->cavernosityCoeffLineEdit_3,
        ui->depthLineEdit_4,
        ui->wellDiameterLineEdit_4,
        ui->columnDiameterLineEdit_4,
        ui->innerDiameterLineEdit_4,
        ui->cementHeightLineEdit_4,
        ui->cavernosityCoeffLineEdit_4,
        ui->depthLineEdit_5,
        ui->wellDiameterLineEdit_5,
        ui->columnDiameterLineEdit_5,
        ui->innerDiameterLineEdit_5,
        ui->cementHeightLineEdit_5,
        ui->cavernosityCoeffLineEdit_5,
        ui->depthLineEdit_6,
        ui->wellDiameterLineEdit_6,
        ui->columnDiameterLineEdit_6,
        ui->innerDiameterLineEdit_6,
        ui->cementHeightLineEdit_6,
        ui->cavernosityCoeffLineEdit_6
    };

    for (QLineEdit *field : fields) {
        if (field->text().isEmpty()) {
            QMessageBox::warning(this, "Ошибка ввода", "Все поля должны быть заполнены!");
            return false;
        }

        bool ok;
        double value = field->text().toDouble(&ok);

        if (!ok || value <= 0) {
            QMessageBox::warning(this, "Ошибка ввода", "Все значения должны быть положительными числами!");
            return false;
        }
    }

    // Проверяем логические зависимости
    double D = ui->wellDiameterLineEdit_2->text().toDouble();
    double D_1 = ui->wellDiameterLineEdit_2->text().toDouble();
    double D_2 = ui->wellDiameterLineEdit_3->text().toDouble();
    double d = ui->columnDiameterLineEdit->text().toDouble();
    double d_1 = ui->columnDiameterLineEdit_2->text().toDouble();
    double d_2 = ui->columnDiameterLineEdit_3->text().toDouble();
    double t = ui->wallThicknessLineEdit->text().toDouble();
    double t_1 = ui->wallThicknessLineEdit_2->text().toDouble();
    double t_2 = ui->wallThicknessLineEdit_3->text().toDouble();

    // Проверяем логические зависимости для второй колоны
    double D__2 = ui->wellDiameterLineEdit_4->text().toDouble();
    double D_1_2 = ui->wellDiameterLineEdit_5->text().toDouble();
    double D_2_2 = ui->wellDiameterLineEdit_6->text().toDouble();
    double d__2 = ui->columnDiameterLineEdit_4->text().toDouble();
    double d_1_2 = ui->columnDiameterLineEdit_5->text().toDouble();
    double d_2_2 = ui->columnDiameterLineEdit_6->text().toDouble();
    double t__2 = ui->wallThicknessLineEdit_4->text().toDouble();
    double t_1_2 = ui->wallThicknessLineEdit_5->text().toDouble();
    double t_2_2 = ui->wallThicknessLineEdit_6->text().toDouble();

    if (d + 2 * t >= D) {
        QMessageBox::warning(this, "Ошибка ввода", "Диаметр колонки с учётом толщины стенок не может превышать диаметр скважины!");
        return false;
    }
    if (d_1 + 2 * t_1 >= D_1) {
        QMessageBox::warning(this, "Ошибка ввода", "Диаметр колонки с учётом толщины стенок не может превышать диаметр скважины!");
        return false;
    }
    if (d_2 + 2 * t_2 >= D_2) {
        QMessageBox::warning(this, "Ошибка ввода", "Диаметр колонки с учётом толщины стенок не может превышать диаметр скважины!");
        return false;
    }
    if (d__2 + 2 * t__2 >= D__2) {
        QMessageBox::warning(this, "Ошибка ввода", "Диаметр колонки с учётом толщины стенок не может превышать диаметр скважины!");
        return false;
    }
    if (d_1_2 + 2 * t_1_2 >= D_1_2) {
        QMessageBox::warning(this, "Ошибка ввода", "Диаметр колонки с учётом толщины стенок не может превышать диаметр скважины!");
        return false;
    }
    if (d_2_2 + 2 * t_2_2 >= D_2_2) {
        QMessageBox::warning(this, "Ошибка ввода", "Диаметр колонки с учётом толщины стенок не может превышать диаметр скважины!");
        return false;
    }
    return true;
}

void MainWindow::calculateResults() {
    // Чтение данных с формы
    double H = ui->depthLineEdit->text().toDouble();             // Глубина
    double D = ui->wellDiameterLineEdit->text().toDouble();      // Диаметр скважины
    double d1 = ui->columnDiameterLineEdit->text().toDouble();   // Внешний диаметр колонны
    double d2 = ui->innerDiameterLineEdit->text().toDouble();    // Внутренний диаметр колонны
    // Чтение значения для толщины стенки колонны (необязательное поле)
    QString tText = ui->wallThicknessLineEdit->text();  // Получаем текст из поля ввода
    double t = tText.isEmpty() ? 0 : tText.toDouble();  // Если поле пустое, присваиваем 0, иначе преобразуем в число
    double h = ui->cementHeightLineEdit->text().toDouble();      // Высота цементации
    double K = ui->cavernosityCoeffLineEdit->text().toDouble();  // Коэффициент кавернозности

    // Проверка входных данных
    if (D <= 0 || d1 <= 0 || d2 <= 0) {
        ui->errorLabel->setText("Ошибка: все размеры должны быть положительными числами.");
        return;
    }
    if (d1 <= d2) {
        ui->errorLabel->setText("Ошибка: внутренний диаметр колонны должен быть меньше внешнего диаметра.");
        return;
    }
    if (d1 >= D) {
        ui->errorLabel->setText("Ошибка: внешний диаметр колонны должен быть меньше диаметра скважины.");
        return;
    }
    if (d2 >= D) {
        ui->errorLabel->setText("Ошибка: внутренний диаметр колонны должен быть меньше диаметра скважины.");
        return;
    }
    if (H <= 0 || h < 0 || K <= 0 || t < 0) {
        ui->errorLabel->setText("Ошибка: проверьте введённые значения.");
        return;
    }
    if (t < 0 && !tText.isEmpty()) {
        ui->errorLabel->setText("Ошибка: проверьте введённые значения.");
        return;
    }
    if (h > H) {
        ui->errorLabel->setText("Ошибка: высота цементного стакана не может быть больше глубины спуска.");
        return;
    }

    // Расчёт объёмов
    double Vцр = 0.785 * (pow(D, 2) - pow(d1, 2)) * H * K + 0.785 * pow(d2, 2) * h;  // Объём тампонажного раствора

    // Дополнительный расчёт с t (если нужно)
    if (t > 0) {
        // Тут можно учесть t, например, в расчёте объёма цементного раствора или других величин
    }

    // Объём промывочной жидкости (если H > h)
    double Vпр = (H > h) ? (0.785 * pow(d2, 2) * (H - h)) : 0;

    // Корректировка отрицательных значений
    if (Vцр < 0) Vцр = 0;
    if (Vпр < 0) Vпр = 0;

    // Расчёт цемента и воды
    double Qц = Vцр * 1.23 * 1.05;  // Необходимое количество цемента
    double Vв = Vцр * 0.6 * 1.5;    // Необходимое количество воды

    // Вывод результатов
    ui->resultsTextEdit->setText(QString(
                                     "Объем тампонажного раствора: %1 м³\n"
                                     "Объем промывочной жидкости: %2 м³\n"
                                     "Необходимое количество цемента: %3 т\n"
                                     "Необходимое количество воды: %4 м³")
                                     .arg(Vцр + Vпр, 0, 'f', 4)
                                     .arg(Vпр, 0, 'f', 4)
                                     .arg(Qц, 0, 'f', 4)
                                     .arg(Vв, 0, 'f', 4));
}


void MainWindow::calculateResults_3()
{
    // Чтение данных с формы
    double H = ui->depthLineEdit->text().toDouble();             // Глубина
    double D = ui->wellDiameterLineEdit->text().toDouble();      // Диаметр скважины
    double d1 = ui->columnDiameterLineEdit->text().toDouble();   // Внешний диаметр колонны
    double d2 = ui->innerDiameterLineEdit->text().toDouble();    // Внутренний диаметр колонны
    // Чтение значения для толщины стенки колонны (необязательное поле)
    QString tText = ui->wallThicknessLineEdit->text();  // Получаем текст из поля ввода
    double t = tText.isEmpty() ? 0 : tText.toDouble();  // Если поле пустое, присваиваем 0, иначе преобразуем в число
    double h = ui->cementHeightLineEdit->text().toDouble();      // Высота цементации
    double K = ui->cavernosityCoeffLineEdit->text().toDouble();  // Коэффициент кавернозности

    // Проверка входных данных
    // Проверяем логическую последовательность диаметров
    if (D <= 0 || d1 <= 0 || d2 <= 0) {
        ui->errorLabel->setText("Ошибка: все размеры должны быть положительными числами.");
        return;
    }
    if (d1 <= d2) {
        ui->errorLabel->setText("Ошибка: внутренний диаметр колонны должен быть меньше внешнего диаметра.");
        return;
    }
    if (d1 >= D) {
        ui->errorLabel->setText("Ошибка: внешний диаметр колонны должен быть меньше диаметра скважины.");
        return;
    }
    if (d2 >= D) {
        ui->errorLabel->setText("Ошибка: внутренний диаметр колонны должен быть меньше диаметра скважины.");
        return;
    }
    if (H <= 0 || h < 0 || K <= 0 || t < 0) {
        ui->errorLabel->setText("Ошибка: проверьте введённые значения.");
        return;
    }
    // Проверка на отрицательную толщину только если поле не пустое
    if (t < 0 && !tText.isEmpty()) {
        ui->errorLabel->setText("Ошибка: проверьте введённые значения.");
        return;
    }
    // Проверка, что высота цементного стакана не может быть больше глубины
    if (h > H) {
        ui->errorLabel->setText("Ошибка: высота цементного стакана не может быть больше глубины спуска.");
        return;
    }

    // Расчёт объёмов
    // Расчёт объёма тампонажного раствора с учетом толщины стенки колонны
    double Vцр = 0.785 * (D * D - d1 * d1) * H * K + 0.785 * d2 * d2 * h;  // Объём тампонажного раствора
    // Дополнительный расчет с t (если нужно)
    if (t > 0) {
        // Здесь можно добавить код для учета t в других расчетах
    }
    double Vпр = (H > h) ? (0.785 * d2 * d2 * (H - h)) : 0;                // Объём промывочной жидкости

    // Корректировка отрицательных значений
    if (Vцр < 0) Vцр = 0;
    if (Vпр < 0) Vпр = 0;

    // Расчёт цемента и воды
    double Qц = Vцр * 1.23 * 1.05;  // Необходимое количество цемента
    double Vв = Vцр * 0.6 * 1.5;    // Необходимое количество воды

    // Вывод результатов
    ui->resultsTextEdit->setText(QString(
                                     "Объем тампонажного раствора: %1 м³\n"
                                     "Объем промывочной жидкости: %2 м³\n"
                                     "Необходимое количество цемента: %3 т\n"
                                     "Необходимое количество воды: %4 м³")
                                     .arg(Vцр + Vпр, 0, 'f', 4)
                                     .arg(Vпр, 0, 'f', 4)
                                     .arg(Qц, 0, 'f', 4)
                                     .arg(Vв, 0, 'f', 4));
}

void MainWindow::calculateResults_2()
{
    struct ColumnData {
        double H;   // Глибина
        double D;   // Діаметр свердловини
        double d1;  // Зовнішній діаметр колони
        double t;   // Товщина стінки
        double d2;  // Внутрішній діаметр колони
        double h;   // Висота цементного стакана
        double K;   // Коефіцієнт кавернозності
    };

    // Вхідні дані для першої колони
    ColumnData column1 = {
        ui->depthLineEdit_2->text().toDouble(),
        ui->wellDiameterLineEdit_2->text().toDouble(),
        ui->columnDiameterLineEdit_2->text().toDouble(),
        ui->wallThicknessLineEdit_2->text().toDouble(),
        ui->innerDiameterLineEdit_2->text().toDouble(),
        ui->cementHeightLineEdit_2->text().toDouble(),
        ui->cavernosityCoeffLineEdit_2->text().toDouble()
    };

    // Вхідні дані для другої колони
    ColumnData column2 = {
        ui->depthLineEdit_3->text().toDouble(),
        ui->wellDiameterLineEdit_3->text().toDouble(),
        ui->columnDiameterLineEdit_3->text().toDouble(),
        ui->wallThicknessLineEdit_3->text().toDouble(),
        ui->innerDiameterLineEdit_3->text().toDouble(),
        ui->cementHeightLineEdit_3->text().toDouble(),
        ui->cavernosityCoeffLineEdit_3->text().toDouble()
    };

    auto calculateVolume = [](const ColumnData& col) {
        if (col.D <= 0 || col.d1 <= 0 || col.d2 <= 0 || col.t < 0 || col.H <= 0 || col.h < 0 || col.K <= 0) {
            return std::make_tuple(0.0, 0.0, 0.0, 0.0); // Невірні вхідні дані
        }
        if (col.d1 <= col.d2 || col.d1 >= col.D || col.d2 >= col.D || col.h > col.H) {
            return std::make_tuple(0.0, 0.0, 0.0, 0.0); // Невірні розміри
        }

        double Vцр = 0.785 * (pow(col.D, 2) - pow(col.d1, 2)) * col.H * col.K + 0.785 * pow(col.d2, 2) * col.h;
        double Vпр = 0.785 * pow(col.d2, 2) * col.H;
        double Qц = Vцр * 1.23 * 1.05; // Необхідна кількість цементу
        double Vв = Vцр * 0.6 * 1.5;   // Необхідна кількість води

        return std::make_tuple(Vцр, Vпр, Qц, Vв);
    };

    auto [Vцр1, Vпр1, Qц1, Vв1] = calculateVolume(column1);
    auto [Vцр2, Vпр2, Qц2, Vв2] = calculateVolume(column2);

    double totalCement = Qц1 + Qц2;
    double totalWater = Vв1 + Vв2;

    // Виведення результатів
    ui->resultsTextEdit_2->setText(QString(
                                       "Перша колона:\n"
                                       "Об'єм тампонажного розчину: %1 м³\n"
                                       "Об'єм промивної рідини: %2 м³\n"
                                       "Необхідна кількість цементу: %3 т\n"
                                       "Необхідна кількість води: %4 м³\n\n"
                                       "Друга колона:\n"
                                       "Об'єм тампонажного розчину: %5 м³\n"
                                       "Об'єм промивної рідини: %6 м³\n"
                                       "Необхідна кількість цементу: %7 т\n"
                                       "Необхідна кількість води: %8 м³\n\n"
                                       "Загальні витрати:\n"
                                       "Цемент: %9 т\n"
                                       "Вода: %10 м³")
                                       .arg(Vцр1, 0, 'f', 4).arg(Vпр1, 0, 'f', 4).arg(Qц1, 0, 'f', 4).arg(Vв1, 0, 'f', 4)
                                       .arg(Vцр2, 0, 'f', 4).arg(Vпр2, 0, 'f', 4).arg(Qц2, 0, 'f', 4).arg(Vв2, 0, 'f', 4)
                                       .arg(totalCement, 0, 'f', 4).arg(totalWater, 0, 'f', 4));
}


void MainWindow::updateCalculateButtonState()
{
    // Проверяем, заполнены ли все поля
    bool allFieldsValid = !ui->depthLineEdit->text().isEmpty() &&
                          !ui->wellDiameterLineEdit->text().isEmpty() &&
                          !ui->columnDiameterLineEdit->text().isEmpty() &&
                          !ui->innerDiameterLineEdit->text().isEmpty() &&
                          !ui->cementHeightLineEdit->text().isEmpty() &&
                          !ui->cavernosityCoeffLineEdit->text().isEmpty();

    ui->calculateButton->setEnabled(allFieldsValid);
}

void MainWindow::on_calculateButton_clicked()
{

}

void MainWindow::clearInputs()
{
    // Очистить поля ввода
    ui->depthLineEdit->clear();             // Глубина
    ui->depthLineEdit_2->clear();
    ui->depthLineEdit_3->clear();
    ui->depthLineEdit_4->clear();
    ui->depthLineEdit_5->clear();
    ui->depthLineEdit_6->clear();
    ui->wellDiameterLineEdit->clear();      // Диаметр скважины
    ui->wellDiameterLineEdit_2->clear();
    ui->wellDiameterLineEdit_3->clear();
    ui->wellDiameterLineEdit_4->clear();
    ui->wellDiameterLineEdit_5->clear();
    ui->wellDiameterLineEdit_6->clear();
    ui->columnDiameterLineEdit->clear();    // Внешний диаметр колонны
    ui->columnDiameterLineEdit_2->clear();
    ui->columnDiameterLineEdit_3->clear();
    ui->columnDiameterLineEdit_4->clear();
    ui->columnDiameterLineEdit_5->clear();
    ui->columnDiameterLineEdit_6->clear();
    ui->innerDiameterLineEdit->clear();     // Внутренний диаметр колонны
    ui->innerDiameterLineEdit_2->clear();
    ui->innerDiameterLineEdit_3->clear();
    ui->innerDiameterLineEdit_4->clear();
    ui->innerDiameterLineEdit_5->clear();
    ui->innerDiameterLineEdit_6->clear();
    ui->wallThicknessLineEdit->clear();     // Толщина стенки
    ui->wallThicknessLineEdit_2->clear();
    ui->wallThicknessLineEdit_3->clear();
    ui->wallThicknessLineEdit_4->clear();
    ui->wallThicknessLineEdit_5->clear();
    ui->wallThicknessLineEdit_6->clear();
    ui->cementHeightLineEdit->clear();      // Высота цементации
    ui->cementHeightLineEdit_2->clear();
    ui->cementHeightLineEdit_3->clear();
    ui->cementHeightLineEdit_4->clear();
    ui->cementHeightLineEdit_5->clear();
    ui->cementHeightLineEdit_6->clear();
    ui->cavernosityCoeffLineEdit->clear();  // Коэффициент кавернозности
    ui->cavernosityCoeffLineEdit_2->clear();
    ui->cavernosityCoeffLineEdit_3->clear();
    ui->cavernosityCoeffLineEdit_4->clear();
    ui->cavernosityCoeffLineEdit_5->clear();
    ui->cavernosityCoeffLineEdit_6->clear();

    // Очистить текстовое поле для результатов
    ui->resultsTextEdit->clear();
    ui->resultsTextEdit_2->clear();
    ui->resultsTextEdit_3->clear();
}


void MainWindow::on_calculateD1Button_clicked()
{
    // Чтение данных с формы
    double d1 = ui->columnDiameterLineEdit->text().toDouble();   // Внешний диаметр колонны
    double d2 = ui->innerDiameterLineEdit->text().toDouble();    // Внутренний диаметр колонны
    double t = ui->wallThicknessLineEdit->text().toDouble();     // Толщина стенки колонны

    // Проверка, что d2 и t заданы
    if (d2 <= 0 || t <= 0) {
        ui->resultsTextEdit->setText("Ошибка: необходимо ввести d2 и t для вычисления d1.");
        return;
    }

    // Вычисление d1
    d1 = d2 + 2 * t;
    ui->columnDiameterLineEdit->setText(QString::number(d1, 'f', 3));  // Выводим результат в поле d1
}

void MainWindow::on_calculateD1Button_2_clicked()
{
    // Чтение данных с формы
    double d1 = ui->columnDiameterLineEdit_2->text().toDouble();   // Внешний диаметр колонны
    double d2 = ui->innerDiameterLineEdit_2->text().toDouble();    // Внутренний диаметр колонны
    double t = ui->wallThicknessLineEdit_2->text().toDouble();     // Толщина стенки колонны

    // Проверка, что d2 и t заданы
    if (d2 <= 0 || t <= 0) {
        ui->errorLabel->setText("Ошибка: необходимо ввести d2 и t для вычисления d1.");
        return;
    }

    // Вычисление d1
    d1 = d2 + 2 * t;
    ui->columnDiameterLineEdit_2->setText(QString::number(d1, 'f', 3));  // Выводим результат в поле d1
}

void MainWindow::on_calculateD1Button_3_clicked()
{
    // Чтение данных с формы
    double d1 = ui->columnDiameterLineEdit_3->text().toDouble();   // Внешний диаметр колонны
    double d2 = ui->innerDiameterLineEdit_3->text().toDouble();    // Внутренний диаметр колонны
    double t = ui->wallThicknessLineEdit_3->text().toDouble();     // Толщина стенки колонны

    // Проверка, что d2 и t заданы
    if (d2 <= 0 || t <= 0) {
        ui->errorLabel->setText("Ошибка: необходимо ввести d2 и t для вычисления d1.");
        return;
    }

    // Вычисление d1
    d1 = d2 + 2 * t;
    ui->columnDiameterLineEdit_3->setText(QString::number(d1, 'f', 3));  // Выводим результат в поле d1
}

void MainWindow::on_calculateD1Button_4_clicked()
{
    // Чтение данных с формы
    double d1 = ui->columnDiameterLineEdit_4->text().toDouble();   // Внешний диаметр колонны
    double d2 = ui->innerDiameterLineEdit_4->text().toDouble();    // Внутренний диаметр колонны
    double t = ui->wallThicknessLineEdit_4->text().toDouble();     // Толщина стенки колонны

    // Проверка, что d2 и t заданы
    if (d2 <= 0 || t <= 0) {
        ui->errorLabel->setText("Ошибка: необходимо ввести d2 и t для вычисления d1.");
        return;
    }

    // Вычисление d1
    d1 = d2 + 2 * t;
    ui->columnDiameterLineEdit_4->setText(QString::number(d1, 'f', 3));  // Выводим результат в поле d1
}

void MainWindow::on_calculateD1Button_5_clicked()
{
    // Чтение данных с формы
    double d1 = ui->columnDiameterLineEdit_5->text().toDouble();   // Внешний диаметр колонны
    double d2 = ui->innerDiameterLineEdit_5->text().toDouble();    // Внутренний диаметр колонны
    double t = ui->wallThicknessLineEdit_5->text().toDouble();     // Толщина стенки колонны

    // Проверка, что d2 и t заданы
    if (d2 <= 0 || t <= 0) {
        ui->errorLabel->setText("Ошибка: необходимо ввести d2 и t для вычисления d1.");
        return;
    }

    // Вычисление d1
    d1 = d2 + 2 * t;
    ui->columnDiameterLineEdit_5->setText(QString::number(d1, 'f', 3));  // Выводим результат в поле d1
}

void MainWindow::on_calculateD1Button_6_clicked()
{
    // Чтение данных с формы
    double d1 = ui->columnDiameterLineEdit_6->text().toDouble();   // Внешний диаметр колонны
    double d2 = ui->innerDiameterLineEdit_6->text().toDouble();    // Внутренний диаметр колонны
    double t = ui->wallThicknessLineEdit_6->text().toDouble();     // Толщина стенки колонны

    // Проверка, что d2 и t заданы
    if (d2 <= 0 || t <= 0) {
        ui->errorLabel->setText("Ошибка: необходимо ввести d2 и t для вычисления d1.");
        return;
    }

    // Вычисление d1
    d1 = d2 + 2 * t;
    ui->columnDiameterLineEdit_6->setText(QString::number(d1, 'f', 3));  // Выводим результат в поле d1
}


void MainWindow::on_calculateD2Button_clicked()
{
    // Чтение данных с формы
    double d1 = ui->columnDiameterLineEdit->text().toDouble();   // Внешний диаметр колонны
    double d2 = ui->innerDiameterLineEdit->text().toDouble();    // Внутренний диаметр колонны
    double t = ui->wallThicknessLineEdit->text().toDouble();     // Толщина стенки колонны

    // Проверка, что d1 и t заданы
    if (d1 <= 0 || t <= 0) {
        ui->errorLabel->setText("Ошибка: необходимо ввести d1 и t для вычисления d2.");
        return;
    }

    // Вычисление d2
    d2 = d1 - 2 * t;
    ui->innerDiameterLineEdit->setText(QString::number(d2, 'f', 3));  // Выводим результат в поле d2
}

void MainWindow::on_calculateD2Button_2_clicked()
{
    // Чтение данных с формы
    double d1 = ui->columnDiameterLineEdit_2->text().toDouble();   // Внешний диаметр колонны
    double t = ui->wallThicknessLineEdit_2->text().toDouble();     // Толщина стенки колонны

    // Проверка, что d1 и t заданы
    if (d1 <= 0 || t <= 0) {
        ui->errorLabel->setText("Ошибка: необходимо ввести d1 и t для вычисления d2.");
        return;
    }

    // Вычисление d2
    double d2 = d1 - 2 * t;
    ui->innerDiameterLineEdit_2->setText(QString::number(d2, 'f', 3));  // Выводим результат в поле d2
}

void MainWindow::on_calculateD2Button_3_clicked()
{
    // Чтение данных с формы
    double d1 = ui->columnDiameterLineEdit_3->text().toDouble();   // Внешний диаметр колонны
    double t = ui->wallThicknessLineEdit_3->text().toDouble();     // Толщина стенки колонны

    // Проверка, что d1 и t заданы
    if (d1 <= 0 || t <= 0) {
        ui->errorLabel->setText("Ошибка: необходимо ввести d1 и t для вычисления d2.");
        return;
    }

    // Вычисление d2
    double d2 = d1 - 2 * t;
    ui->innerDiameterLineEdit_3->setText(QString::number(d2, 'f', 3));  // Выводим результат в поле d2
}

void MainWindow::on_calculateD2Button_4_clicked()
{
    // Чтение данных с формы
    double d1 = ui->columnDiameterLineEdit_4->text().toDouble();   // Внешний диаметр колонны
    double t = ui->wallThicknessLineEdit_4->text().toDouble();     // Толщина стенки колонны

    // Проверка, что d1 и t заданы
    if (d1 <= 0 || t <= 0) {
        ui->errorLabel->setText("Ошибка: необходимо ввести d1 и t для вычисления d2.");
        return;
    }

    // Вычисление d2
    double d2 = d1 - 2 * t;
    ui->innerDiameterLineEdit_4->setText(QString::number(d2, 'f', 3));  // Выводим результат в поле d2
}

void MainWindow::on_calculateD2Button_5_clicked()
{
    // Чтение данных с формы
    double d1 = ui->columnDiameterLineEdit_5->text().toDouble();   // Внешний диаметр колонны
    double t = ui->wallThicknessLineEdit_5->text().toDouble();     // Толщина стенки колонны

    // Проверка, что d1 и t заданы
    if (d1 <= 0 || t <= 0) {
        ui->errorLabel->setText("Ошибка: необходимо ввести d1 и t для вычисления d2.");
        return;
    }

    // Вычисление d2
    double d2 = d1 - 2 * t;
    ui->innerDiameterLineEdit_5->setText(QString::number(d2, 'f', 3));  // Выводим результат в поле d2
}

void MainWindow::on_calculateD2Button_6_clicked()
{
    // Чтение данных с формы
    double d1 = ui->columnDiameterLineEdit_6->text().toDouble();   // Внешний диаметр колонны
    double t = ui->wallThicknessLineEdit_6->text().toDouble();     // Толщина стенки колонны

    // Проверка, что d1 и t заданы
    if (d1 <= 0 || t <= 0) {
        ui->errorLabel->setText("Ошибка: необходимо ввести d1 и t для вычисления d2.");
        return;
    }

    // Вычисление d2
    double d2 = d1 - 2 * t;
    ui->innerDiameterLineEdit_6->setText(QString::number(d2, 'f', 3));  // Выводим результат в поле d2
}

void MainWindow::on_calculateTButton_clicked()
{
    // Чтение данных с формы
    double d1 = ui->columnDiameterLineEdit->text().toDouble();   // Внешний диаметр колонны
    double d2 = ui->innerDiameterLineEdit->text().toDouble();    // Внутренний диаметр колонны

    // Проверка, что d1 и d2 заданы
    if (d1 <= 0 || d2 <= 0) {
        ui->errorLabel->setText("Ошибка: необходимо ввести d1 и d2 для вычисления t.");
        return;
    }

    // Вычисление t
    double t = (d1 - d2) / 2;
    ui->wallThicknessLineEdit->setText(QString::number(t, 'f', 3));  // Выводим результат в поле t
}

void MainWindow::on_calculateTButton_2_clicked()
{
    // Чтение данных с формы
    double d1 = ui->columnDiameterLineEdit_2->text().toDouble();   // Внешний диаметр колонны
    double d2 = ui->innerDiameterLineEdit_2->text().toDouble();    // Внутренний диаметр колонны

    // Проверка, что d1 и d2 заданы
    if (d1 <= 0 || d2 <= 0) {
        ui->errorLabel->setText("Ошибка: необходимо ввести d1 и d2 для вычисления t.");
        return;
    }

    // Вычисление t
    double t = (d1 - d2) / 2;
    ui->wallThicknessLineEdit_2->setText(QString::number(t, 'f', 3));  // Выводим результат в поле t
}

void MainWindow::on_calculateTButton_3_clicked()
{
    // Чтение данных с формы
    double d1 = ui->columnDiameterLineEdit_3->text().toDouble();   // Внешний диаметр колонны
    double d2 = ui->innerDiameterLineEdit_3->text().toDouble();    // Внутренний диаметр колонны

    // Проверка, что d1 и d2 заданы
    if (d1 <= 0 || d2 <= 0) {
        ui->errorLabel->setText("Ошибка: необходимо ввести d1 и d2 для вычисления t.");
        return;
    }

    // Вычисление t
    double t = (d1 - d2) / 2;
    ui->wallThicknessLineEdit_3->setText(QString::number(t, 'f', 3));  // Выводим результат в поле t
}

void MainWindow::on_calculateTButton_4_clicked()
{
    // Чтение данных с формы
    double d1 = ui->columnDiameterLineEdit_4->text().toDouble();   // Внешний диаметр колонны
    double d2 = ui->innerDiameterLineEdit_4->text().toDouble();    // Внутренний диаметр колонны

    // Проверка, что d1 и d2 заданы
    if (d1 <= 0 || d2 <= 0) {
        ui->errorLabel->setText("Ошибка: необходимо ввести d1 и d2 для вычисления t.");
        return;
    }

    // Вычисление t
    double t = (d1 - d2) / 2;
    ui->wallThicknessLineEdit_4->setText(QString::number(t, 'f', 3));  // Выводим результат в поле t
}

void MainWindow::on_calculateTButton_5_clicked()
{
    // Чтение данных с формы
    double d1 = ui->columnDiameterLineEdit_5->text().toDouble();   // Внешний диаметр колонны
    double d2 = ui->innerDiameterLineEdit_5->text().toDouble();    // Внутренний диаметр колонны

    // Проверка, что d1 и d2 заданы
    if (d1 <= 0 || d2 <= 0) {
        ui->errorLabel->setText("Ошибка: необходимо ввести d1 и d2 для вычисления t.");
        return;
    }

    // Вычисление t
    double t = (d1 - d2) / 2;
    ui->wallThicknessLineEdit_5->setText(QString::number(t, 'f', 3));  // Выводим результат в поле t
}

void MainWindow::on_calculateTButton_6_clicked()
{
    // Чтение данных с формы
    double d1 = ui->columnDiameterLineEdit_6->text().toDouble();   // Внешний диаметр колонны
    double d2 = ui->innerDiameterLineEdit_6->text().toDouble();    // Внутренний диаметр колонны

    // Проверка, что d1 и d2 заданы
    if (d1 <= 0 || d2 <= 0) {
        ui->errorLabel->setText("Ошибка: необходимо ввести d1 и d2 для вычисления t.");
        return;
    }

    // Вычисление t
    double t = (d1 - d2) / 2;
    ui->wallThicknessLineEdit_6->setText(QString::number(t, 'f', 3));  // Выводим результат в поле t
}


void MainWindow::on_clearButton_clicked()
{
    clearInputs();  // Очистить все поля
}

void MainWindow::on_clearButton_2_clicked()
{
    clearInputs();  // Очистить все поля
}

void MainWindow::on_clearButton_3_clicked()
{
    clearInputs();  // Очистить все поля
}

void MainWindow::on_calculateButton_2_clicked()
{
    calculateResults_2();
}


void MainWindow::on_calculateButton_3_clicked()
{

}

void MainWindow::updateErrorLabel()
{
    // Получаем текст из QTextEdit, который содержит ошибки
    QString errorText = ui->textEdit->toPlainText();

    // Если в QTextEdit есть ошибки, выводим их в errorLabel
    if (!errorText.isEmpty()) {
        ui->errorLabel->setText(errorText);
    } else {
        // Если нет ошибок, очищаем errorLabel
        ui->errorLabel->clear();
    }
}
