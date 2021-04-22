#include "receiver/Receiver.h"

Receiver::Receiver(){

}

Receiver::~Receiver(){

}

void Receiver::receiveMessage(google::protobuf::Message* msg){
    std::list<HandlerElement*>::const_iterator it;
    for(it = handlerList.begin(); it != handlerList.end() ; ++it){
        (*it)->injectMessage(msg);
    }
}

void Receiver::addHandler(HandlerElement* handler){
    handlerList.push_back(handler);
}

void Receiver::deleteHandler(HandlerElement* handler){
    std::list<HandlerElement*>::const_iterator it;
    bool erased = false;
    for(it = handlerList.begin(); !erased && it != handlerList.end() ; ++it){
        if(*it == handler){
            handlerList.erase(it);
            erased = true;
        }
    }
}
