#ifndef MYSPOTIFY_H
#define MYSPOTIFY_H

#include <QMainWindow>
#include <iostream>

QT_BEGIN_NAMESPACE
namespace Ui { class MySpotify; }
QT_END_NAMESPACE

class MySpotify : public QMainWindow
{
    Q_OBJECT

public:
    MySpotify(QWidget *parent = nullptr);
    ~MySpotify();

private slots:
    void on_searchButton_clicked();

private:
    Ui::MySpotify *ui;
};
#endif // MYSPOTIFY_H
