#ifndef __HANDLER_H__
#define __HANDLER_H__

#include "google/protobuf/message.h"

class Handler{
    public:
    virtual void run() = 0;
};

#endif // __HANDLER_H__