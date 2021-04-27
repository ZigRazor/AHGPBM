#ifndef __RECEIVER_H__
#define __RECEIVER_H__

#include "google/protobuf/message.h"
#include "base/HandlerElement.h"
#include <list>

namespace AHGPBM
{
    class Receiver
    {
    public:
        Receiver();
        ~Receiver();
        void receiveMessage(google::protobuf::Message *msg);

        void addHandler(HandlerElement *handler);
        void deleteHandler(HandlerElement *handler);

    private:
        std::list<HandlerElement *> handlerList;
    };
}

#endif // __RECEIVER_H__