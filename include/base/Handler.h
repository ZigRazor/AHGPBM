#ifndef __HANDLER_H__
#define __HANDLER_H__

#include "google/protobuf/message.h"

namespace AHGPBM
{
    class Handler
    {
    public:
        virtual void *run(google::protobuf::Message *msg) = 0;
    };

}

#endif // __HANDLER_H__