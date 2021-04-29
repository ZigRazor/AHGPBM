#include "define_test_utilities.h"

TEST(AHGPBM, test_recv_route_disp_1)
{
    init_variable;

    dispatcher1.addHandler(&hand1, msg1.GetDescriptor()->name());
    router1.addHandler(&dispatcher1, msg1.GetDescriptor()->name());
    receiver1.addHandler(&router1);
    int *result;
    receiver1.receiveMessage(&msg1, (void **)&result);

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
    init_variable;

    dispatcher1.addHandler(&hand1, msg1.GetDescriptor()->name());
    receiver1.addHandler(&router1);
    int *result;
    receiver1.receiveMessage(&msg1, (void **)&result);

    ASSERT_EQ(result, nullptr);
}

TEST(AHGPBM, test_recv_route_disp_3)
{
    init_variable;

    router1.addHandler(&dispatcher1, msg1.GetDescriptor()->name());
    receiver1.addHandler(&router1);
    int *result;
    receiver1.receiveMessage(&msg1, (void **)&result);

    ASSERT_EQ(result, nullptr);
}

TEST(AHGPBM, test_recv_route_disp_4)
{
    init_variable;

    dispatcher1.addHandler(&hand1, msg1.GetDescriptor()->name());
    router1.addHandler(&dispatcher1, msg1.GetDescriptor()->name());

    int *result;
    receiver1.receiveMessage(&msg1, (void **)&result);

    ASSERT_EQ(result, nullptr);
}