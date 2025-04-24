#ifndef __ENETPP_PEER_HPP_INCLUDED__
#define __ENETPP_PEER_HPP_INCLUDED__

#include <cstdint>
#include <enet/enet.h>
#include "packet.hpp"
#include "address.hpp"

namespace enetpp
{
    class Peer
    {
        public:
            Peer(ENetPeer* peer);
            Peer(const Peer& peer);
            Peer(Peer&& peer);

            Peer& operator=(Peer&& peer);

            void ping();
            void setPingInterval(std::uint32_t interval);
            bool quePacket(std::uint8_t channel, Packet& packet);
            Packet dequePacket();
            void disconnect(std::uint32_t data);
            void disconnect_later(std::uint32_t data);
            void disconnect_now(std::uint32_t data);
            Address getAddress();
            ENetPeer* getEnetPeer();
            void* getUserData(); // Change name to getUser.
            void setUserData(void* userData); // Change name to setUser and overload stream operators.

        private:
            ENetPeer* enetPeer;
    };
}

#endif