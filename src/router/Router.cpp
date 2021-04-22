#include "router/Router.h"

Router::Router(){

}

Router::~Router(){

}
    
void Router::injectMessage(google::protobuf::Message* msg){
    if(routingMap.find(msg->GetDescriptor()->name()) != routingMap.end()){
        std::list<HandlerElement*> &handlerList = routingMap.at(msg->GetDescriptor()->name());
        std::list<HandlerElement*>::const_iterator it;
        for(it = handlerList.begin(); it != handlerList.end() ; ++it){
            (*it)->injectMessage(msg);
        }
    }
}
    
void Router::addRoutingElement(std::string messageName, HandlerElement* routingElement){
    routingMap[messageName].push_back(routingElement);
}
    
void Router::deleteRoutingElement(std::string messageName, HandlerElement* routingElement){
    if(routingMap.find(messageName) != routingMap.end()){
        std::list<HandlerElement*> &handlerList = routingMap.at(messageName);
        std::list<HandlerElement*>::const_iterator handlerListIt;
        bool erased = false;
        for(handlerListIt = handlerList.begin(); !erased &&  handlerListIt != handlerList.end(); ++handlerListIt){
            if(*handlerListIt == routingElement){
                handlerList.erase(handlerListIt);
                erased = true;
            }
        }
    }
}
    
void Router::deleteRoutingMessage(std::string messageName){
    routingMap.erase(routingMap.find(messageName));
}