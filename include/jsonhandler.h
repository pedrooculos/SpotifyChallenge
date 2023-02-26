#ifndef JSONHANDLER_H
#define JSONHANDLER_H

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QString>
#include <QFile>
#include <iostream>

QJsonObject strToQjsonObj(const std::string&);

std::string takeTrackNameListFromJson(const QJsonObject& searchResultJsonObject);

std::string takeArtistName(const QJsonObject& trackInformation);

std::string takeId(const QJsonObject& trackInformation);

void writeJsonArrayToFile(const QJsonArray& jsonArray, const std::string& fileName);

QJsonArray readJsonArrayFromFile(const std::string fileName);

#endif // JSONHANDLER_H
