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
    ui->searchResultsTextBox->setPlainText(textedString.toStdString().c_str());
}




