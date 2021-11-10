#include "myspotify.h"
#include "./ui_myspotify.h"

MySpotify::MySpotify(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MySpotify)
{
    ui->setupUi(this);
}

MySpotify::~MySpotify()
{
    delete ui;
}

