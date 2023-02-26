#include "include/jsonhandler.h"


QJsonObject strToQjsonObj(const std::string& stdString)
{
    QString qString;
    qString = qString.fromStdString(stdString);
    QJsonDocument jsonDocument =  QJsonDocument::fromJson(qString.toUtf8());
    QJsonObject jsonObject = jsonDocument.object();

    return jsonObject;
}


std::string takeTrackNameListFromJson(const QJsonObject& searchResult)
{
    QJsonObject tracks = searchResult["tracks"].toObject();

    QJsonArray trackList = tracks["items"].toArray();

    std::string tracksSearchResult;

    for(int i=0; i < trackList.size();i++)
    {
        QJsonObject trackJson = trackList[i].toObject();
        QString firstTrackName = trackJson["name"].toString();
        std::string artists = takeArtistName(trackJson);
        std::string trackId = takeId(trackJson);
        tracksSearchResult += "Name: " + firstTrackName.toStdString() + "\n";
        tracksSearchResult += "Artist: " + artists + "\n";
        tracksSearchResult += "Id: " + trackId +"\n";
        tracksSearchResult += "\n";
    }

    return tracksSearchResult;
}


std::string takeArtistName(const QJsonObject& trackInformation)
{
    QJsonArray artistList = trackInformation["artists"].toArray();

    std::string artistStr;

    for(int i=0; i < artistList.size(); i++)
    {
        QJsonObject artist = artistList[i].toObject();
        QString artistName = artist["name"].toString();
        artistStr += " " + artistName.toStdString();
    }

    return artistStr;
}

std::string takeId(const QJsonObject& trackInformation)
{
    return trackInformation["id"].toString().toStdString();
}

void writeJsonArrayToFile(const QJsonArray& jsonArray,const std::string& fileName)
{
    QJsonDocument jsonDoc(jsonArray);

    QString qStringFileName;
    qStringFileName = qStringFileName.fromStdString(fileName);
    QFile jsonFile(qStringFileName);

    jsonFile.open(QFile::WriteOnly | QFile::Text | QFile::Truncate);
    jsonFile.write(jsonDoc.toJson());
    jsonFile.close();
}

QJsonArray readJsonArrayFromFile(const std::string fileName)
{
    QString qStringFileName;
    qStringFileName = qStringFileName.fromStdString(fileName);
    QFile jsonFile(qStringFileName);

    QJsonArray jsonArray;
    if(jsonFile.open(QFile::ReadOnly| QFile::Text | QFile::Truncate))
    {
        QJsonDocument jsonDoc;
        jsonDoc = QJsonDocument::fromJson(jsonFile.readAll());
        jsonArray = jsonDoc.array();
    }

    return jsonArray;
}




