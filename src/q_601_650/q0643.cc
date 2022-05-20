#include <gtest/gtest.h>
#include <iostream>
#include <vector>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 643.
 *      Maximum Average Subarray I
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   You are given an integer array ‘nums’ consisting of ‘n’ elements, and
 *   an integer ‘k’
 *   Find a contiguous subarray whose “length is equal to” ‘k’ that has the
 *   maximum average value and return “this value” . Any answer with a
 *   calculation error less than ‘10⁻⁵’ will be accepted.
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘n = nums.length’
 *   • ‘1 ≤ k ≤ n ≤ 10⁵’
 *   • ‘-10⁴ ≤ nums[i] ≤ 10⁴’
 *
 */

struct q643 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   public:
    double findMaxAverage(vector<int>& nums, int k) {
      vector<int> sum = nums;
      double res = 0;

      for (int i = 1; i < sum.size(); ++i) {
        sum[i] += sum[i - 1];
      }

      res = static_cast<double>(sum[k - 1]) / k;

      for (int i = k; i < sum.size(); ++i) {
        res = max(res, static_cast<double>(sum[i] - sum[i - k]) / k);
      }

      return res;
    }
  };

  class Solution *solution;
};

TEST_F(q643, sample_input01) {
  solution = new Solution();
  vector<int> nums = {1, 12, -5, -6, 50, 3};
  int k = 4;
  double exp = 12.75000;
  double act = solution->findMaxAverage(nums, k);
  EXPECT_DOUBLE_EQ(act, exp);
  delete solution;
}

TEST_F(q643, sample_input02) {
  solution = new Solution();
  vector<int> nums = {5};
  int k = 1;
  double exp = 5.00000;
  double act = solution->findMaxAverage(nums, k);
  EXPECT_DOUBLE_EQ(act, exp);
  delete solution;
}