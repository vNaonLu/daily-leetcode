#include <gtest/gtest.h>
#include <iostream>
#include <vector>

using namespace std;

/**
 * This file is generated by leetcode_add.py v1.0
 *
 * 377.
 *      Combination Sum IV
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   Given an array of “distinct” integers ‘nums’ and a target integer
 *   ‘target’ , return “the number of possible combinations that add up to”
 *    ‘target’
 *   The test cases are generated so that the answer can fit in a “32-bit”
 *   integer.
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤ nums.length ≤ 200’
 *   • ‘1 ≤ nums[i] ≤ 1000’
 *   • All the elements of ‘nums’ are “unique” .
 *   • ‘1 ≤ target ≤ 1000’
 *
 */

struct q377 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   private:
    vector<int> dp;
    bool init = false;
   public:
    int combinationSum4(vector<int>& nums, int target) {
      if (!init) {
        init = true;
        dp.resize(1001, -1);
        dp[0] = 1;
      }
      if (target < 0) return 0;
      if (dp[target] != -1) return dp[target];
      dp[target] = 0;
      for (const int& c : nums) {
        dp[target] += combinationSum4(nums, target - c);
      }
      return dp[target];
    }
  };

  class Solution *solution;
};

TEST_F(q377, sample_input01) {
  solution = new Solution();
  vector<int> nums = {1, 2, 3};
  int target = 4;
  int exp = 7;
  EXPECT_EQ(solution->combinationSum4(nums, target), exp);
  delete solution;
}

TEST_F(q377, sample_input02) {
  solution = new Solution();
  vector<int> nums = {9};
  int target = 3;
  int exp = 0;
  EXPECT_EQ(solution->combinationSum4(nums, target), exp);
  delete solution;
}