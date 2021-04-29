#ifndef __HANDLER_H__
#define __HANDLER_H__

#include "google/protobuf/message.h"
#include "base/HandlerElement.h"

namespace AHGPBM
{
    class Handler : public HandlerElement
    {
    public:        
        HandlerElementType getElementType() const final;
        HandlerElement *addHandler(HandlerElement *handler, const std::string &messageName = "") final;
        HandlerElement *deleteHandler(HandlerElement *handler, const std::string &messageName = "") final;
    
    protected:
        virtual void *run(google::protobuf::Message *msg) = 0;
    
    private:
        void injectMessage(google::protobuf::Message *msg) final;
        void injectMessage(google::protobuf::Message *msg, void **result) final;

    };

}

#endif // __HANDLER_H__