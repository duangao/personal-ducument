#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDiaLog>
#include <QLineEdit>
#include <QString>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QString resstring;
    int result;
    int result_temp;
    int base;

    void trans_to_bin();
    void trans_to_oct();
    void trans_to_dec();
    void trans_to_hex();

private slots:
    void recepeZero();
    void recepeOne();
    void recepeTwo();
    void recepeThree();
    void recepeFour();
    void recepeFive();
    void recepeSix();
    void recepeSeven();
    void recepeEight();
    void recepeNine();

    void recepeA();
    void recepeB();
    void recepeC();
    void recepeD();
    void recepeE();
    void recepeF();

    void receptBin();
    void receptOct();
    void receptDec();
    void receptHex();
    void clear();

};

#endif // MAINWINDOW_H
