
#include "event.hpp"
#include "exception.hpp"

namespace enetpp
{
    Event::Event()
    {
    }


    std::uint8_t Event::getChannel()
    {
        return(event.channelID);
    }

    std::uint32_t Event::getData()
    {
        return(event.data);
    }

    ENetEventType Event::getType()
    {
        return(event.type);
    }

    ENetEvent* Event::getEvent()
    {
        return(&event);
    }

    Packet Event::getPacket()
    {
        return(Packet(event.packet));
    }

    Peer Event::getPeer()
    {
        return(Peer(event.peer));
    }
}