#include "handler/Handler.h"
#include <future>

namespace AHGPBM
{
    void Handler::injectMessage(google::protobuf::Message *msg)
    {
        auto asynch = std::async(std::launch::async, &Handler::run, this, msg);
    }
    void Handler::injectMessage(google::protobuf::Message *msg, void **result)
    {
        auto asynch = std::async(std::launch::async, &Handler::run, this, msg);
        *result = asynch.get();
    }
    HandlerElementType Handler::getElementType() const
    {
        return HandlerElementType::HANDLER;
    }
    HandlerElement *Handler::addHandler(HandlerElement *handler, const std::string &messageName)
    {
        //Operation Not allowed
        return nullptr;
    }
    HandlerElement *Handler::deleteHandler(HandlerElement *handler, const std::string &messageName)
    {
        //Operation Not allowed
        return nullptr;
    }

}