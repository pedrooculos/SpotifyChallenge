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

    std::string searchResult = spotifyApp.search(textedString.toStdString());

    QJsonObject searchResultJson = strToQjsonObj(searchResult);

    std::string result = takeTrackNameListFromJson(searchResultJson);

    //std::cout << result.toStdString() << std::endl;

    ui->searchResultsTextBox->setPlainText(result.c_str());
}




