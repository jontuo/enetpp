
#ifndef __ENETPP_ADDRESS_HPP_INCLUDED__
#define __ENETPP_ADDRESS_HPP_INCLUDED__

#include <cstdint>
#include <enet/enet.h>
#include <string>

namespace enetpp
{
    class Address
    {
        public:
            Address();
            Address(std::uint32_t host, std::uint16_t port);
            Address(std::string host, std::uint16_t port);
            Address(ENetAddress& enetAddress);

            void setHost(std::uint32_t host);
            void setHost(std::string host);
            //std::uint32_t getHost();
            std::string getHost();


            void setPort(std::uint16_t port);
            std::uint16_t getPort();

            ENetAddress* getEnetAddress();

        private:
            ENetAddress enetAddress;
    };
}

#endif
