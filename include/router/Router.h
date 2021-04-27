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
        void injectMessage(google::protobuf::Message *msg);
        void addRoutingElement(std::string messageName, HandlerElement *routingElement);
        void deleteRoutingElement(std::string messageName, HandlerElement *routingElement);
        void deleteRoutingMessage(std::string messageName);

    private:
        std::map<std::string, std::list<HandlerElement *>> routingMap;
    };

}

#endif // __ROUTER_H__