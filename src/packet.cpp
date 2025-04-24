
#include <cstring>
#include "packet.hpp"
#include "exception.hpp"

namespace enetpp
{


    Packet::Packet(ENetPacket* enetPacket): enetPacket(enetPacket), position(0) {}
    
    Packet::Packet(const void* data, size_t length, std::uint32_t flags): position(0)
    {
        if((enetPacket = enet_packet_create(data, length, flags)) == NULL)
        {
            throw(Exception("e packk"));
        }
    }

    size_t Packet::getSize()
    {
        return(enetPacket->dataLength);
    }

    std::uint32_t Packet::getFlag()
    {
        return(enetPacket->flags);
    }

    std::uint8_t* Packet::getData()
    {
        return(enetPacket->data);
    }

    ENetPacket* Packet::getEnetPacket()
    {
        return(enetPacket);
    }

    /*Packet& Packet::operator >>(std::uint8_t& data)
    {
        data = *reinterpret_cast<const std::uint8_t*>(&enetPacket->data[position]);
        position = position + sizeof(data);

        return(*this);
    }*/


    /*Packet& Packet::operator >>(bool& data)
    {
        std::uint8_t value;
        if(*this >> value)
        {
            data = (value != 0);
        }

        return(*this);
    }*/

    Packet& Packet::operator >>(std::int8_t& data)
    {
        data = *reinterpret_cast<const std::int8_t*>(&enetPacket->data[position]);
        position = position + sizeof(data);

        return(*this);
    }

    Packet& Packet::operator >>(std::uint8_t& data)
    {
        data = *reinterpret_cast<const std::uint8_t*>(&enetPacket->data[position]);
        position = position + sizeof(data);

        return(*this);
    }

    Packet& Packet::operator >>(std::int16_t& data)
    {
        //data = ntohs(*reinterpret_cast<const std::int16_t*>(&enetPacket->data[position]));
        data = *reinterpret_cast<const std::int16_t*>(&enetPacket->data[position]);
        position = position + sizeof(data);

        return(*this);
    }

    Packet& Packet::operator >>(std::uint16_t& data)
    {
        //data = ntohs(*reinterpret_cast<const std::uint16_t*>(&enetPacket->data[position]));
        data = *reinterpret_cast<const std::uint16_t*>(&enetPacket->data[position]);
        position = position + sizeof(data);

        return(*this);
    }
    
    Packet& Packet::operator >>(std::int32_t& data)
    {
        //data = ntohl(*reinterpret_cast<const std::int32_t*>(&enetPacket->data[position]));
        data = *reinterpret_cast<const std::int32_t*>(&enetPacket->data[position]);
        position = position + sizeof(data);

        return(*this);
    }

    Packet& Packet::operator >>(std::uint32_t& data)
    {
        //data = ntohl(*reinterpret_cast<const std::uint32_t*>(&enetPacket->data[position]));
        data = *reinterpret_cast<const std::uint32_t*>(&enetPacket->data[position]);
        position = position + sizeof(data);

        return(*this);
    }

    Packet& Packet::operator >>(std::int64_t& data)
    {
        const std::uint8_t* bytes = reinterpret_cast<const std::uint8_t*>(&enetPacket->data[position]);
        data = (static_cast<std::int64_t>(bytes[0]) << 56) |
               (static_cast<std::int64_t>(bytes[1]) << 48) |
               (static_cast<std::int64_t>(bytes[2]) << 40) |
               (static_cast<std::int64_t>(bytes[3]) << 32) |
               (static_cast<std::int64_t>(bytes[4]) << 24) |
               (static_cast<std::int64_t>(bytes[5]) << 16) |
               (static_cast<std::int64_t>(bytes[6]) <<  8) |
               (static_cast<std::int64_t>(bytes[7])      );
        position = position + sizeof(data);

        return(*this);
    }

    Packet& Packet::operator >>(std::uint64_t& data)
    {
        const std::uint8_t* bytes = reinterpret_cast<const std::uint8_t*>(&enetPacket->data[position]);
        data = (static_cast<std::uint64_t>(bytes[0]) << 56) |
               (static_cast<std::uint64_t>(bytes[1]) << 48) |
               (static_cast<std::uint64_t>(bytes[2]) << 40) |
               (static_cast<std::uint64_t>(bytes[3]) << 32) |
               (static_cast<std::uint64_t>(bytes[4]) << 24) |
               (static_cast<std::uint64_t>(bytes[5]) << 16) |
               (static_cast<std::uint64_t>(bytes[6]) <<  8) |
               (static_cast<std::uint64_t>(bytes[7])      );
        position = position + sizeof(data);

        return(*this);
    }

    Packet& Packet::operator >>(float& data)
    {
        data = *reinterpret_cast<const float*>(&enetPacket->data[position]);
        position = position + sizeof(data);

        return(*this);
    }

    Packet& Packet::operator >>(double& data)
    {
        data = *reinterpret_cast<const double*>(&enetPacket->data[position]);
        position = position + sizeof(data);

        return(*this);
    }

