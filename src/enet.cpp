
#include "enet.hpp"
#include "exception.hpp"

namespace enetpp
{
    Enet::Enet()
    {
        if(enet_initialize() != 0)
        {
            throw(Exception("jaja"));
        }
    }

    Enet::~Enet()
    {
        enet_deinitialize();
    }

}
