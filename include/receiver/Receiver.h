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
        void receiveMessage(google::protobuf::Message *msg);
        void receiveMessage(google::protobuf::Message *msg, void **result);

        HandlerElement *addHandler(HandlerElement *handler, const std::string &messageName = "") final;
        HandlerElement *deleteHandler(HandlerElement *handler, const std::string &messageName = "") final;

        HandlerElementType getElementType() const final;

    private:
        std::list<HandlerElement *> handlerList;

        void injectMessage(google::protobuf::Message *msg) final;
        void injectMessage(google::protobuf::Message *msg, void **result) final;
    };
}

#endif // __RECEIVER_H__