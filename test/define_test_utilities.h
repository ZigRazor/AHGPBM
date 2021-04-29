#ifndef F1D3D0E2_CE3B_4B79_8749_968B3143BC5D
#define F1D3D0E2_CE3B_4B79_8749_968B3143BC5D


#include "gtest/gtest.h"
#include "receiver/Receiver.h"
#include "dispatcher/Dispatcher.h"
#include "handler/Handler.h"
#include "router/Router.h"
#include "proto/example.pb.h"
#include <iostream>
#include "handlerImpl.h"

#define init_variable \
    AHGPBM::Receiver receiver1; \
    AHGPBM::Router router1; \
    AHGPBM::Dispatcher dispatcher1; \
    AHGPBM::Dispatcher dispatcher2; \
    handler1 hand1; \
    handler2 hand2; \
    SearchRequest1 msg1; 

#endif /* F1D3D0E2_CE3B_4B79_8749_968B3143BC5D */
