#ifndef __ROUTER_H__
#define __ROUTER_H__

#include "base/HandlerElement.h"
#include <map>
#include <list>
#include <string>

namespace AHGPBM
{
    class Router : public HandlerElement
    {
    public:
        Router();
        ~Router();
        void injectMessage(google::protobuf::Message *msg) override final;
        void injectMessage(google::protobuf::Message *msg, void **result) override final;
        HandlerElement *addHandler(HandlerElement *handler, const std::string &messageName = "") override final;
        HandlerElement *deleteHandler(HandlerElement *handler, const std::string &messageName = "") override final;
        void deleteRoutingMessage(std::string messageName);

        HandlerElementType getElementType() const override final;

    private:
        std::map<std::string, std::list<HandlerElement *>> routingMap;
    };

}

#endif // __ROUTER_H__