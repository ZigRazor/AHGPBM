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
        void injectMessage(google::protobuf::Message *msg) override final;
        void injectMessage(google::protobuf::Message *msg, void **result) override final;

        HandlerElement *addHandler(HandlerElement *handler, const std::string &messageName = "") override final;
        HandlerElement *deleteHandler(HandlerElement *handler, const std::string &messageName = "") override final;

        HandlerElementType getElementType() const override final;

    private:
        std::list<HandlerElement *> handlerList;
    };
}

#endif // __RECEIVER_H__