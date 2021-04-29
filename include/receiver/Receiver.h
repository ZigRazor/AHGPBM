#ifndef __RECEIVER_H__
#define __RECEIVER_H__

#include "google/protobuf/message.h"
#include "base/HandlerElement.h"
#include <list>

namespace AHGPBM
{
    class Receiver : public HandlerElement
    {
    public:
        Receiver();
        ~Receiver();
        void injectMessage(google::protobuf::Message *msg) final;
        void injectMessage(google::protobuf::Message *msg, void **result) final;

        HandlerElement *addHandler(HandlerElement *handler, const std::string &messageName = "") final;
        HandlerElement *deleteHandler(HandlerElement *handler, const std::string &messageName = "") final;

        HandlerElementType getElementType() const final;

    private:
        std::list<HandlerElement *> handlerList;
    };
}

#endif // __RECEIVER_H__