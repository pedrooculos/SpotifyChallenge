#ifndef JSONHANDLER_H
#define JSONHANDLER_H

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

QJsonObject strToQjsonObj(std::string&);

std::string takeTrackNameListFromJson(QJsonObject& searchResultJsonObject);

std::string takeArtistName(QJsonObject& trackInformation);

std::string takeId(QJsonObject& trackInformation);

#endif // JSONHANDLER_H
