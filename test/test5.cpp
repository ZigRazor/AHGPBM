#include "define_test_utilities.h"

TEST(AHGPBM, test_net_costruct_1)
{
    init_variable;

    auto result0 = receiver1.addHandler(&router1)->addHandler(&dispatcher1, msg1.GetDescriptor()->name())->addHandler(&hand1, msg1.GetDescriptor()->name());

    ASSERT_NE(result0, nullptr);

    result0 = receiver1.addHandler(&router1)->addHandler(&dispatcher1, msg1.GetDescriptor()->name())->addHandler(&hand2, msg1.GetDescriptor()->name());

    ASSERT_NE(result0, nullptr);

    receiver1.receiveMessage(&msg1);
    auto result1 = hand1.getResult();
    auto result2 = hand2.getResult();

    ASSERT_EQ(result1, 1);
    ASSERT_EQ(result2, 2);
}


TEST(AHGPBM, test_net_costruct_2)
{
    init_variable;

    auto result0 = receiver1.addHandler(&router1)->addHandler(&dispatcher1, msg1.GetDescriptor()->name());

    ASSERT_NE(result0, nullptr);

    result0 = receiver1.addHandler(&router1)->addHandler(&dispatcher1, msg1.GetDescriptor()->name())->addHandler(&hand2, msg1.GetDescriptor()->name());
    
    ASSERT_NE(result0, nullptr);

    receiver1.receiveMessage(&msg1);
    auto result1 = hand1.getResult();
    auto result2 = hand2.getResult();

    ASSERT_EQ(result1, 0);
    ASSERT_EQ(result2, 2);
}

TEST(AHGPBM, test_net_costruct_3)
{
    init_variable;

    auto result0 = receiver1.addHandler(&router1)->addHandler(&dispatcher1, msg1.GetDescriptor()->name());

    ASSERT_NE(result0, nullptr);

    result0 = receiver1.addHandler(&router1)->addHandler(&dispatcher1, msg1.GetDescriptor()->name());
    
    ASSERT_NE(result0, nullptr);

    receiver1.receiveMessage(&msg1);
    auto result1 = hand1.getResult();
    auto result2 = hand2.getResult();

    ASSERT_EQ(result1, 0);
    ASSERT_EQ(result2, 0);
}


TEST(AHGPBM, test_net_costruct_4)
{
    init_variable;

    auto result0 = receiver1.addHandler(&router1)->addHandler(&dispatcher1, msg1.GetDescriptor()->name())->addHandler(&hand1);

    ASSERT_EQ(result0, nullptr);

    result0 = receiver1.addHandler(&router1)->addHandler(&dispatcher1, msg1.GetDescriptor()->name())->addHandler(&hand2, msg1.GetDescriptor()->name());

    ASSERT_NE(result0, nullptr);

    receiver1.receiveMessage(&msg1);
    auto result1 = hand1.getResult();
    auto result2 = hand2.getResult();

    ASSERT_EQ(result1, 0);
    ASSERT_EQ(result2, 2);
}

TEST(AHGPBM, test_net_costruct_5)
{
    init_variable;

    auto result0 = receiver1.addHandler(&router1)->addHandler(&dispatcher1);

    ASSERT_EQ(result0, nullptr);

    result0 = receiver1.addHandler(&router1)->addHandler(&dispatcher1, msg1.GetDescriptor()->name())->addHandler(&hand2, msg1.GetDescriptor()->name());

    ASSERT_NE(result0, nullptr);

    receiver1.receiveMessage(&msg1);
    auto result1 = hand1.getResult();
    auto result2 = hand2.getResult();

    ASSERT_EQ(result1, 0);
    ASSERT_EQ(result2, 2);
}

TEST(AHGPBM, test_net_costruct_6)
{
    init_variable;

    auto result0 = receiver1.addHandler(&router1, msg1.GetDescriptor()->name())->addHandler(&dispatcher1, msg1.GetDescriptor()->name())->addHandler(&hand1, msg1.GetDescriptor()->name());

    ASSERT_NE(result0, nullptr);

    result0 = receiver1.addHandler(&router1)->addHandler(&dispatcher1, msg1.GetDescriptor()->name())->addHandler(&hand2, msg1.GetDescriptor()->name());

    ASSERT_NE(result0, nullptr);

    receiver1.receiveMessage(&msg1);
    auto result1 = hand1.getResult();
    auto result2 = hand2.getResult();

    ASSERT_EQ(result1, 1);
    ASSERT_EQ(result2, 2);
}

TEST(AHGPBM, test_net_costruct_7)
{
    init_variable;

    auto result0 = receiver1.addHandler(&hand1);

    ASSERT_EQ(result0, nullptr);

    result0 = receiver1.addHandler(&router1)->addHandler(&dispatcher1, msg1.GetDescriptor()->name())->addHandler(&hand2, msg1.GetDescriptor()->name());

    ASSERT_NE(result0, nullptr);

    receiver1.receiveMessage(&msg1);
    auto result1 = hand1.getResult();
    auto result2 = hand2.getResult();

    ASSERT_EQ(result1, 0);
    ASSERT_EQ(result2, 2);
}

TEST(AHGPBM, test_net_costruct_8)
{
    init_variable;

    auto result0 = receiver1.addHandler(&router1)->addHandler(&hand1, msg1.GetDescriptor()->name());

    ASSERT_EQ(result0, nullptr);

    result0 = receiver1.addHandler(&router1)->addHandler(&dispatcher1, msg1.GetDescriptor()->name())->addHandler(&hand2, msg1.GetDescriptor()->name());

    ASSERT_NE(result0, nullptr);

    receiver1.receiveMessage(&msg1);
    auto result1 = hand1.getResult();
    auto result2 = hand2.getResult();

    ASSERT_EQ(result1, 0);
    ASSERT_EQ(result2, 2);
}

TEST(AHGPBM, test_net_costruct_9)
{
    init_variable;

    auto result0 = receiver1.addHandler(&dispatcher1)->addHandler(&hand1, msg1.GetDescriptor()->name());

    ASSERT_NE(result0, nullptr);

    result0 = receiver1.addHandler(&router1)->addHandler(&dispatcher1, msg1.GetDescriptor()->name())->addHandler(&hand2, msg1.GetDescriptor()->name());

    ASSERT_NE(result0, nullptr);

    receiver1.receiveMessage(&msg1);
    auto result1 = hand1.getResult();
    auto result2 = hand2.getResult();

    ASSERT_EQ(result1, 1);
    ASSERT_EQ(result2, 2);
}