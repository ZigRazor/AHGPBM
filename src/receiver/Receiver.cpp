#include "receiver/Receiver.h"

namespace AHGPBM
{

    Receiver::Receiver()
    {
    }

    Receiver::~Receiver()
    {
    }

    void Receiver::injectMessage(google::protobuf::Message *msg)
    {
        std::list<HandlerElement *>::const_iterator it;
        for (it = handlerList.begin(); it != handlerList.end(); ++it)
        {
            (*it)->injectMessage(msg);
        }
    }

    void Receiver::injectMessage(google::protobuf::Message *msg, void **result)
    {
        std::list<HandlerElement *>::const_iterator it;
        if (!handlerList.empty())
        {

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

    HandlerElement *Receiver::addHandler(HandlerElement *handler, const std::string &messageName)
    {
        if (handler->getElementType() == HandlerElementType::ROUTER ||
            handler->getElementType() == HandlerElementType::DISPATCHER)
        {
            handlerList.push_back(handler);
        }
        else
        {
            //Not allowed Element Type
            return nullptr;
        }
        return handler;
    }

    HandlerElement *Receiver::deleteHandler(HandlerElement *handler, const std::string &messageName)
    {
        std::list<HandlerElement *>::const_iterator it;
        for (it = handlerList.begin(); it != handlerList.end(); ++it)
        {
            if (*it == handler)
            {
                handlerList.erase(it);
                return handler;
            }
        }
        //Not found handler
        return nullptr;
    }

    HandlerElementType Receiver::getElementType() const
    {
        return HandlerElementType::RECEIVER;
    }
}
