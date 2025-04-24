
#ifndef __ENETPP_PACKET_HPP_INCLUDED__
#define __ENETPP_PACKET_HPP_INCLUDED__

#include <string>
#include <cstdint>
#include <enet/enet.h>

namespace enetpp
{
    class Packet
    {
        public:
            Packet(ENetPacket* enetPacket);
            Packet(const void* data, size_t length, std::uint32_t flag);

            //Packet& operator >>(bool& data);
            Packet& operator >>(std::int8_t& data);
            Packet& operator >>(std::uint8_t& data);
            Packet& operator >>(std::int16_t& data);
            Packet& operator >>(std::uint16_t& data);
            Packet& operator >>(std::int32_t& data);
            Packet& operator >>(std::uint32_t& data);
            Packet& operator >>(std::int64_t& data);
            Packet& operator >>(std::uint64_t& data);
            Packet& operator >>(float& data);
            Packet& operator >>(double& data);
            Packet& operator >>(char* data);
            Packet& operator >>(std::string& data);

            //Packet& operator <<(bool data);
            Packet& operator <<(std::int8_t data);
            Packet& operator <<(std::uint8_t data);
            Packet& operator <<(std::int16_t data);
            Packet& operator <<(std::uint16_t data);
            Packet& operator <<(std::int32_t data);
            Packet& operator <<(std::uint32_t data);
            Packet& operator <<(std::int64_t data);
            Packet& operator <<(std::uint64_t data);
            Packet& operator <<(float data);
            Packet& operator <<(double data);
            Packet& operator <<(const char* data);
            Packet& operator <<(const std::string& data);



            size_t getSize();
            std::uint8_t* getData();
            std::uint32_t getFlag();
            ENetPacket* getEnetPacket();
            void destroy();

        private:
            ENetPacket* enetPacket;
            ENetPacketFlag enetFlag;
            std::size_t position;

            void append(const void* data, std::size_t size);
            void* prepend();
    };
}

#endif
