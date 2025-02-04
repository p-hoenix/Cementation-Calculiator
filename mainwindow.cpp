#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QComboBox>
#include <QTimer>
#include <QTextEdit>
#include <QMessageBox>
#include <cmath>
#include <QDockWidget>
#include "infowidget.h"
#include <QDoubleValidator>
#include <QIntValidator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupValidators();  // Добавляем валидацию

    // Установка заголовка окна
    setWindowTitle("Калькулятор цементувания обсадних колон");
    ui->calculateButton->setEnabled(false);
    ui->calculateButton_2->setEnabled(false);
    ui->calculateButton_3->setEnabled(false);

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

    ui->resultsTextEdit->setReadOnly(true);  // Запрещаем ввод

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

    connect(ui->depthLineEdit_2, &QLineEdit::textChanged, this, &MainWindow::updateCalculateButton_2State);
    connect(ui->wellDiameterLineEdit_2, &QLineEdit::textChanged, this, &MainWindow::updateCalculateButton_2State);
    connect(ui->columnDiameterLineEdit_2, &QLineEdit::textChanged, this, &MainWindow::updateCalculateButton_2State);
    connect(ui->innerDiameterLineEdit_2, &QLineEdit::textChanged, this, &MainWindow::updateCalculateButton_2State);
    connect(ui->wallThicknessLineEdit_2, &QLineEdit::textChanged, this, &MainWindow::updateCalculateButton_2State);
    connect(ui->cementHeightLineEdit_2, &QLineEdit::textChanged, this, &MainWindow::updateCalculateButton_2State);
    connect(ui->cavernosityCoeffLineEdit_2, &QLineEdit::textChanged, this, &MainWindow::updateCalculateButton_2State);

    connect(ui->depthLineEdit_3, &QLineEdit::textChanged, this, &MainWindow::updateCalculateButton_2State);
    connect(ui->wellDiameterLineEdit_3, &QLineEdit::textChanged, this, &MainWindow::updateCalculateButton_2State);
    connect(ui->columnDiameterLineEdit_3, &QLineEdit::textChanged, this, &MainWindow::updateCalculateButton_2State);
    connect(ui->innerDiameterLineEdit_3, &QLineEdit::textChanged, this, &MainWindow::updateCalculateButton_2State);
    connect(ui->wallThicknessLineEdit_3, &QLineEdit::textChanged, this, &MainWindow::updateCalculateButton_2State);
    connect(ui->cementHeightLineEdit_3, &QLineEdit::textChanged, this, &MainWindow::updateCalculateButton_2State);
    connect(ui->cavernosityCoeffLineEdit_3, &QLineEdit::textChanged, this, &MainWindow::updateCalculateButton_2State);

    connect(ui->depthLineEdit_4, &QLineEdit::textChanged, this, &MainWindow::updateCalculateButton_3State);
    connect(ui->wellDiameterLineEdit_4, &QLineEdit::textChanged, this, &MainWindow::updateCalculateButton_3State);
    connect(ui->columnDiameterLineEdit_4, &QLineEdit::textChanged, this, &MainWindow::updateCalculateButton_3State);
    connect(ui->innerDiameterLineEdit_4, &QLineEdit::textChanged, this, &MainWindow::updateCalculateButton_3State);
    connect(ui->wallThicknessLineEdit_4, &QLineEdit::textChanged, this, &MainWindow::updateCalculateButton_3State);
    connect(ui->cementHeightLineEdit_4, &QLineEdit::textChanged, this, &MainWindow::updateCalculateButton_3State);
    connect(ui->cavernosityCoeffLineEdit_4, &QLineEdit::textChanged, this, &MainWindow::updateCalculateButton_3State);

    connect(ui->depthLineEdit_5, &QLineEdit::textChanged, this, &MainWindow::updateCalculateButton_3State);
    connect(ui->wellDiameterLineEdit_5, &QLineEdit::textChanged, this, &MainWindow::updateCalculateButton_3State);
    connect(ui->columnDiameterLineEdit_5, &QLineEdit::textChanged, this, &MainWindow::updateCalculateButton_3State);
    connect(ui->innerDiameterLineEdit_5, &QLineEdit::textChanged, this, &MainWindow::updateCalculateButton_3State);
    connect(ui->wallThicknessLineEdit_5, &QLineEdit::textChanged, this, &MainWindow::updateCalculateButton_3State);
    connect(ui->cementHeightLineEdit_5, &QLineEdit::textChanged, this, &MainWindow::updateCalculateButton_3State);
    connect(ui->cavernosityCoeffLineEdit_5, &QLineEdit::textChanged, this, &MainWindow::updateCalculateButton_3State);

    connect(ui->depthLineEdit_6, &QLineEdit::textChanged, this, &MainWindow::updateCalculateButton_3State);
    connect(ui->wellDiameterLineEdit_6, &QLineEdit::textChanged, this, &MainWindow::updateCalculateButton_3State);
    connect(ui->columnDiameterLineEdit_6, &QLineEdit::textChanged, this, &MainWindow::updateCalculateButton_3State);
    connect(ui->innerDiameterLineEdit_6, &QLineEdit::textChanged, this, &MainWindow::updateCalculateButton_3State);
    connect(ui->wallThicknessLineEdit_6, &QLineEdit::textChanged, this, &MainWindow::updateCalculateButton_3State);
    connect(ui->cementHeightLineEdit_6, &QLineEdit::textChanged, this, &MainWindow::updateCalculateButton_3State);
    connect(ui->cavernosityCoeffLineEdit_6, &QLineEdit::textChanged, this, &MainWindow::updateCalculateButton_3State);

    // Обновляем состояние кнопки при запуске
    updateCalculateButtonState();
    updateCalculateButton_2State();
    updateCalculateButton_3State();


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
        ui->errorLabel->setText("Помилка: всі розміри повинні бути додатними числами.");
        return;
    }
    if (d1 <= d2) {
        ui->errorLabel->setText("Помилка: внутрішній діаметр повинен бути меншим за зовнішній діаметр.");
        return;
    }
    if (d1 >= D) {
        ui->errorLabel->setText("Помилка: зовнішній діаметр повинен бути меншим за діаметр свердловини.");
        return;
    }
    if (d2 >= D) {
        ui->errorLabel->setText("Помилка: внутрішній діаметр повинен бути менше діаметра свердловини.");
        return;
    }
    if (H <= 0 || h < 0 || K <= 0 || t < 0) {
        ui->errorLabel->setText("Помилка: перевірте правильність даних.");
        return;
    }
    if (t < 0 && !tText.isEmpty()) {
        ui->errorLabel->setText("Помилка: перевірте внесені значення.");
        return;
    }
    if (h > H) {
        ui->errorLabel->setText("Помилка: висота цементного стакана не може бути більшою за глибину.");
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
                                     "Об'єм тампонажного розчину : %1 м³\n"
                                     "Об'єм промивної рідини : %2 м³\n"
                                     "Необхідна кількість цементу : %3 т\n"
                                     "Необхідна кількість води : %4 м³\n\n")
                                     .arg(Vцр + Vпр, 0, 'f', 4)
                                     .arg(Vпр, 0, 'f', 4)
                                     .arg(Qц, 0, 'f', 4)
                                     .arg(Vв, 0, 'f', 4));
}

