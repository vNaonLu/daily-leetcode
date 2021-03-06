#include <gtest/gtest.h>
#include <iostream>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 2180.
 *       Count Integers With Even Digit Sum
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   Given a positive integer ‘num’ , return “the number of positive
 *   integers “less than or equal to” ” ‘num’ “whose digit sums are “even”
 *   ”
 *   The “digit sum” of a positive integer is the sum of all its digits.
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤ num ≤ 1000’
 *
 */

struct q2180 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   public:
    int countEven(int num) {
      int adjust = (num / 1000 + num % 1000 / 100 + num % 100 / 10 + num % 10) % 2;
      return (num - adjust) / 2;
    }
  };

  class Solution *solution;
};

TEST_F(q2180, sample_input01) {
  solution = new Solution();
  int num = 4;
  int exp = 2;
  int act = solution->countEven(num);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q2180, sample_input02) {
  solution = new Solution();
  int num = 30;
  int exp = 14;
  int act = solution->countEven(num);
  EXPECT_EQ(act, exp);
  delete solution;
}