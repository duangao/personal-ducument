#include "md.h"
#include <QApplication>
#include <QtWebKitWidgets/QWebView>
#include <QStyle>
#include<QPixmap>
#include<QBrush>
#include "parse.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    md w;
    QPalette p;
    p.setBrush(w.backgroundRole(),QBrush(QImage(":/file/back")));
    w.setPalette(p);

    a.setStyle("plastique");
    w.show();

    return a.exec();
}
