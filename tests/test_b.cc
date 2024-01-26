#ifndef C70132D3_1396_4CCD_A37B_54145CBF2BDE
#define C70132D3_1396_4CCD_A37B_54145CBF2BDE

#include <gtest/gtest.h>
#include "../modules/module_b/test_fun_b.h"

using namespace std;

TEST(TestGroupNameB, Subtest_1) {
  ASSERT_FALSE('b' == 'b');
  cout << "continue test after failure" << endl;
}

TEST(TestGroupNameB, Subtest_2) {
  // EXPECT_EQ(mult_test(2, 3), 6);
  EXPECT_EQ((2*3), 7);
}

#endif /* C70132D3_1396_4CCD_A37B_54145CBF2BDE */
