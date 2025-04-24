#ifndef __ENETPP_HOST_HPP_INCLUDED__
#define __ENETPP_HOST_HPP_INCLUDED__

#include <enet/enet.h>
#include "address.hpp"
#include "peer.hpp"
#include "event.hpp"
#include "packet.hpp"
#include <cstdint>

namespace enetpp
{
    class Host
    {
        public:
            Host(Address address, size_t peerLimit, size_t channelLimit, std::uint32_t incomingBandwidth, std::uint32_t outgoingBandwidth);
            Host(size_t peerLimit, size_t channelLimit, std::uint32_t incomingBandwidth, std::uint32_t outgoingBandwidth);
            ~Host();

            Peer connect(Address address, size_t channelLimit, std::uint32_t userData);

            ENetHost* getHost();
            void flush();
            bool service(Event& event);
            void broadcast(std::uint8_t channelIdentifier, Packet& packet);

        private:
            ENetHost* enetHost;
    };
}

#endif