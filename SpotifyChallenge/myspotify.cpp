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


void MySpotify::on_searchButton_clicked()
{
    QString textedString = ui->searchText->toPlainText();
    ui->searchText->clear();

    std::string searchResult = spotifyApp.search(textedString.toStdString());

    QJsonObject searchResultJson = strToQjsonObj(searchResult);

    std::string result = takeTrackNameListFromJson(searchResultJson);

    ui->searchResultsTextBox->setPlainText(result.c_str());

}


void MySpotify::on_addPushButton_clicked()
{
    QString textedStr = ui->playlistInput->toPlainText();
    ui->playlistInput->clear();

    spotifyApp.createPlaylist("Minha Play");
    spotifyApp.addTrackToPlaylist(textedStr.toStdString(),"MyPlaylist");

    std::vector<Playlists> playlists = spotifyApp.getPlaylists();

    ui->searchResultsTextBox->setPlainText(playlists[0].getName().c_str());

    QJsonObject track = playlists[0].getPlaylist()[0].toObject();

    ui->searchResultsTextBox->setPlainText(track["id"].toString().toStdString().c_str());
}




void MySpotify::on_deletePushButton_clicked()
{
    QString textedStr = ui->playlistInput->toPlainText();
    ui->playlistInput->clear();
}