    Packet& Packet::operator >>(char* data)
    {
        std::uint32_t length = 0;
        *this >> length;
        std::memcpy(data, reinterpret_cast<char*>(&enetPacket->data[position]), length);
        data[length] = '\0';
        position = position + length;
        
        return *this;
    }
/*Packet& Packet::operator >>(char* data)
{
    // First extract string length
    Uint32 length = 0;
    *this >> length;

    if ((length > 0) && checkSize(length))
    {
        // Then extract characters
        std::memcpy(data, &m_data[m_readPos], length);
        data[length] = '\0';

        // Update reading position
        m_readPos += length;
    }

    return *this;
}*/

    Packet& Packet::operator >>(std::string& data)
    {
        std::uint32_t length = 0;
        *this >> length;
        data.clear();
        data.assign(reinterpret_cast<const char*>(&enetPacket->data[position]), length);
        position = position + length;

        return *this;
    }
/*
Packet& Packet::operator >>(std::string& data)
{
    // First extract string length
    Uint32 length = 0;
    *this >> length;

    data.clear();
    if ((length > 0) && checkSize(length))
    {
        // Then extract characters
        data.assign(&m_data[m_readPos], length);

        // Update reading position
        m_readPos += length;
    }

    return *this;
}*/







    /*Packet& Packet::operator <<(bool data)
    {
        *this << static_cast<std::uint8_t>(data);

        return(*this);
    }*/

    Packet& Packet::operator <<(std::int8_t data)
    {
        append(&data, sizeof(data));

        return(*this);
    }

    Packet& Packet::operator <<(std::uint8_t data)
    {
        //std::size_t startPosition = this->data.size();
        //this->data.resize(startPosition + sizeof(data));
        //std::memcpy(&this->data[startPosition], &data, sizeof(data));
        append(&data, sizeof(data));

        return(*this);
    }

    Packet& Packet::operator <<(std::int16_t data)
    {
        append(&data, sizeof(data));

        return(*this);
    }

    Packet& Packet::operator <<(std::uint16_t data)
    {
        append(&data, sizeof(data));

        return(*this);
    }

    Packet& Packet::operator <<(std::int32_t data)
    {
        append(&data, sizeof(data));

        return(*this);
    }

    Packet& Packet::operator <<(std::uint32_t data)
    {
        append(&data, sizeof(data));

        return(*this);
    }

    Packet& Packet::operator <<(std::int64_t data)
    {
        std::uint8_t value[] =
        {
            static_cast<std::uint8_t>((data >> 56) & 0xFF),
            static_cast<std::uint8_t>((data >> 48) & 0xFF),
            static_cast<std::uint8_t>((data >> 40) & 0xFF),
            static_cast<std::uint8_t>((data >> 32) & 0xFF),
            static_cast<std::uint8_t>((data >> 24) & 0xFF),
            static_cast<std::uint8_t>((data >> 16) & 0xFF),
            static_cast<std::uint8_t>((data >>  8) & 0xFF),
            static_cast<std::uint8_t>((data      ) & 0xFF)
        };

        append(&value, sizeof(value));
        
        return(*this);
    }

    Packet& Packet::operator <<(std::uint64_t data)
    {
        std::uint8_t value[] =
        {
            static_cast<std::uint8_t>((data >> 56) & 0xFF),
            static_cast<std::uint8_t>((data >> 48) & 0xFF),
            static_cast<std::uint8_t>((data >> 40) & 0xFF),
            static_cast<std::uint8_t>((data >> 32) & 0xFF),
            static_cast<std::uint8_t>((data >> 24) & 0xFF),
            static_cast<std::uint8_t>((data >> 16) & 0xFF),
            static_cast<std::uint8_t>((data >>  8) & 0xFF),
            static_cast<std::uint8_t>((data      ) & 0xFF)
        };

        append(&value, sizeof(value));
        
        return(*this);
    }

    Packet& Packet::operator <<(float data)
    {
        append(&data, sizeof(data));

        return(*this);
    }

    Packet& Packet::operator <<(double data)
    {
        append(&data, sizeof(data));

        return(*this);
    }

    Packet& Packet::operator <<(const char* data)
    {
        std::uint32_t length = static_cast<std::uint32_t>(std::strlen(data));
        *this << length;
        append(&data, length + sizeof(char));

        return(*this);
    }

    Packet& Packet::operator <<(const std::string& data)
    {
        std::uint32_t length = static_cast<std::uint32_t>(data.size());
        *this << length;
        append(data.c_str(), length + sizeof(std::string::value_type));

        return(*this);
    }









    /*Packet& Packet::operator <<(bool data)
    {
        *this << static_cast<std::uint8_t>(data);

        return(*this);
    }*/


    /*Packet& Packet::operator <<(std::uint8_t data)
    {
        //std::size_t length = getLength();
        //enet_packet_resize(enetPacket, length + sizeof(data));
        //std::memcpy(&enetPacket->data[length], &data, sizeof(data));

        append(&data, sizeof(data));
        return(*this);
    }*/




    void Packet::append(const void* data, std::size_t size)
    {
        if(data != nullptr && size > 0)
        {
            std::size_t start = getSize();
            enet_packet_resize(enetPacket, start + size);
            std::memcpy(&enetPacket->data[start], data, size);
        }
    }

    void* Packet::prepend()
    {
        return(nullptr);
    }

    void Packet::destroy()
    {
        enet_packet_destroy(enetPacket);
    }
}