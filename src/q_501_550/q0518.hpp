
#ifndef LEETCODE_Q518_H__
#define LEETCODE_Q518_H__
#include <iostream>
#include <vector>

namespace l518 {
using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 518.
 *      Coin Change 2
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   You are given an integer array ‘coins’ representing coins of different
 *   denominations and an integer ‘amount’ representing a total amount of
 *   Return “the number of combinations that make up that amount” . If that
 *   amount of money cannot be made up by any combination of the coins,
 *   return ‘0’
 *   You may assume that you have an infinite number of each kind of
 *   The answer is “guaranteed” to fit into a signed “32-bit” integer.
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤ coins.length ≤ 300’
 *   • ‘1 ≤ coins[i] ≤ 5000’
 *   • All the values of ‘coins’ are “unique” .
 *   • ‘0 ≤ amount ≤ 5000’
 *
 */

class Solution {
 public:
  int change(int amount, vector<int>& coins) {
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;
    for (const auto& c : coins) {
      for (int x = c; x < dp.size(); ++x) {
        dp[x] += dp[x - c];
      }
    }
    return dp.back();
  }
};
}  // namespace l518

#endif