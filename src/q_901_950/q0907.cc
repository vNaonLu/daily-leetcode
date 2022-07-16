#include <gtest/gtest.h>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 907.
 *      Sum of Subarray Minimums
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   Given an array of integers arr, find the sum of ‘min(b)’ , where ‘b’
 *   ranges over every (contiguous) subarray of ‘arr’ . Since the answer
 *   may be large, return the answer “modulo” ‘10⁹ + 7’ .
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤ arr.length ≤ 3 × 10⁴’
 *   • ‘1 ≤ arr[i] ≤ 3 × 10⁴’
 *
 */

struct q907 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   private:
    inline constexpr static int kMod = 1e9 + 7;

   public:
    int sumSubarrayMins(vector<int>& arr) {
      long long             res = 0;
      stack<pair<int, int>> stk;
      vector<long long>     dp(arr.size() + 2, 0);
      for (int i = arr.size() - 1; i >= 0; --i) {
        int right;
        while (stk.empty() == false && stk.top().first > arr[i]) {
          stk.pop();
        }

        if (stk.empty() == true) {
          right = arr.size();
        } else {
          right = stk.top().second;
        }

        dp[i] = ((arr[i] % kMod * (right - i) % kMod) % kMod + dp[right] % kMod) % kMod;
        res = (res % kMod + dp[i] % kMod) % kMod;
        stk.emplace(arr[i], i);
      }
      return res;
    }
  };

  class Solution *solution;
};

TEST_F(q907, sample_input01) {
  solution = new Solution();
  vector<int> arr = {3, 1, 2, 4};
  int exp = 17;
  int act = solution->sumSubarrayMins(arr);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q907, sample_input02) {
  solution = new Solution();
  vector<int> arr = {11, 81, 94, 43, 3};
  int exp = 444;
  int act = solution->sumSubarrayMins(arr);
  EXPECT_EQ(act, exp);
  delete solution;
}