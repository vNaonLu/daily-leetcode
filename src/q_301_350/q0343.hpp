
#ifndef LEETCODE_Q343_H__
#define LEETCODE_Q343_H__
#include <iostream>

namespace l343 {
using namespace std;

/**
  * This file is generated by leetcode_add.py
  *
  * 343.
  *      Integer Break
  *
  * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
  *
  *   Given an integer ‘n’ , break it into the sum of ‘k’ “positive
  *   integers” , where ‘k ≥ 2’ , and maximize the product of those integers.
  *   
  *   Return “the maximum product you can get”.
  *
  * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
  *
  *   • ‘2 ≤ n ≤ 58’
  *
*/

class Solution {
 public:
  int integerBreak(int n) {
    vector<int> dp = {0, 1, 1, 2, 4, 6, 9, 12};
    if (dp.size() > n) return dp[n];
    int sz = dp.size();
    dp.resize(n + 1, 0);
    for (int i = sz; i <= n; ++i)
      for (int j = i - 2; j >= 2; --j)
        dp[i] = max(dp[i], j * dp[i - j]);
    return dp[n];
  }
};
}  // namespace l343

#endif