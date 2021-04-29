#include "define_test_utilities.h"

TEST(AHGPBM, test_recv_route_disp_mult_hand_1)
{
    init_variable;

    dispatcher1.addHandler(&hand1, msg1.GetDescriptor()->name());
    dispatcher1.addHandler(&hand2, msg1.GetDescriptor()->name());
    router1.addHandler(&dispatcher1, msg1.GetDescriptor()->name());
    receiver1.addHandler(&router1);

    receiver1.receiveMessage(&msg1);
    auto result1 = hand1.getResult();
    auto result2 = hand2.getResult();

    ASSERT_EQ(result1, 1);
    ASSERT_EQ(result2, 2);
}

TEST(AHGPBM, test_recv_route_disp_mult_hand_2)
{
    init_variable;

    dispatcher1.addHandler(&hand1, msg1.GetDescriptor()->name());
    router1.addHandler(&dispatcher1, msg1.GetDescriptor()->name());
    receiver1.addHandler(&router1);

    receiver1.receiveMessage(&msg1);
    auto result1 = hand1.getResult();
    auto result2 = hand2.getResult();

    ASSERT_EQ(result1, 1);
    ASSERT_EQ(result2, 0);
}

TEST(AHGPBM, test_recv_route_disp_mult_hand_3)
{
    init_variable;

    dispatcher1.addHandler(&hand2, msg1.GetDescriptor()->name());

    router1.addHandler(&dispatcher1, msg1.GetDescriptor()->name());
    receiver1.addHandler(&router1);

    receiver1.receiveMessage(&msg1);
    auto result1 = hand1.getResult();
    auto result2 = hand2.getResult();

    ASSERT_EQ(result1, 0);
    ASSERT_EQ(result2, 2);
}

TEST(AHGPBM, test_recv_route_disp_mult_hand_4)
{
    init_variable;

    dispatcher1.addHandler(&hand1, msg1.GetDescriptor()->name());
    dispatcher1.addHandler(&hand2, msg1.GetDescriptor()->name());
    router1.addHandler(&dispatcher1, msg1.GetDescriptor()->name());

    receiver1.receiveMessage(&msg1);
    auto result1 = hand1.getResult();
    auto result2 = hand2.getResult();

    ASSERT_EQ(result1, 0);
    ASSERT_EQ(result2, 0);
}

TEST(AHGPBM, test_recv_route_disp_mult_hand_5)
{
    init_variable;

    dispatcher1.addHandler(&hand1, msg1.GetDescriptor()->name());
    dispatcher1.addHandler(&hand2, msg1.GetDescriptor()->name());

    receiver1.addHandler(&router1);

    receiver1.receiveMessage(&msg1);
    auto result1 = hand1.getResult();
    auto result2 = hand2.getResult();

    ASSERT_EQ(result1, 0);
    ASSERT_EQ(result2, 0);
}

TEST(AHGPBM, test_recv_route_disp_mult_hand_6)
{
    init_variable;

    router1.addHandler(&dispatcher1, msg1.GetDescriptor()->name());
    receiver1.addHandler(&router1);

    receiver1.receiveMessage(&msg1);
    auto result1 = hand1.getResult();
    auto result2 = hand2.getResult();

    ASSERT_EQ(result1, 0);
    ASSERT_EQ(result2, 0);
}