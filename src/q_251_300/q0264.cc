#include <gtest/gtest.h>
#include <iostream>

using namespace std;

/**
 * This file is generated by leetcode_add.py v1.0
 *
 * 264.
 *      Ugly Number II
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   An “ugly number” is a positive integer whose prime factors are limited
 *   to ‘2’ , ‘3’ , and ‘5’
 *   Given an integer ‘n’ , return “the” ‘nᵗʰ’ “ “ugly number” ” .
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤ n ≤ 1690’
 *
 */

struct q264 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   public:
    int nthUglyNumber(int n) {
      vector<int> dp(n, 1);
      int fac2 = 0,
          fac3 = 0,
          fac5 = 0;
      for (int i = 1; i < n; ++i) {
        dp[i] = min({dp[fac2] * 2, dp[fac3] * 3, dp[fac5] * 5});
        if (dp[i] == dp[fac2] * 2) {
          ++fac2;
        }
        if (dp[i] == dp[fac3] * 3) {
          ++fac3;
        }
        if (dp[i] == dp[fac5] * 5) {
          ++fac5;
        }
      }
      return dp.back();
    }
  };

  class Solution *solution;
};

TEST_F(q264, sample_input01) {
  solution = new Solution();
  int n = 10;
  int exp = 12;
  EXPECT_EQ(solution->nthUglyNumber(n), exp);
  delete solution;
}

TEST_F(q264, sample_input02) {
  solution = new Solution();
  int n = 1;
  int exp = 1;
  EXPECT_EQ(solution->nthUglyNumber(n), exp);
  delete solution;
}