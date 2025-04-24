
#include "exception.hpp"



namespace enetpp
{
    Exception::Exception(std::string reason): reason(reason) {}

    const char* Exception::getReason() const
    {
        return reason.c_str();
    }
}
