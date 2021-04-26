#include "dispatcher/Dispatcher.h"
#include <future>

Dispatcher::Dispatcher(){

}
    
Dispatcher::~Dispatcher(){

}
    
void Dispatcher::injectMessage(google::protobuf::Message* msg){
    if(handlerMap.find(msg->GetDescriptor()->name()) != handlerMap.end()){
        std::list<Handler*> &handlerList = handlerMap.at(msg->GetDescriptor()->name());
        std::list<Handler*>::const_iterator it;
        for(it = handlerList.begin(); it != handlerList.end() ; ++it){
            auto asynch = std::async(std::launch::async, &Handler::run, &(*(*it)),msg);
        }
    }
}

void Dispatcher::addHandler(std::string messageName, Handler* handler){
    handlerMap[messageName].push_back(handler);
}
    
void Dispatcher::deleteHandler(std::string messageName, Handler* handler){
    if(handlerMap.find(messageName) != handlerMap.end()){
        std::list<Handler*> &handlerList = handlerMap.at(messageName);
        std::list<Handler*>::const_iterator handlerListIt;
        bool erased = false;
        for(handlerListIt = handlerList.begin(); !erased &&  handlerListIt != handlerList.end(); ++handlerListIt){
            if(*handlerListIt == handler){
                handlerList.erase(handlerListIt);
                erased = true;
            }
        }
    }
}
    
void Dispatcher::deleteHandlerMessage(std::string messageName){
    handlerMap.erase(handlerMap.find(messageName));
}