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
        HandlerElement *addHandler(HandlerElement *handler, const std::string &messageName = "") final;
        HandlerElement *deleteHandler(HandlerElement *handler, const std::string &messageName = "") final;
        void deleteRoutingMessage(std::string messageName);

        HandlerElementType getElementType() const final;

    private:
        std::map<std::string, std::list<HandlerElement *>> routingMap;

        void injectMessage(google::protobuf::Message *msg) final;
        void injectMessage(google::protobuf::Message *msg, void **result) final;
    };

}

#endif // __ROUTER_H__