void MainWindow::calculateResults_3() {
    // Читання даних з форми для першої колони
    double H1 = ui->depthLineEdit_4->text().toDouble();             // Глибина
    double D1 = ui->wellDiameterLineEdit_4->text().toDouble();      // Діаметр свердловини
    double d1_1 = ui->columnDiameterLineEdit_4->text().toDouble();  // Зовнішній діаметр першої колони
    double d2_1 = ui->innerDiameterLineEdit_4->text().toDouble();   // Внутрішній діаметр першої колони
    QString tText1 = ui->wallThicknessLineEdit_4->text();            // Товщина стінки першої колони
    double t1 = tText1.isEmpty() ? 0 : tText1.toDouble();          // Якщо порожнє, присвоюємо 0
    double h1 = ui->cementHeightLineEdit_4->text().toDouble();       // Висота цементації першої колони
    double K1 = ui->cavernosityCoeffLineEdit_4->text().toDouble();  // Коэффициент кавернозності першої колони

    // Читання даних з форми для другої колони
    double H2 = ui->depthLineEdit_5->text().toDouble();             // Глибина
    double D2 = ui->wellDiameterLineEdit_5->text().toDouble();      // Діаметр свердловини
    double d1_2 = ui->columnDiameterLineEdit_5->text().toDouble();  // Зовнішній діаметр другої колони
    double d2_2 = ui->innerDiameterLineEdit_5->text().toDouble();   // Внутрішній діаметр другої колони
    QString tText2 = ui->wallThicknessLineEdit_5->text();            // Товщина стінки другої колони
    double t2 = tText2.isEmpty() ? 0 : tText2.toDouble();          // Якщо порожнє, присвоюємо 0
    double h2 = ui->cementHeightLineEdit_5->text().toDouble();       // Висота цементації другої колони
    double K2 = ui->cavernosityCoeffLineEdit_5->text().toDouble();  // Коэффициент кавернозності другої колони

    // Читання даних з форми для третьої колони
    double H3 = ui->depthLineEdit_6->text().toDouble();             // Глибина
    double D3 = ui->wellDiameterLineEdit_6->text().toDouble();      // Діаметр свердловини
    double d1_3 = ui->columnDiameterLineEdit_6->text().toDouble();  // Зовнішній діаметр третьої колони
    double d2_3 = ui->innerDiameterLineEdit_6->text().toDouble();   // Внутрішній діаметр третьої колони
    QString tText3 = ui->wallThicknessLineEdit_6->text();            // Товщина стінки третьої колони
    double t3 = tText3.isEmpty() ? 0 : tText3.toDouble();          // Якщо порожнє, присвоюємо 0
    double h3 = ui->cementHeightLineEdit_6->text().toDouble();       // Висота цементації третьої колони
    double K3 = ui->cavernosityCoeffLineEdit_6->text().toDouble();  // Коэффициент кавернозності третьої колони

    // Перевірка вхідних даних для першої колони
    if (D1 <= 0 || d1_1 <= 0 || d2_1 <= 0) {
        ui->errorLabel->setText("Помилка: всі розміри першої колони повинні бути додатними числами.");
        return;
    }
    if (d1_1 <= d2_1) {
        ui->errorLabel->setText("Помилка: внутрішній діаметр першої колони повинен бути меншим за зовнішній діаметр.");
        return;
    }
    if (d1_1 >= D1) {
        ui->errorLabel->setText("Помилка: зовнішній діаметр першої колони повинен бути меншим за діаметр свердловини.");
        return;
    }
    if (d2_1 >= D1) {
        ui->errorLabel->setText("Помилка: внутрішній діаметр першої колони повинен бути меншим за діаметр свердловини.");
        return;
    }
    if (H1 <= 0 || h1 < 0 || K1 <= 0 || t1 < 0) {
        ui->errorLabel->setText("Помилка: перевірте введені значення для першої колони.");
        return;
    }
    if (h1 > H1) {
        ui->errorLabel->setText("Помилка: висота цементного стакана першої колони не може бути більшою за глибину.");
        return;
    }

    // Перевірка вхідних даних для другої колони
    if (D2 <= 0 || d1_2 <= 0 || d2_2 <= 0) {
        ui->errorLabel->setText("Помилка: всі розміри другої колони повинні бути додатними числами.");
        return;
    }
    if (d1_2 <= d2_2) {
        ui->errorLabel->setText("Помилка: внутрішній діаметр другої колони повинен бути меншим за зовнішній діаметр.");
        return;
    }
    if (d1_2 >= D2) {
        ui->errorLabel->setText("Помилка: зовнішній діаметр другої колони повинен бути меншим за діаметр свердловини.");
        return;
    }
    if (d2_2 >= D2) {
        ui->errorLabel->setText("Помилка: внутрішній діаметр другої колони повинен бути меншим за діаметр свердловини.");
        return;
    }
    if (H2 <= 0 || h2 < 0 || K2 <= 0 || t2 < 0) {
        ui->errorLabel->setText("Помилка: перевірте введені значення для другої колони.");
        return;
    }
    if (h2 > H2) {
        ui->errorLabel->setText("Помилка: висота цементного стакана другої колони не може бути більшою за глибину.");
        return;
    }

    // Перевірка вхідних даних для третьої колони
    if (D3 <= 0 || d1_3 <= 0 || d2_3 <= 0) {
        ui->errorLabel->setText("Помилка: всі розміри третьої колони повинні бути додатними числами.");
        return;
    }
    if (d1_3 <= d2_3) {
        ui->errorLabel->setText("Помилка: внутрішній діаметр третьої колони повинен бути меншим за зовнішній діаметр.");
        return;
    }
    if (d1_3 >= D3) {
        ui->errorLabel->setText("Помилка: зовнішній діаметр третьої колони повинен бути меншим за діаметр свердловини.");
        return;
    }
    if (d2_3 >= D3) {
        ui->errorLabel->setText("Помилка: внутрішній діаметр третьої колони повинен бути меншим за діаметр свердловини.");
        return;
    }
    if (H3 <= 0 || h3 < 0 || K3 <= 0 || t3 < 0) {
        ui->errorLabel->setText("Помилка: перевірте введені значення для третьої колони.");
        return;
    }
    if (h3 > H3) {
        ui->errorLabel->setText("Помилка: висота цементного стакана третьої колони не може бути більшою за глибину.");
        return;
    }

    // Розрахунок об'ємів для першої колони
    double Vцр1 = 0.785 * (pow(D1, 2) - pow(d1_1, 2)) * H1 * K1 + 0.785 * pow(d2_1, 2) * h1;  // Об'єм тампонажного розчину для першої колони
    double Vпр1 = (H1 > h1) ? (0.785 * pow(d2_1, 2) * (H1 - h1)) : 0;  // Об'єм промивної рідини для першої колони

    // Розрахунок об'ємів для другої колони
    double Vцр2 = 0.785 * (pow(D2, 2) - pow(d1_2, 2)) * H2 * K2 + 0.785 * pow(d2_2, 2) * h2;  // Об'єм тампонажного розчину для другої колони
    double Vпр2 = (H2 > h2) ? (0.785 * pow(d2_2, 2) * (H2 - h2)) : 0;  // Об'єм промивної рідини для другої колони

    // Розрахунок об'ємів для третьої колони
    double Vцр3 = 0.785 * (pow(D3, 2) - pow(d1_3, 2)) * H3 * K3 + 0.785 * pow(d2_3, 2) * h3;  // Об'єм тампонажного розчину для третьої колони
    double Vпр3 = (H3 > h3) ? (0.785 * pow(d2_3, 2) * (H3 - h3)) : 0;  // Об'єм промивної рідини для третьої колони

    // Коригування від'ємних значень
    if (Vцр1 < 0) Vцр1 = 0;
    if (Vпр1 < 0) Vпр1 = 0;
    if (Vцр2 < 0) Vцр2 = 0;
    if (Vпр2 < 0) Vпр2 = 0;
    if (Vцр3 < 0) Vцр3 = 0;
    if (Vпр3 < 0) Vпр3 = 0;

    // Розрахунок цементу та води
    double Qц1 = Vцр1 * 1.23 * 1.05;  // Необхідна кількість цементу для першої колони
    double Vв1 = Vцр1 * 0.6 * 1.5;    // Необхідна кількість води для першої колони
    double Qц2 = Vцр2 * 1.23 * 1.05;  // Необхідна кількість цементу для другої колони
    double Vв2 = Vцр2 * 0.6 * 1.5;    // Необхідна кількість води для другої колони
    double Qц3 = Vцр3 * 1.23 * 1.05;  // Необхідна кількість цементу для третьої колони
    double Vв3 = Vцр3 * 0.6 * 1.5;    // Необхідна кількість води для третьої колони

    ui->resultsTextEdit_3->setText(QString(
                                         "Об'єм тампонажного розчину для першої колони: %1 м³\n"
                                         "Об'єм промивної рідини для першої колони: %2 м³\n"
                                         "Необхідна кількість цементу для першої колони: %3 т\n"
                                         "Необхідна кількість води для першої колони: %4 м³\n\n"
                                         "Об'єм тампонажного розчину для другої колони: %5 м³\n"
                                         "Об'єм промивної рідини для другої колони: %6 м³\n"
                                         "Необхідна кількість цементу для другої колони: %7 т\n"
                                         "Необхідна кількість води для другої колони: %8 м³\n\n"
                                         "Об'єм тампонажного розчину для третьої колони: %9 м³\n"
                                         "Об'єм промивної рідини для третьої колони: %10 м³\n"
                                         "Необхідна кількість цементу для третьої колони: %11 т\n"
                                         "Необхідна кількість води для третьої колони: %12 м³")
                                         .arg(Vцр1 + Vпр1, 0, 'f', 4)
                                         .arg(Vпр1, 0, 'f', 4)
                                         .arg(Qц1, 0, 'f', 4)
                                         .arg(Vв1, 0, 'f', 4)
                                         .arg(Vцр2 + Vпр2, 0, 'f', 4)
                                         .arg(Vпр2, 0, 'f', 4)
                                         .arg(Qц2, 0, 'f', 4)
                                         .arg(Vв2, 0, 'f', 4)
                                         .arg(Vцр3 + Vпр3, 0, 'f', 4)
                                         .arg(Vпр3, 0, 'f', 4)
                                         .arg(Qц3, 0, 'f', 4)
                                         .arg(Vв3, 0, 'f', 4));
}

