
#include "gtest/gtest.h"
#include "receiver/Receiver.h"
#include "dispatcher/Dispatcher.h"
#include "handler/Handler.h"
#include "proto/example.pb.h"
#include <iostream>
#include "handlerImpl.h"



TEST(AHGPBM, test_recv_disp_1)
{
    AHGPBM::Receiver receiver;
    AHGPBM::Dispatcher dispatcher;
    handler1 hand;

    SearchRequest1 msg;

    dispatcher.addHandler(&hand, msg.GetDescriptor()->name());
    receiver.addHandler(&dispatcher);
    int *result;
    receiver.injectMessage(&msg, (void **)&result);

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

TEST(AHGPBM, test_recv_disp_2)
{
    AHGPBM::Receiver receiver;
    AHGPBM::Dispatcher dispatcher;

    SearchRequest1 msg;

    receiver.addHandler(&dispatcher);
    int *result;
    receiver.injectMessage(&msg, (void **)&result);

    ASSERT_EQ(result, nullptr);
}

TEST(AHGPBM, test_recv_disp_3)
{
    AHGPBM::Receiver receiver;

    SearchRequest1 msg;

    int *result;
    receiver.injectMessage(&msg, (void **)&result);

    ASSERT_EQ(result, nullptr);
}
