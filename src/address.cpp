
#include "address.hpp"
#include "exception.hpp"

namespace enetpp
{
    Address::Address()
    {

    }

    Address::Address(std::uint32_t host, std::uint16_t port)
    {
        setHost(host);
        setPort(port);
    }

    Address::Address(std::string host, std::uint16_t port)
    {
        setHost(host);
        setPort(port);
    }

    Address::Address(ENetAddress& enetAddress): enetAddress(enetAddress)
    {

    }

    void Address::setHost(std::uint32_t host)
    {
        enetAddress.host = host;
    }

    void Address::setHost(std::string host)
    {
        if(enet_address_set_host(&enetAddress, host.c_str()) < 0)
        {
            throw(Exception("addr"));
        }
    }

    /*std::uint32_t Address::getHost()
    {
        return(enetAddress.host);
    }*/

    std::string Address::getHost()
    {
        char host[256];
        enet_address_get_host_ip(&enetAddress, host, sizeof(host));
        return(std::string(host));
    }

    void Address::setPort(std::uint16_t port)
    {
        enetAddress.port = port;
    }

    std::uint16_t Address::getPort()
    {
        return(enetAddress.port);
    }

    ENetAddress* Address::getEnetAddress()
    {
        return(&enetAddress);
    }
}
