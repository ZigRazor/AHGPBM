
#include "gtest/gtest.h"
#include "receiver/Receiver.h"
#include "dispatcher/Dispatcher.h"
#include "base/Handler.h"
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

TEST(AHGPBM, test1)
{
    AHGPBM::Receiver receiver;
    AHGPBM::Dispatcher dispatcher;
    handler1 hand;

    SearchRequest1 msg;

    dispatcher.addHandler(msg.GetDescriptor()->name(), &hand);
    receiver.addHandler(&dispatcher);
    int *result;
    receiver.receiveMessage(&msg, (void **)&result);

    if(result){
    ASSERT_EQ(*result, 1);
    }else{
        //force error
        ASSERT_EQ(0, 1);
    }
}

TEST(AHGPBM, test2)
{
    AHGPBM::Receiver receiver;
    AHGPBM::Dispatcher dispatcher;
    
    SearchRequest1 msg;
    
    receiver.addHandler(&dispatcher);
    int *result;
    receiver.receiveMessage(&msg, (void **)&result);

    
    ASSERT_EQ(result, nullptr);
}

TEST(AHGPBM, test3)
{
    AHGPBM::Receiver receiver;

    SearchRequest1 msg;

    int *result;
    receiver.receiveMessage(&msg, (void **)&result);

    
    ASSERT_EQ(result, nullptr);
}
