#ifndef __HANDLER_H__
#define __HANDLER_H__

#include "google/protobuf/message.h"

class Handler{
    public:
    virtual int run(google::protobuf::Message* msg) = 0;
};

#endif // __HANDLER_H__