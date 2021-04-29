#include "gtest/gtest.h"
#include "receiver/Receiver.h"
#include "dispatcher/Dispatcher.h"
#include "handler/Handler.h"
#include "router/Router.h"
#include "proto/example.pb.h"
#include <iostream>
#include "handlerImpl.h"


TEST(AHGPBM, test_recv_route_disp_1)
{
    AHGPBM::Receiver receiver;
    AHGPBM::Router router;
    AHGPBM::Dispatcher dispatcher;
    handler1 hand;

    SearchRequest1 msg;

    dispatcher.addHandler(&hand, msg.GetDescriptor()->name());
    router.addHandler(&dispatcher, msg.GetDescriptor()->name());
    receiver.addHandler(&router);
    int *result;
    receiver.receiveMessage(&msg, (void **)&result);

    if (result)
    {
        ASSERT_EQ(*result, 1);
    }
    else
    {
        //force error
        ASSERT_EQ(0, 1);
    }
}

TEST(AHGPBM, test_recv_route_disp_2)
{
    AHGPBM::Receiver receiver;
    AHGPBM::Router router;
    AHGPBM::Dispatcher dispatcher;
    handler1 hand;

    SearchRequest1 msg;

    dispatcher.addHandler(&hand, msg.GetDescriptor()->name());
    receiver.addHandler(&router);
    int *result;
    receiver.receiveMessage(&msg, (void **)&result);

    ASSERT_EQ(result, nullptr);
}

TEST(AHGPBM, test_recv_route_disp_3)
{
    AHGPBM::Receiver receiver;
    AHGPBM::Router router;
    AHGPBM::Dispatcher dispatcher;
    handler1 hand;

    SearchRequest1 msg;

    router.addHandler(&dispatcher, msg.GetDescriptor()->name());
    receiver.addHandler(&router);
    int *result;
    receiver.receiveMessage(&msg, (void **)&result);

    ASSERT_EQ(result, nullptr);
}

TEST(AHGPBM, test_recv_route_disp_4)
{
    AHGPBM::Receiver receiver;
    AHGPBM::Router router;
    AHGPBM::Dispatcher dispatcher;
    handler1 hand;

    SearchRequest1 msg;

    dispatcher.addHandler(&hand, msg.GetDescriptor()->name());
    router.addHandler(&dispatcher, msg.GetDescriptor()->name());

    int *result;
    receiver.receiveMessage(&msg, (void **)&result);

    ASSERT_EQ(result, nullptr);
}