#include <gtest/gtest.h>
#include <iostream>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 1680.
 *       Concatenation of Consecutive Binary Numbers
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   Given an integer ‘n’ , return “the “decimal value” of the binary
 *   string formed by concatenating the binary representations of ” ‘1’ “
 *   to ” ‘n’ “ in order, “modulo ” ” ‘10^(9 )+ 7’ .
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤ n ≤ 10⁵’
 *
 */

struct q1680 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   private:
    inline constexpr static int kMod = 1e9 + 7;

   public:
    int concatenatedBinary(int n) {
      unsigned long long res = 0;
      for (int i = 1; i <= n; ++i) {
        int j = i,
            cnt = 0;
        while (j != 0) {
          j >>= 1;
          ++cnt;
        }
        res <<= cnt;
        res %= kMod;
        res += i;
        res %= kMod;
      }
      return (int)res;
    }
  };

  class Solution *solution;
};

TEST_F(q1680, sample_input01) {
  solution = new Solution();
  int n = 1;
  int exp = 1;
  int act = solution->concatenatedBinary(n);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q1680, sample_input02) {
  solution = new Solution();
  int n = 3;
  int exp = 27;
  int act = solution->concatenatedBinary(n);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q1680, sample_input03) {
  solution = new Solution();
  int n = 12;
  int exp = 505379714;
  int act = solution->concatenatedBinary(n);
  EXPECT_EQ(act, exp);
  delete solution;
}