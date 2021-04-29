#ifndef __DISPATCHER_H__
#define __DISPATCHER_H__

#include "base/HandlerElement.h"
#include <map>
#include <list>

namespace AHGPBM
{
    class Dispatcher : public HandlerElement
    {
    public:
        Dispatcher();
        ~Dispatcher();
        void injectMessage(google::protobuf::Message *msg) final;
        void injectMessage(google::protobuf::Message *msg, void **result) final;
        HandlerElement *addHandler(HandlerElement *handler, const std::string &messageName = "") final;
        HandlerElement *deleteHandler(HandlerElement *handler, const std::string &messageName = "") final;
        void deleteHandlerMessage(std::string messageName);
        HandlerElementType getElementType() const final;

    private:
        std::map<std::string, std::list<HandlerElement *>> handlerMap;
    };

}

#endif // __DISPATCHER_H__