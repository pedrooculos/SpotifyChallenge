#include "jsonhandler.h"


QJsonObject strToQjsonObj(std::string& stdString)
{
    QString qString;
    qString = qString.fromStdString(stdString);
    QJsonDocument jsonDocument =  QJsonDocument::fromJson(qString.toUtf8());
    QJsonObject jsonObject = jsonDocument.object();

    return jsonObject;
}


