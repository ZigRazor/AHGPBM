
#include "gtest/gtest.h"
#include "receiver/Receiver.h"
#include "dispatcher/Dispatcher.h"
#include "proto/example.pb.h"

TEST(AHGPBM, test1) { 
    EXPECT_EQ (18.0, 18.0);
    EXPECT_EQ (25.4, 25.4);
}

TEST (AHGPBM, test2) { 
    ASSERT_EQ (0.0, 0.0);
    ASSERT_EQ (-1, -1);
}
