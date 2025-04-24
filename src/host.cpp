
#include "host.hpp"
#include "exception.hpp"

namespace enetpp
{
    Host::Host(Address address, size_t peerLimit, size_t channelLimit, std::uint32_t incomingBandwidth, std::uint32_t outgoingBandwidth)
    {
        if((enetHost = enet_host_create(address.getEnetAddress(), peerLimit, channelLimit, incomingBandwidth, outgoingBandwidth)) == NULL)
        {
            throw(Exception("hosts"));
        }
    }

    Host::Host(size_t peerLimit, size_t channelLimit, std::uint32_t incomingBandwidth, std::uint32_t outgoingBandwidth)
    {
        if((enetHost = enet_host_create(NULL, peerLimit, channelLimit, incomingBandwidth, outgoingBandwidth)) == NULL)
        {
            throw(Exception("hosts"));
        }
    }

    Host::~Host()
    {
        enet_host_destroy(enetHost);
    }

    ENetHost* Host::getHost()
    {
        return(enetHost);
    }

    Peer Host::connect(Address address, size_t channelLimit, std::uint32_t userData)
    {
        ENetPeer* enetPeer;
        if((enetPeer = enet_host_connect(enetHost, address.getEnetAddress(), channelLimit, userData)) == NULL)
        {
            throw(Exception("e conn"));
        }

        return(Peer(enetPeer));
    }

    void Host::flush()
    {
        enet_host_flush(enetHost);
    }

    bool Host::service(Event& event)
    {
        signed int status = enet_host_service(enetHost, event.getEvent(), 0);
        if(status > 0)
        {
            return(true);
        }
        else if(status == 0)
        {
            return(false);
        }
        else
        {
            throw(Exception("enet service"));
        }
    }

    void Host::broadcast(std::uint8_t channelIdentifier, Packet& packet)
    {
        enet_host_broadcast(enetHost, channelIdentifier, packet.getEnetPacket());
    }

}
