#include "dispatcher/Dispatcher.h"

namespace AHGPBM
{

    Dispatcher::Dispatcher()
    {
    }

    Dispatcher::~Dispatcher()
    {
    }

    void Dispatcher::injectMessage(google::protobuf::Message *msg)
    {
        if (handlerMap.find(msg->GetDescriptor()->name()) != handlerMap.end())
        {
            std::list<HandlerElement *> &handlerList = handlerMap.at(msg->GetDescriptor()->name());
            std::list<HandlerElement *>::const_iterator it;
            for (it = handlerList.begin(); it != handlerList.end(); ++it)
            {
                (*it)->injectMessage(msg);
            }
        }
    }

    void Dispatcher::injectMessage(google::protobuf::Message *msg, void **result)
    {

        if (handlerMap.find(msg->GetDescriptor()->name()) != handlerMap.end())
        {
            std::list<HandlerElement *> &handlerList = handlerMap.at(msg->GetDescriptor()->name());
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

    HandlerElement *Dispatcher::addHandler(HandlerElement *handler, const std::string &messageName)
    {
        if (messageName != "")
        {
            if (handler->getElementType() == HandlerElementType::HANDLER)
            {
                std::cout << "Dispatcher::addHandler2" << std::endl;
                handlerMap[messageName].push_back(handler);
            }
            else
            {
                //Not allowed to add element different from HANDLER
                return nullptr;
            }
        }
        else
        {
            //Not allowed call without message
            return nullptr;
        }
        return handler;
    }

    HandlerElement *Dispatcher::deleteHandler(HandlerElement *handler, const std::string &messageName)
    {
        if (messageName != "")
        {
            if (handlerMap.find(messageName) != handlerMap.end())
            {
                std::list<HandlerElement *> &handlerList = handlerMap.at(messageName);
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
            //Not allowed call without message
            return nullptr;
        }
        //Not found handler
        return nullptr;
    }

    void Dispatcher::deleteHandlerMessage(std::string messageName)
    {
        handlerMap.erase(handlerMap.find(messageName));
    }

    HandlerElementType Dispatcher::getElementType() const
    {
        return HandlerElementType::DISPATCHER;
    }
}