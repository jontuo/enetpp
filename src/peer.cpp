
#include "peer.hpp"

namespace enetpp
{
    Peer::Peer(ENetPeer* peer): enetPeer(peer) {}

    Peer::Peer(const Peer& peer): enetPeer(peer.enetPeer) {}

    Peer::Peer(Peer&& peer)
    {
        enetPeer = peer.enetPeer;
        peer.enetPeer = NULL; // FIX: nullptr?
    }

    Peer& Peer::operator=(Peer&& peer)
    {
        enetPeer = peer.enetPeer;
        peer.enetPeer = NULL; // FIX: nullptr?
        return(*this);
    }

    void Peer::ping()
    {
        enet_peer_ping(enetPeer);
    }

    void Peer::setPingInterval(std::uint32_t interval)
    {
        enet_peer_ping_interval(enetPeer, interval);
    }

    bool Peer::quePacket(std::uint8_t channel, Packet& packet)
    {
        return(enet_peer_send(enetPeer, channel, packet.getEnetPacket()));
    }

    Packet Peer::dequePacket()
    {
        return(Packet(enet_peer_receive(enetPeer, NULL))); // ERROR??? This NULL might fuck it up!
    }

    void Peer::disconnect(std::uint32_t data)
    {
        enet_peer_disconnect(enetPeer, data);
    }

    void Peer::disconnect_later(std::uint32_t data)
    {
        enet_peer_disconnect_later(enetPeer, data);
    }

    void Peer::disconnect_now(std::uint32_t data)
    {
        enet_peer_disconnect_now(enetPeer, data);
    }

    Address Peer::getAddress()
    {
        return(Address(enetPeer->address));
    }

    ENetPeer* Peer::getEnetPeer()
    {
        return(enetPeer);
    }

    void* Peer::getUserData()
    {
        return(enetPeer->data);
    }

    void Peer::setUserData(void* userData)
    {
        enetPeer->data = userData;
    }
}