#ifndef __HANDLERELEMENT_H__
#define __HANDLERELEMENT_H__

#include "google/protobuf/message.h"

namespace AHGPBM
{
    class HandlerElement
    {
    public:
        virtual void injectMessage(google::protobuf::Message *msg) = 0;
    };
}

#endif // __HANDLERELEMENT_H__