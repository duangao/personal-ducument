#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    resstring="";
    result=0;
    base=10;
    ui->pushButton0->setDisabled(0);
    ui->pushButton1->setDisabled(0);
    ui->pushButton2->setDisabled(0);
    ui->pushButton3->setDisabled(0);
    ui->pushButton4->setDisabled(0);
    ui->pushButton5->setDisabled(0);
    ui->pushButton6->setDisabled(0);
    ui->pushButton7->setDisabled(0);
    ui->pushButton8->setDisabled(0);
    ui->pushButton9->setDisabled(0);

    ui->pushButtonA->setDisabled(1);
    ui->pushButtonB->setDisabled(1);
    ui->pushButtonB->setDisabled(1);
    ui->pushButtonC->setDisabled(1);
    ui->pushButtonD->setDisabled(1);
    ui->pushButtonE->setDisabled(1);
    ui->pushButtonF->setDisabled(1);

    setWindowTitle(tr("Bin&Oct&dec&hex"));

    connect(ui->pushButton0,SIGNAL(clicked()),this,SLOT(recepeZero()));
    connect(ui->pushButton1,SIGNAL(clicked()),this,SLOT(recepeOne()));
    connect(ui->pushButton2,SIGNAL(clicked()),this,SLOT(recepeTwo()));
    connect(ui->pushButton3,SIGNAL(clicked()),this,SLOT(recepeThree()));
    connect(ui->pushButton4,SIGNAL(clicked()),this,SLOT(recepeFour()));
    connect(ui->pushButton5,SIGNAL(clicked()),this,SLOT(recepeFive()));
    connect(ui->pushButton6,SIGNAL(clicked()),this,SLOT(recepeSix()));
    connect(ui->pushButton7,SIGNAL(clicked()),this,SLOT(recepeSeven()));
    connect(ui->pushButton8,SIGNAL(clicked()),this,SLOT(recepeEight()));
    connect(ui->pushButton9,SIGNAL(clicked()),this,SLOT(recepeNine()));
    connect(ui->pushButtonA,SIGNAL(clicked()),this,SLOT(recepeA()));
    connect(ui->pushButtonB,SIGNAL(clicked()),this,SLOT(recepeB()));
    connect(ui->pushButtonC,SIGNAL(clicked()),this,SLOT(recepeC()));
    connect(ui->pushButtonD,SIGNAL(clicked()),this,SLOT(recepeD()));
    connect(ui->pushButtonE,SIGNAL(clicked()),this,SLOT(recepeE()));
    connect(ui->pushButtonF,SIGNAL(clicked()),this,SLOT(recepeF()));

    connect(ui->pushButton_1,SIGNAL(clicked()),this,SLOT(receptBin()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(receptDec()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(receptOct()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(receptHex()));
    connect(ui->clear,SIGNAL(clicked()),this,SLOT(clear()));

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::receptBin()
{
   ui->pushButton2->setDisabled(1);
   ui->pushButton3->setDisabled(1);
   ui->pushButton4->setDisabled(1);
   ui->pushButton5->setDisabled(1);
   ui->pushButton6->setDisabled(1);
   ui->pushButton7->setDisabled(1);
   ui->pushButton8->setDisabled(1);
   ui->pushButton9->setDisabled(1);
   ui->pushButtonA->setDisabled(1);
   ui->pushButtonB->setDisabled(1);
   ui->pushButtonB->setDisabled(1);
   ui->pushButtonC->setDisabled(1);
   ui->pushButtonD->setDisabled(1);
   ui->pushButtonE->setDisabled(1);
   ui->pushButtonF->setDisabled(1);
   ui->pushButton0->setDisabled(0);
   ui->pushButton1->setDisabled(0);
   trans_to_bin();

}

void MainWindow::receptOct()
{
    ui->pushButton0->setDisabled(0);
    ui->pushButton1->setDisabled(0);
    ui->pushButton2->setDisabled(0);
    ui->pushButton3->setDisabled(0);
    ui->pushButton4->setDisabled(0);
    ui->pushButton5->setDisabled(0);
    ui->pushButton6->setDisabled(0);
    ui->pushButton7->setDisabled(0);
    ui->pushButton8->setDisabled(1);
    ui->pushButton9->setDisabled(1);
    ui->pushButtonA->setDisabled(1);
    ui->pushButtonB->setDisabled(1);
    ui->pushButtonB->setDisabled(1);
    ui->pushButtonC->setDisabled(1);
    ui->pushButtonD->setDisabled(1);
    ui->pushButtonE->setDisabled(1);
    ui->pushButtonF->setDisabled(1);
    trans_to_oct();

}

void MainWindow::receptDec()
{
    ui->pushButton0->setDisabled(0);
    ui->pushButton1->setDisabled(0);
    ui->pushButton2->setDisabled(0);
    ui->pushButton3->setDisabled(0);
    ui->pushButton4->setDisabled(0);
    ui->pushButton5->setDisabled(0);
    ui->pushButton6->setDisabled(0);
    ui->pushButton7->setDisabled(0);
    ui->pushButton8->setDisabled(0);
    ui->pushButton9->setDisabled(0);

    ui->pushButtonA->setDisabled(1);
    ui->pushButtonB->setDisabled(1);
    ui->pushButtonB->setDisabled(1);
    ui->pushButtonC->setDisabled(1);
    ui->pushButtonD->setDisabled(1);
    ui->pushButtonE->setDisabled(1);
    ui->pushButtonF->setDisabled(1);

    trans_to_dec();
}
void MainWindow::receptHex()
{
    ui->pushButton0->setDisabled(0);
    ui->pushButton1->setDisabled(0);
    ui->pushButton2->setDisabled(0);
    ui->pushButton3->setDisabled(0);
    ui->pushButton4->setDisabled(0);
    ui->pushButton5->setDisabled(0);
    ui->pushButton6->setDisabled(0);
    ui->pushButton7->setDisabled(0);
    ui->pushButton8->setDisabled(0);
    ui->pushButton9->setDisabled(0);

    ui->pushButtonA->setDisabled(0);
    ui->pushButtonB->setDisabled(0);
    ui->pushButtonB->setDisabled(0);
    ui->pushButtonC->setDisabled(0);
    ui->pushButtonD->setDisabled(0);
    ui->pushButtonE->setDisabled(0);
    ui->pushButtonF->setDisabled(0);
    trans_to_hex();

}

void MainWindow::recepeZero()
{
    result=result*base;
    resstring+="0";
    ui->showLabel->setText(resstring);
}
void MainWindow::recepeOne()
{
    result=result*base+1;
    resstring+="1";
    ui->showLabel->setText(resstring);
}

void MainWindow::recepeTwo()
{
    result=result*base+2;
    resstring+="2";
    ui->showLabel->setText(resstring);
}

void MainWindow::recepeThree()
{
    result=result*base+3;
    resstring+="3";
    ui->showLabel->setText(resstring);
}

void MainWindow::recepeFour()
{
    result=result*base+4;
    resstring+="4";
    ui->showLabel->setText(resstring);
}

void MainWindow::recepeFive()
{
    result=result*base+5;
    resstring+="5";
    ui->showLabel->setText(resstring);
}

void MainWindow::recepeSix()
{
    result=result*base+6;
    resstring+="6";
    ui->showLabel->setText(resstring);
}

void MainWindow::recepeSeven()
{
    result=result*base+7;
    resstring+="7";
    ui->showLabel->setText(resstring);
}

void MainWindow::recepeEight()
{
    result=result*base+8;
    resstring+="8";
    ui->showLabel->setText(resstring);
}

void MainWindow::recepeNine()
{
    result=result*base+9;
    resstring+="9";
    ui->showLabel->setText(resstring);
}

void MainWindow::recepeA()
{
    result=result*base+10;
    resstring+="A";
    ui->showLabel->setText(resstring);
}

void MainWindow::recepeB()
{
    result=result*base+11;
    resstring+="B";
    ui->showLabel->setText(resstring);
}

void MainWindow::recepeC()
{
    result=result*base+12;
    resstring+="C";
    ui->showLabel->setText(resstring);
}

void MainWindow::recepeD()
{
    result=result*base+13;
    resstring+="D";
    ui->showLabel->setText(resstring);
}

void MainWindow::recepeE()
{
    result=result*base+14;
    resstring+="E";
    ui->showLabel->setText(resstring);
}

void MainWindow::recepeF()
{
    result=result*base+15;
    resstring+="F";
    ui->showLabel->setText(resstring);
}
void MainWindow::trans_to_bin()
{
    if(result==-1)
        resstring.setNum(result_temp,2);
    else
    {
        resstring.setNum(result,2);
        result_temp=result;
         result=-1;
    }
    ui->showLabel->setText(resstring);
}

void MainWindow::trans_to_oct()
{

    if(result==-1)
        resstring.setNum(result_temp,8);
    else
    {
        resstring.setNum(result,8);
        result_temp=result;
         result=-1;
    }
    ui->showLabel->setText(resstring);
}
void MainWindow::trans_to_dec()
{
     if(result==-1)
        resstring.setNum(result_temp,10);
    else
    {
        resstring.setNum(result,10);
        result_temp=result;
         result=-1;
    }
    ui->showLabel->setText(resstring);
}
void MainWindow::trans_to_hex()
{

     if(result==-1)
        resstring.setNum(result_temp,16);
    else
    {
        resstring.setNum(result,16);
        result_temp=result;
         result=-1;
    }
    ui->showLabel->setText(resstring);
}
void MainWindow::clear()
{
    result=0;
    result_temp=0;
    resstring="";
    ui->showLabel->setText(resstring);
}

