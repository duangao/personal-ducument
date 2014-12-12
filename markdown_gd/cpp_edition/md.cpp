#include "parse.h"
#include "md.h"
#include "ui_md.h"
#include <iostream>
#include <QDir>
#include <QStyle>
#include <QScrollBar>
#include <QWebFrame>

md::md(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::md)
{
    ui->setupUi(this);

    //QPalette pal ;
     //pal.setBrush(QPalette::Base, Qt::transparent);
    // ui->webView->setPalette(pal);


    QDir dir;
    QString path=dir.currentPath();
    //std::cout<<path.toStdString()<<std::endl;

    pos_left=0;
    pos=std::vector<int>(100);
    connect(ui->make,SIGNAL(clicked()),this,SLOT(make()));
    connect(ui->preview,SIGNAL(clicked()),this,SLOT(preview()));
    connect(ui->plainTextEdit->verticalScrollBar(),SIGNAL(valueChanged(int)),this,SLOT(scrollST()));

}

md::~md()
{
    delete ui;
}
void md::make() {
    QString text=ui->plainTextEdit->toPlainText();
   QStringList md_source=text.split("\n");
   QFile file(path+"result.html");
   if(!file.open(QIODevice::WriteOnly | QIODevice::Truncate))  {
      qDebug("not open!");
      return;
   }
   QTextStream out(&file);
   out<< "<style type=\"text/css\">div {display: block;font-family: Consolas}\
          #wrapper { width: 100%;height:100%; margin: 0; padding: 0;}#left { float:left; \
         width: 15%;  height: 100%;  }#second {   float:left;   width: 70%;height: 100%;   \
        }#right {float:left;  width: 15%;  height: 100%; \
        }</style><div id=\"wrapper\"> <div id=\"left\"></div><div id=\"second\">";

    foreach(QString line,md_source) {
       QString parse_line=parse(line.toStdString()).c_str();
       out<<parse_line<<"\n";
   }
    out<< "</br></br></div><div id=\"right\"></div></div>";
   file.close();
}
void md::preview() {
    QFile read(path+"result.html");
    if(! read.open(QIODevice::ReadOnly | QIODevice::Truncate) ) {
        qDebug("not open!");
        return;
    }
    QString result;
    QTextStream in(&read);
    while(!in.atEnd()) {
        QString line=in.readLine();
        result+=line;
    }
    read.close();
    ui->webView->setHtml(result,QUrl());
}

void md::scrollST() {
    pos_left=ui->plainTextEdit->verticalScrollBar()->value();
    int max_left=ui->plainTextEdit->verticalScrollBar()->maximum();
    int max_right=ui->webView->page()->mainFrame()->scrollBarMaximum(Qt::Vertical);
    std::cout<<pos_left<<" "<<max_left<<std::endl;

    double ratio=(double)pos_left/(double)max_left;
    std::cout<<ratio<<std::endl;
    double pos_right=max_right*ratio;
    std::cout<<pos_right<<" "<<max_right<<std::endl;
    ui->webView->page()->mainFrame()->setScrollBarValue(Qt::Vertical,max_right*ratio);
}
