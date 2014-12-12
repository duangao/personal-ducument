#ifndef MD_H
#define MD_H

#include <QMainWindow>

namespace Ui {
class md;
}

class md : public QMainWindow
{
    Q_OBJECT

public:
    explicit md(QWidget *parent = 0);
    QString path;
    ~md();


public slots:
    void make();
    void preview();
    void scrollST();
private:
    Ui::md *ui;
    int pos_left;
    std::vector<int> pos;


};

#endif // MD_H