void MainWindow::calculateResults_2() {
    // Чтение данных с формы для первой колонки
    double H1 = ui->depthLineEdit_2->text().toDouble();             // Глубина
    double D1 = ui->wellDiameterLineEdit_2->text().toDouble();      // Диаметр скважины
    double d1_1 = ui->columnDiameterLineEdit_2->text().toDouble();  // Внешний диаметр первой колонны
    double d2_1 = ui->innerDiameterLineEdit_2->text().toDouble();   // Внутренний диаметр первой колонны
    QString tText1 = ui->wallThicknessLineEdit_2->text();            // Толщина стенки первой колонны
    double t1 = tText1.isEmpty() ? 0 : tText1.toDouble();          // Если пустое, присваиваем 0
    double h1 = ui->cementHeightLineEdit_2->text().toDouble();       // Высота цементации первой колонны
    double K1 = ui->cavernosityCoeffLineEdit_2->text().toDouble();  // Коэффициент кавернозности первой колонны

    // Чтение данных с формы для второй колонки
    double H2 = ui->depthLineEdit_3->text().toDouble();             // Глубина
    double D2 = ui->wellDiameterLineEdit_3->text().toDouble();      // Диаметр скважины
    double d1_2 = ui->columnDiameterLineEdit_3->text().toDouble();  // Внешний диаметр второй колонны
    double d2_2 = ui->innerDiameterLineEdit_3->text().toDouble();   // Внутренний диаметр второй колонны
    QString tText2 = ui->wallThicknessLineEdit_3->text();            // Толщина стенки второй колонны
    double t2 = tText2.isEmpty() ? 0 : tText2.toDouble();          // Если пустое, присваиваем 0
    double h2 = ui->cementHeightLineEdit_3->text().toDouble();       // Высота цементации второй колонны
    double K2 = ui->cavernosityCoeffLineEdit_3->text().toDouble();  // Коэффициент кавернозности второй колонны

    // Проверка входных данных для первой колонки
    if (D1 <= 0 || d1_1 <= 0 || d2_1 <= 0) {
        ui->errorLabel->setText("Ошибка: все размеры первой колонны должны быть положительными числами.");
        return;
    }
    if (d1_1 <= d2_1) {
        ui->errorLabel->setText("Ошибка: внутренний диаметр первой колонны должен быть меньше внешнего диаметра.");
        return;
    }
    if (d1_1 >= D1) {
        ui->errorLabel->setText("Ошибка: внешний диаметр первой колонны должен быть меньше диаметра скважины.");
        return;
    }
    if (d2_1 >= D1) {
        ui->errorLabel->setText("Ошибка: внутренний диаметр первой колонны должен быть меньше диаметра скважины.");
        return;
    }
    if (H1 <= 0 || h1 < 0 || K1 <= 0 || t1 < 0) {
        ui->errorLabel->setText("Ошибка: проверьте введённые значения для первой колонны.");
        return;
    }
    if (h1 > H1) {
        ui->errorLabel->setText("Ошибка: высота цементного стакана первой колонны не может быть больше глубины.");
        return;
    }

    // Проверка входных данных для второй колонки
    if (D2 <= 0 || d1_2 <= 0 || d2_2 <= 0) {
        ui->errorLabel->setText("Ошибка: все размеры второй колонны должны быть положительными числами.");
        return;
    }
    if (d1_2 <= d2_2) {
        ui->errorLabel->setText("Ошибка: внутренний диаметр второй колонны должен быть меньше внешнего диаметра.");
        return;
    }
    if (d1_2 >= D2) {
        ui->errorLabel->setText("Ошибка: внешний диаметр второй колонны должен быть меньше диаметра скважины.");
        return;
    }
    if (d2_2 >= D2) {
        ui->errorLabel->setText("Ошибка: внутренний диаметр второй колонны должен быть меньше диаметра скважины.");
        return;
    }
    if (H2 <= 0 || h2 < 0 || K2 <= 0 || t2 < 0) {
        ui->errorLabel->setText("Ошибка: проверьте введённые значения для второй колонны.");
        return;
    }
    if (h2 > H2) {
        ui->errorLabel->setText("Ошибка: высота цементного стакана второй колонны не может быть больше глубины.");
        return;
    }

    // Расчёт объёмов для первой колонны
    double Vцр1 = 0.785 * (pow(D1, 2) - pow(d1_1, 2)) * H1 * K1 + 0.785 * pow(d2_1, 2) * h1;  // Объём тампонажного раствора для первой колонны
    double Vпр1 = (H1 > h1) ? (0.785 * pow(d2_1, 2) * (H1 - h1)) : 0;  // Объём промывочной жидкости для первой колонны

    // Расчёт объёмов для второй колонны
    double Vцр2 = 0.785 * (pow(D2, 2) - pow(d1_2, 2)) * H2 * K2 + 0.785 * pow(d2_2, 2) * h2;  // Объём тампонажного раствора для второй колонны
    double Vпр2 = (H2 > h2) ? (0.785 * pow(d2_2, 2) * (H2 - h2)) : 0;  // Объём промывочной жидкости для второй колонны

    // Корректировка отрицательных значений
    if (Vцр1 < 0) Vцр1 = 0;
    if (Vпр1 < 0) Vпр1 = 0;
    if (Vцр2 < 0) Vцр2 = 0;
    if (Vпр2 < 0) Vпр2 = 0;

    // Расчёт цемента и воды
    double Qц1 = Vцр1 * 1.23 * 1.05;  // Необходимое количество цемента для первой колонны
    double Vв1 = Vцр1 * 0.6 * 1.5;    // Необходимое количество воды для первой колонны
    double Qц2 = Vцр2 * 1.23 * 1.05;  // Необходимое количество цемента для второй колонны
    double Vв2 = Vцр2 * 0.6 * 1.5;    // Необходимое количество воды для второй колонны

    // Вывод результатов
    ui->resultsTextEdit->setText(QString(
                                     "Объем тампонажного раствора для первой колонны: %1 м³\n"
                                     "Объем промывочной жидкости для первой колонны: %2 м³\n"
                                     "Необходимое количество цемента для первой колонны: %3 т\n"
                                     "Необходимое количество воды для первой колонны: %4 м³\n\n"
                                     "Объем тампонажного раствора для второй колонны: %5 м³\n"
                                     "Объем промывочной жидкости для второй колонны: %6 м³\n"
                                     "Необходимое количество цемента для второй колонны: %7 т\n"
                                     "Необходимое количество воды для второй колонны: %8 м³")
                                     .arg(Vцр1 + Vпр1, 0, 'f', 4)
                                     .arg(Vпр1, 0, 'f', 4)
                                     .arg(Qц1, 0, 'f', 4)
                                     .arg(Vв1, 0, 'f', 4)
                                     .arg(Vцр2 + Vпр2, 0, 'f', 4)
                                     .arg(Vпр2, 0, 'f', 4)
                                     .arg(Qц2, 0, 'f', 4)
                                     .arg(Vв2, 0, 'f', 4));
}

