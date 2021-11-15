#include "jsonhandler.h"


QJsonObject strToQjsonObj(std::string& stdString)
{
    QString qString;
    qString = qString.fromStdString(stdString);
    QJsonDocument jsonDocument =  QJsonDocument::fromJson(qString.toUtf8());
    QJsonObject jsonObject = jsonDocument.object();

    return jsonObject;
}


std::string takeTrackNameListFromJson(QJsonObject& searchResult)
{
    QJsonObject tracks = searchResult.take("tracks").toObject();

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


std::string takeArtistName(QJsonObject& trackInformation)
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

std::string takeId(QJsonObject& trackInformation)
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


