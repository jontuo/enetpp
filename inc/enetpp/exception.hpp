
#ifndef __ENETPP_EXCEPTION_HPP_INCLUDED__
#define __ENETPP_EXCEPTION_HPP_INCLUDED__

#include <string>



namespace enetpp
{
    class Exception: public std::exception
    {
        public:
            Exception(std::string reason);
            const char* getReason() const;
            std::string reason;
    };
}

#endif
