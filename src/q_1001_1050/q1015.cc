#include <gtest/gtest.h>
#include <iostream>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 1015.
 *       Smallest Integer Divisible by K
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   Given a positive integer ‘k’ , you need to find the “length” of the
 *   “smallest” positive integer ‘n’ such that ‘n’ is divisible by ‘k’ ,
 *   and ‘n’ only contains the digit ‘1’
 *   Return “the “length” of ” ‘n’ . If there is no such ‘n’ , return
 *    “Note:” ‘n’ may not fit in a 64-bit signed integer.
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤ k ≤ 10⁵’
 *
 */

struct q1015 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   public:
    int smallestRepunitDivByK(int k) {
      int res = 0;
      for (int i = 1; i <= k; ++i) {
        res = (res * 10 + 1) % k;
        if (res == 0) return i;
      }
      return -1;
    }
  };

  class Solution *solution;
};

TEST_F(q1015, sample_input01) {
  solution = new Solution();
  int k = 1;
  int exp = 1;
  int act = solution->smallestRepunitDivByK(k);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q1015, sample_input02) {
  solution = new Solution();
  int k = 2;
  int exp = -1;
  int act = solution->smallestRepunitDivByK(k);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q1015, sample_input03) {
  solution = new Solution();
  int k = 3;
  int exp = 3;
  int act = solution->smallestRepunitDivByK(k);
  EXPECT_EQ(act, exp);
  delete solution;
}