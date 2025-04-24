
#ifndef __ENETPP_EVENT_HPP_INCLUDED__
#define __ENETPP_EVENT_HPP_INCLUDED__

#include <enet/enet.h>
#include "packet.hpp"
#include "peer.hpp"

namespace enetpp
{
    enum class EventType
    {
        NONE = ENET_EVENT_TYPE_NONE,
        CONNECT = ENET_EVENT_TYPE_CONNECT,
        DISCONNECT = ENET_EVENT_TYPE_DISCONNECT,
        PACKET = ENET_EVENT_TYPE_RECEIVE
    };

    class Event
    {
        public:
            Event();

            std::uint8_t getChannel();
            std::uint32_t getData();
            ENetEventType getType();
            ENetEvent* getEvent();
            Packet getPacket();
            Peer getPeer();

        private:
            ENetEvent event;            
    };
}

#endif
