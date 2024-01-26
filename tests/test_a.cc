#ifndef DC2A0D02_F411_4E08_BB42_3D771DDE9E62
#define DC2A0D02_F411_4E08_BB42_3D771DDE9E62

#include <gtest/gtest.h>
#include "../modules/module_a/test_fun_a.h"

using namespace std;

TEST(TestGroupNameA, Subtest_1) {
  ASSERT_TRUE(1 == 1);
}

TEST(TestGroupNameA, Subtest_2) {
  // EXPECT_EQ(sum_test(2, 3), 5);
  EXPECT_EQ((2+3), 5);
}

#endif /* DC2A0D02_F411_4E08_BB42_3D771DDE9E62 */
