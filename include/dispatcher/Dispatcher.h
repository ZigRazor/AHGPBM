#ifndef __DISPATCHER_H__
#define __DISPATCHER_H__

#include "base/HandlerElement.h"
#include "base/Handler.h"
#include <map>
#include <list>

class Dispatcher : public HandlerElement{
    public:
    Dispatcher();
    ~Dispatcher();
    void injectMessage(google::protobuf::Message* msg);
    void addHandler(std::string messageName, Handler* handler);
    void deleteHandler(std::string messageName, Handler* handler);
    void deleteHandlerMessage(std::string messageName);
    private:
    std::map<std::string, std::list<Handler*>> handlerMap;

};

#endif // __DISPATCHER_H__