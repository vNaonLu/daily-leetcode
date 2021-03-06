#include <gtest/gtest.h>
#include <iostream>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 1344.
 *       Angle Between Hands of a Clock
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   Given two numbers, ‘hour’ and ‘minutes’ , return “the smaller angle
 *   (in degrees) formed between the ” ‘hour’ “ and the ” ‘minute’ “ hand”
 *   Answers within ‘10⁻⁵’ of the actual value will be accepted as correct.
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤ hour ≤ 12’
 *   • ‘0 ≤ minutes ≤ 59’
 *
 */

struct q1344 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   public:
    double angleClock(int hour, int minutes) {
      if (hour == 12) hour = 0;

      double hour_d = (hour * 30.) + (minutes / 2.),
             min_d = minutes * 6.;

      return hour_d > min_d
                 ? min(hour_d - min_d, 360 - hour_d + min_d)
                 : min(min_d - hour_d, 360 - min_d + hour_d);
    }
  };

  class Solution *solution;
};

TEST_F(q1344, sample_input01) {
  solution = new Solution();
  int hour = 12;
  int minutes = 30;
  double exp = 165;
  double act = solution->angleClock(hour, minutes);
  EXPECT_DOUBLE_EQ(act, exp);
  delete solution;
}

TEST_F(q1344, sample_input02) {
  solution = new Solution();
  int hour = 3;
  int minutes = 30;
  double exp = 75;
  double act = solution->angleClock(hour, minutes);
  EXPECT_DOUBLE_EQ(act, exp);
  delete solution;
}

TEST_F(q1344, sample_input03) {
  solution = new Solution();
  int hour = 3;
  int minutes = 15;
  double exp = 7.5;
  double act = solution->angleClock(hour, minutes);
  EXPECT_DOUBLE_EQ(act, exp);
  delete solution;
}