#include "myspotify.h"
#include "spotifyapp.h"
#include "./ui_myspotify.h"

MySpotify::MySpotify(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MySpotify)
{
    ui->setupUi(this);
    SpotifyApp();
}


MySpotify::~MySpotify()
{
    delete ui;
}

