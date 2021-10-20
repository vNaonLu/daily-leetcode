
#ifndef LEETCODE_Q264_H__
#define LEETCODE_Q264_H__
#include <iostream>
#include <vector>

namespace l264 {
using namespace std;

/**
 * This file is generated by leetcode_add.py
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
}  // namespace l264

#endif