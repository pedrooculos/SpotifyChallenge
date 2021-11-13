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

    QJsonObject firstTrack = trackList[0].toObject();

    QString firstTrackName = firstTrack["name"].toString();



    std::string trackSearchResult = "Name: " + firstTrackName.toStdString() + " ";
    trackSearchResult += "Artist: " + takeArtistName(firstTrack);

    return trackSearchResult;
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


