#include <gtest/gtest.h>
#include <iostream>

using namespace std;

/**
 * This file is generated by leetcode_add.py v1.0
 *
 * 258.
 *      Add Digits
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   Given an integer ‘num’ , repeatedly add all its digits until the
 *   result has only one digit, and return it.
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘0 ≤ num ≤ 2³¹ - 1’
 *
 */

struct q258 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   public:
    int addDigits(int num) {
      return num == 0 ? 0 : 1 + (num - 1) % 9;
    }
  };

  class Solution *solution;
};

TEST_F(q258, sample_input01) {
  solution = new Solution();
  int num = 38;
  int exp = 2;
  EXPECT_EQ(solution->addDigits(num), exp);
  delete solution;
}

TEST_F(q258, sample_input02) {
  solution = new Solution();
  int num = 0;
  int exp = 0;
  EXPECT_EQ(solution->addDigits(num), exp);
  delete solution;
}