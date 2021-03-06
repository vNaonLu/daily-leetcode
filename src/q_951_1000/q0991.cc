#include <gtest/gtest.h>
#include <iostream>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 991.
 *      Broken Calculator
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   There is a broken calculator that has the integer ‘startValue’ on its
 *   display initially. In one operation, you
 *       - multiply the number on display by ‘2’ ,
 *       - subtract ‘1’ from the number on
 *   Given two integers ‘startValue’ and ‘target’ , return “the minimum
 *   number of operations needed to display ” ‘target’ “ on the calculator”
 *   .
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤ x, y ≤ 10⁹’
 *
 */

struct q991 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   public:
    int brokenCalc(int startValue, int target) {
      int res = 0;

      while (target > startValue) {
        ++res;

        if (target % 2) {
          ++target;
        } else {
          target >>= 1;
        }
      }

      return res + startValue - target;
    }
  };

  class Solution *solution;
};

TEST_F(q991, sample_input01) {
  solution = new Solution();
  int startValue = 2;
  int target = 3;
  int exp = 2;
  int act = solution->brokenCalc(startValue, target);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q991, sample_input02) {
  solution = new Solution();
  int startValue = 5;
  int target = 8;
  int exp = 2;
  int act = solution->brokenCalc(startValue, target);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q991, sample_input03) {
  solution = new Solution();
  int startValue = 3;
  int target = 10;
  int exp = 3;
  int act = solution->brokenCalc(startValue, target);
  EXPECT_EQ(act, exp);
  delete solution;
}