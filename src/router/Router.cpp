#include "router/Router.h"

namespace AHGPBM
{

    Router::Router()
    {
    }

    Router::~Router()
    {
    }

    void Router::injectMessage(google::protobuf::Message *msg)
    {
        if (routingMap.find(msg->GetDescriptor()->name()) != routingMap.end())
        {
            std::list<HandlerElement *> &handlerList = routingMap.at(msg->GetDescriptor()->name());
            std::list<HandlerElement *>::const_iterator it;
            for (it = handlerList.begin(); it != handlerList.end(); ++it)
            {
                (*it)->injectMessage(msg);
            }
        }
    }

    void Router::injectMessage(google::protobuf::Message *msg, void **result)
    {
        if (routingMap.find(msg->GetDescriptor()->name()) != routingMap.end())
        {
            std::list<HandlerElement *> &handlerList = routingMap.at(msg->GetDescriptor()->name());
            std::list<HandlerElement *>::const_iterator it;
            for (it = handlerList.begin(); it != handlerList.end(); ++it)
            {
                (*it)->injectMessage(msg, result);
            }
        }
        else
        {
            *result = nullptr;
        }
    }

    HandlerElement *Router::addHandler(HandlerElement *handler, const std::string &messageName)
    {
        if (messageName != "")
        {
            routingMap[messageName].push_back(handler);
        }
        else
        {
            //Not allowed call without messageName
            return nullptr;
        }
        return handler;
    }

    HandlerElement *Router::deleteHandler(HandlerElement *handler, const std::string &messageName)
    {
        if (messageName != "")
        {
            if (routingMap.find(messageName) != routingMap.end())
            {
                std::list<HandlerElement *> &handlerList = routingMap.at(messageName);
                std::list<HandlerElement *>::const_iterator handlerListIt;
                bool erased = false;
                for (handlerListIt = handlerList.begin(); !erased && handlerListIt != handlerList.end(); ++handlerListIt)
                {
                    if (*handlerListIt == handler)
                    {
                        handlerList.erase(handlerListIt);
                        erased = true;
                        return handler;
                    }
                }
            }
        }
        else
        {
            //Not allowed call without messageName
            return nullptr;
        }
        //Not found handler
        return nullptr;
    }

    void Router::deleteRoutingMessage(std::string messageName)
    {
        routingMap.erase(routingMap.find(messageName));
    }

    HandlerElementType Router::getElementType() const
    {
        return HandlerElementType::ROUTER;
    }

}