void MainWindow::updateCalculateButton_2State()
{
    qDebug() << "Проверка полей...";

    bool allFieldsValid = !ui->depthLineEdit_2->text().isEmpty() &&
                          !ui->wellDiameterLineEdit_2->text().isEmpty() &&
                          !ui->columnDiameterLineEdit_2->text().isEmpty() &&
                          !ui->innerDiameterLineEdit_2->text().isEmpty() &&
                          !ui->cementHeightLineEdit_2->text().isEmpty() &&
                          !ui->cavernosityCoeffLineEdit_2->text().isEmpty() &&
                          !ui->depthLineEdit_3->text().isEmpty() &&
                          !ui->wellDiameterLineEdit_3->text().isEmpty() &&
                          !ui->columnDiameterLineEdit_3->text().isEmpty() &&
                          !ui->innerDiameterLineEdit_3->text().isEmpty() &&
                          !ui->cementHeightLineEdit_3->text().isEmpty() &&
                          !ui->cavernosityCoeffLineEdit_3->text().isEmpty();

    qDebug() << "Все поля заполнены?" << allFieldsValid;

    ui->calculateButton_2->setEnabled(allFieldsValid);
    if (!allFieldsValid) {
        ui->calculateButton_2->setToolTip("Заповніть всі поля для розрахунку");
    } else {
        ui->calculateButton_2->setToolTip(""); // Очищаем подсказку
    }
}

