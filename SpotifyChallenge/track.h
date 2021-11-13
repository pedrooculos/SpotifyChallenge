#ifndef TRACK_H
#define TRACK_H

#include <QJsonObject>
#include <string>
#include <curlhandler.h>

class Track
{
    public:
        Track(const std::string& id,const QJsonObject& trackJsonObject);

        const QJsonObject getTrackObject();
        const std::string getTrackId();

    private:
        std::string id;
        QJsonObject trackObject;
};

#endif // TRACK_H
