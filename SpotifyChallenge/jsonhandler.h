#ifndef JSONHANDLER_H
#define JSONHANDLER_H

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QString>
#include <QFile>

QJsonObject strToQjsonObj(std::string&);

std::string takeTrackNameListFromJson(QJsonObject& searchResultJsonObject);

std::string takeArtistName(QJsonObject& trackInformation);

std::string takeId(QJsonObject& trackInformation);

void writeJsonArrayToFile(const QJsonArray& jsonArray, const std::string& fileName);

QJsonArray readJsonArrayFromFile(std::string fileName);

#endif // JSONHANDLER_H
