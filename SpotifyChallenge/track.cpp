#include "track.h"

Track::Track(const std::string& id,const QJsonObject& trackObject)
{
    this->id = id;
    this->trackObject = trackObject;
}


const QJsonObject Track::getTrackObject()
{
    return this->trackObject;
}

const std::string Track::getTrackId()
{
    return this->getTrackId();
}
