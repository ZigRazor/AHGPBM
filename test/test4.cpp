#include "gtest/gtest.h"
#include "receiver/Receiver.h"
#include "dispatcher/Dispatcher.h"
#include "handler/Handler.h"
#include "router/Router.h"
#include "proto/example.pb.h"
#include <iostream>

class handler1 : public AHGPBM::Handler
{
public:
    handler1() : result(0) {}

    void *run(google::protobuf::Message *msg)
    {
        //std::cout << "Handled " << msg->GetDescriptor()->name() << std::endl;
        result = 1;
        int *result_to_return = new int(result);
        return result_to_return;
    }

    int getResult()
    {
        return result;
    }

private:
    int result;
};

class handler2 : public AHGPBM::Handler
{
public:
    handler2() : result(0) {}

    void *run(google::protobuf::Message *msg)
    {
        //std::cout << "Handled " << msg->GetDescriptor()->name() << std::endl;
        result = 2;
        int *result_to_return = new int(result);
        return result_to_return;
    }

    int getResult()
    {
        return result;
    }

private:
    int result;
};

TEST(AHGPBM, test_recv_route_disp_mult_hand_1)
{
    AHGPBM::Receiver receiver;
    AHGPBM::Router router;
    AHGPBM::Dispatcher dispatcher1;
    handler1 hand1;
    handler2 hand2;

    SearchRequest1 msg;

    dispatcher1.addHandler(&hand1, msg.GetDescriptor()->name());
    dispatcher1.addHandler(&hand2, msg.GetDescriptor()->name());
    router.addHandler(&dispatcher1, msg.GetDescriptor()->name());
    receiver.addHandler(&router);

    receiver.injectMessage(&msg);
    auto result1 = hand1.getResult();
    auto result2 = hand2.getResult();

    ASSERT_EQ(result1, 1);
    ASSERT_EQ(result2, 2);
}

TEST(AHGPBM, test_recv_route_disp_mult_hand_2)
{
    AHGPBM::Receiver receiver;
    AHGPBM::Router router;
    AHGPBM::Dispatcher dispatcher1;
    handler1 hand1;
    handler2 hand2;

    SearchRequest1 msg;

    dispatcher1.addHandler(&hand1, msg.GetDescriptor()->name());
    router.addHandler(&dispatcher1, msg.GetDescriptor()->name());
    receiver.addHandler(&router);

    receiver.injectMessage(&msg);
    auto result1 = hand1.getResult();
    auto result2 = hand2.getResult();

    ASSERT_EQ(result1, 1);
    ASSERT_EQ(result2, 0);
}

TEST(AHGPBM, test_recv_route_disp_mult_hand_3)
{
    AHGPBM::Receiver receiver;
    AHGPBM::Router router;
    AHGPBM::Dispatcher dispatcher1;
    handler1 hand1;
    handler2 hand2;

    SearchRequest1 msg;

    dispatcher1.addHandler(&hand2, msg.GetDescriptor()->name());

    router.addHandler(&dispatcher1, msg.GetDescriptor()->name());
    receiver.addHandler(&router);

    receiver.injectMessage(&msg);
    auto result1 = hand1.getResult();
    auto result2 = hand2.getResult();

    ASSERT_EQ(result1, 0);
    ASSERT_EQ(result2, 2);
}

TEST(AHGPBM, test_recv_route_disp_mult_hand_4)
{
    AHGPBM::Receiver receiver;
    AHGPBM::Router router;
    AHGPBM::Dispatcher dispatcher1;
    handler1 hand1;
    handler2 hand2;

    SearchRequest1 msg;

    dispatcher1.addHandler(&hand1, msg.GetDescriptor()->name());
    dispatcher1.addHandler(&hand2, msg.GetDescriptor()->name());
    router.addHandler(&dispatcher1, msg.GetDescriptor()->name());

    receiver.injectMessage(&msg);
    auto result1 = hand1.getResult();
    auto result2 = hand2.getResult();

    ASSERT_EQ(result1, 0);
    ASSERT_EQ(result2, 0);
}

TEST(AHGPBM, test_recv_route_disp_mult_hand_5)
{
    AHGPBM::Receiver receiver;
    AHGPBM::Router router;
    AHGPBM::Dispatcher dispatcher1;
    handler1 hand1;
    handler2 hand2;

    SearchRequest1 msg;

    dispatcher1.addHandler(&hand1, msg.GetDescriptor()->name());
    dispatcher1.addHandler(&hand2, msg.GetDescriptor()->name());

    receiver.addHandler(&router);

    receiver.injectMessage(&msg);
    auto result1 = hand1.getResult();
    auto result2 = hand2.getResult();

    ASSERT_EQ(result1, 0);
    ASSERT_EQ(result2, 0);
}

TEST(AHGPBM, test_recv_route_disp_mult_hand_6)
{
    AHGPBM::Receiver receiver;
    AHGPBM::Router router;
    AHGPBM::Dispatcher dispatcher1;
    handler1 hand1;
    handler2 hand2;

    SearchRequest1 msg;

    router.addHandler(&dispatcher1, msg.GetDescriptor()->name());
    receiver.addHandler(&router);

    receiver.injectMessage(&msg);
    auto result1 = hand1.getResult();
    auto result2 = hand2.getResult();

    ASSERT_EQ(result1, 0);
    ASSERT_EQ(result2, 0);
}