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
        tracksSearchResult += "Name: " + firstTrackName.toStdString() + " ";
        tracksSearchResult += "Artist: " + artists + "\n\n";
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


