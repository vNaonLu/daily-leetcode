#include <gtest/gtest.h>
#include <iostream>

using namespace std;

/**
 * This file is generated by leetcode_add.py v1.0
 *
 * 1137.
 *       N-th Tribonacci Number
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   The Tribonacci sequence Tₙ is defined as
 *   T₀ = 0, T₁ = 1, T₂ = 1, and Tₙ₊₃ = Tₙ + Tₙ₊₁ + Tₙ₊₂ for n ≥
 *   Given ‘n’ , return the value of
 *   
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘0 ≤ n ≤ 37’
 *   • The answer is guaranteed to fit within a 32-bit integer, ie. ‘answer ≤ 2^31 - 1’ .
 *
 */

struct q1137 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   public:
    int tribonacci(int n) {
      vector<int> res(n + 1, 1);
      res[0] = 0;
      for (int i = 3; i <= n; ++i)
        res[i] = res[i - 1] + res[i - 2] + res[i - 3];
      return res.back();
    }
  };

  class Solution *solution;
};

TEST_F(q1137, sample_input01) {
  solution = new Solution();
  int n = 4;
  int exp = 4;
  EXPECT_EQ(solution->tribonacci(n), exp);
  delete solution;
}

TEST_F(q1137, sample_input02) {
  solution = new Solution();
  int n = 25;
  int exp = 1389537;
  EXPECT_EQ(solution->tribonacci(n), exp);
  delete solution;
}