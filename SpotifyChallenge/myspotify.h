#ifndef MYSPOTIFY_H
#define MYSPOTIFY_H

#include <QMainWindow>
#include <iostream>
#include "spotifyapp.h"

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

    void on_addPushButton_clicked();

    void on_deletePushButton_clicked();

private:
    Ui::MySpotify *ui;
    SpotifyApp spotifyApp;
};
#endif // MYSPOTIFY_H
