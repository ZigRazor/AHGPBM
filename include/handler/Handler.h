#ifndef __HANDLER_H__
#define __HANDLER_H__

#include "google/protobuf/message.h"
#include "base/HandlerElement.h"

namespace AHGPBM
{
    class Handler : public HandlerElement
    {
    public:
        void injectMessage(google::protobuf::Message *msg) override final;
        void injectMessage(google::protobuf::Message *msg, void **result) override final;
        HandlerElementType getElementType() const override final;
        HandlerElement *addHandler(HandlerElement *handler, const std::string &messageName = "") override final;
        HandlerElement *deleteHandler(HandlerElement *handler, const std::string &messageName = "") override final;
        virtual void *run(google::protobuf::Message *msg) = 0;
    };

}

#endif // __HANDLER_H__