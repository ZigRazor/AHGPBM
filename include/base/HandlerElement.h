#ifndef __HANDLERELEMENT_H__
#define __HANDLERELEMENT_H__

#include "google/protobuf/message.h"

namespace AHGPBM
{

    enum class HandlerElementType
    {
        RECEIVER,
        ROUTER,
        DISPATCHER,
        HANDLER
    };
    class HandlerElement
    {
    public:
        virtual void injectMessage(google::protobuf::Message *msg) = 0;
        virtual void injectMessage(google::protobuf::Message *msg, void **result) = 0;
        virtual HandlerElementType getElementType() const = 0;
        virtual HandlerElement *addHandler(HandlerElement *handler, const std::string &messageName = "") = 0;
        virtual HandlerElement *deleteHandler(HandlerElement *handler, const std::string &messageName = "") = 0;
    };

}

#endif // __HANDLERELEMENT_H__