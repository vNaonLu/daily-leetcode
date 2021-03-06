#include <gtest/gtest.h>
#include <iostream>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 1688.
 *       Count of Matches in Tournament
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   You are given an integer ‘n’ , the number of teams in a tournament
 *   that has strange
 *       - If the current number of teams is “even” , each team gets paired
 *   with another team. A total of ‘n / 2’ matches are played, and ‘n / 2’
 *   teams advance to the next
 *       - If the current number of teams is “odd” , one team randomly
 *   advances in the tournament, and the rest gets paired. A total of ‘(n -
 *   1) / 2’ matches are played, and ‘(n - 1) / 2 + 1’ teams advance to the
 *   next
 *   Return “the number of matches played in the tournament until a winner
 *   is decided.” 
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤ n ≤ 200’
 *
 */

struct q1688 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   public:
    int numberOfMatches(int n) {
      int res = 0;

      while (n != 1) {
        auto x = n >> 1;
        res += x;
        n -= x;
      }

      return res;
    }
  };

  class Solution *solution;
};

TEST_F(q1688, sample_input01) {
  solution = new Solution();
  int n = 7;
  int exp = 6;
  int act = solution->numberOfMatches(n);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q1688, sample_input02) {
  solution = new Solution();
  int n = 14;
  int exp = 13;
  int act = solution->numberOfMatches(n);
  EXPECT_EQ(act, exp);
  delete solution;
}