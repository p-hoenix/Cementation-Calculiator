#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QTextEdit>
#include <QTimer>
#include <QSettings>
#include "infowidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void showDetailedInfo();

private slots:

    void checkFields();

    void setupValidators();

    void updateErrorLabel();

    void calculateResults(); // Слот для расчётов

    void calculateResults_2(); // Слот для расчётов

    void calculateResults_3(); // Слот для расчётов

    void on_calculateButton_clicked();

    void on_wellTypeComboBox_currentIndexChanged(int index);

    void normalizeInput();  // Общий слот для обработки ввода

    void updateCalculateButtonState();

    bool validateInput();

    void clearInputs();

    void createActions(); // Объявление метода

    void about(); // Объявление метода "О программе"

    void on_clearButton_clicked();

    void on_calculateD1Button_clicked();

    void on_calculateButton_2_clicked();

    void on_calculateButton_3_clicked();

    void on_calculateD1Button_2_clicked();

    void on_calculateD1Button_3_clicked();

    void on_calculateD1Button_4_clicked();

    void on_calculateD1Button_5_clicked();

    void on_calculateD1Button_6_clicked();

    void on_calculateD2Button_clicked();

    void on_calculateD2Button_2_clicked();

    void on_calculateD2Button_3_clicked();

    void on_calculateD2Button_4_clicked();

    void on_calculateD2Button_5_clicked();

    void on_calculateD2Button_6_clicked();

    void on_calculateTButton_clicked();

    void on_calculateTButton_2_clicked();

    void on_calculateTButton_3_clicked();

    void on_calculateTButton_4_clicked();

    void on_calculateTButton_5_clicked();

    void on_calculateTButton_6_clicked();

    void on_clearButton_2_clicked();

    void on_clearButton_3_clicked();

    void updateCalculateButton_2State();

    void updateCalculateButton_3State();

    void onChangeWCRAction();

    void openDensitySettings();  // Открытие окна настроек плотности

    void setK2();

    void setK3();

    void openK2Settings();  // Слот для открытия настроек K2

    void openK3Settings();  // Слот для открытия настроек K3
protected:
    void enterEvent(QEnterEvent *event) override;


private:
    Ui::MainWindow *ui;
    QTextEdit *resultsTextEdit; // Добавляем член для текста результатов
    QTextEdit *resultsTextEdit_2; // Добавляем член для текста результатов 2 колоны
    QTextEdit *resultsTextEdit_3; // Добавляем член для текста результатов 3 колоны
    QWidget *window1;  // Виджет для расчёта 1
    QWidget *window2;  // Виджет для расчёта 2
    QWidget *window3;  // Виджет для расчёта 3
    QDockWidget *infoDockWidget = nullptr;
    InfoWidget *infoWindow = nullptr;
    QMenu *SMenu;  // Меню настроек
    QAction *CWR;  // Действие для изменения соотношения вода-цемент
    QAction *setK2Action;
    QAction *setK3Action;

    double currentWCR = 0.6667; // Соотношение цемента с водой

    // Переменные для хранения плотности
    double rho_tr = 1000.0; // Плотность транспортной жидкости
    double rho_c = 1400.0;  // Плотность цемента
    double rho_w = 1000.0;  // Плотность воды
    double k2 = 1.05;     // Коэффициент потерь цемента
    double k3 = 1.05;     // Коэффициент потерь воды

    // Методы для сохранения и загрузки настроек
    void saveSettings();
    void loadSettings();
};

#endif // MAINWINDOW_H