void MainWindow::updateCalculateButton_3State()
{
    qDebug() << "Проверка полей...";

    bool allFieldsValid = !ui->depthLineEdit_4->text().isEmpty() &&
                          !ui->wellDiameterLineEdit_4->text().isEmpty() &&
                          !ui->columnDiameterLineEdit_4->text().isEmpty() &&
                          !ui->innerDiameterLineEdit_4->text().isEmpty() &&
                          !ui->cementHeightLineEdit_4->text().isEmpty() &&
                          !ui->cavernosityCoeffLineEdit_4->text().isEmpty() &&
                          !ui->depthLineEdit_5->text().isEmpty() &&
                          !ui->wellDiameterLineEdit_5->text().isEmpty() &&
                          !ui->columnDiameterLineEdit_5->text().isEmpty() &&
                          !ui->innerDiameterLineEdit_5->text().isEmpty() &&
                          !ui->cementHeightLineEdit_5->text().isEmpty() &&
                          !ui->cavernosityCoeffLineEdit_5->text().isEmpty() &&
                          !ui->depthLineEdit_6->text().isEmpty() &&
                          !ui->wellDiameterLineEdit_6->text().isEmpty() &&
                          !ui->columnDiameterLineEdit_6->text().isEmpty() &&
                          !ui->innerDiameterLineEdit_6->text().isEmpty() &&
                          !ui->cementHeightLineEdit_6->text().isEmpty() &&
                          !ui->cavernosityCoeffLineEdit_6->text().isEmpty();

    qDebug() << "Все поля заполнены?" << allFieldsValid;

    ui->calculateButton_3->setEnabled(allFieldsValid);

    if (!allFieldsValid) {
        ui->calculateButton_3->setToolTip("Заповніть всі поля для розрахунку");
    } else {
        ui->calculateButton_3->setToolTip(""); // Очищаем подсказку
    }
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

    qDebug() << "Все поля заполнены?" << allFieldsValid;

    ui->calculateButton->setEnabled(allFieldsValid);

    if (!allFieldsValid) {
        ui->calculateButton->setToolTip("Заповніть всі поля для розрахунку");
    } else {
        ui->calculateButton->setToolTip(""); // Очищаем подсказку
    }
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

void MainWindow::checkFields() {
    bool allFilled = !ui->depthLineEdit->text().isEmpty() &&
                     !ui->wellDiameterLineEdit->text().isEmpty() &&
                     !ui->columnDiameterLineEdit->text().isEmpty() &&
                     !ui->innerDiameterLineEdit->text().isEmpty() &&
                     !ui->wallThicknessLineEdit->text().isEmpty() &&
                     !ui->cementHeightLineEdit->text().isEmpty() &&
                     !ui->cavernosityCoeffLineEdit->text().isEmpty();

    ui->calculateButton->setEnabled(allFilled);
}

void MainWindow::enterEvent(QEnterEvent *event)
{
    QMainWindow::enterEvent(event);

    // Проверяем, если кнопка неактивна
    if (!ui->calculateButton_2->isEnabled()) {
        ui->errorLabel->setText("");
        ui->errorLabel->setVisible(true);  // Показываем метку с ошибкой
    }
}
