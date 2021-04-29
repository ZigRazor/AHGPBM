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
        void injectMessage(google::protobuf::Message *msg) override final;
        void injectMessage(google::protobuf::Message *msg, void **result) override final;
        HandlerElement *addHandler(HandlerElement *handler, const std::string &messageName = "") override final;
        HandlerElement *deleteHandler(HandlerElement *handler, const std::string &messageName = "") override final;
        void deleteHandlerMessage(std::string messageName);
        HandlerElementType getElementType() const override final;

    private:
        std::map<std::string, std::list<HandlerElement *>> handlerMap;
    };

}

#endif // __DISPATCHER_H__