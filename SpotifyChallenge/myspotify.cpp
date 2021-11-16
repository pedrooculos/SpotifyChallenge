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

void MySpotify::printPlaylist(const std::string& playlistName){
    std::string strToPrint = this->spotifyApp.printPlaylist(playlistName);
    ui->playlistOut->setPlainText(strToPrint.c_str());
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
    QString playlistName = ui->playlistName->toPlainText();

    this->spotifyApp.addTrackToPlaylist(textedStr.toStdString(),playlistName.toStdString());

    this->printPlaylist(playlistName.toStdString());
}




void MySpotify::on_deletePushButton_clicked()
{
    QString textedStr = ui->playlistInput->toPlainText();
    ui->playlistInput->clear();
    QString playlistName = ui->playlistName->toPlainText();

    this->spotifyApp.deleteTrackFromPlaylist(textedStr.toStdString(),playlistName.toStdString());
    this->printPlaylist(playlistName.toStdString());
}

