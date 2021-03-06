#include <gtest/gtest.h>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 456.
 *      132 Pattern
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   Given an arrayof ‘n’ integers ‘nums’ , a “132 pattern” is a
 *   subsequence of three integers ‘nums[i]’ , ‘nums[j]’ and ‘nums[k]’ such
 *   that ‘i < j < k’ and ‘nums[i] < nums[k] < nums[j]’
 *   Return “ ‘true’ if there is a “132 pattern” in ‘nums’ , otherwise,
 *   return ‘false’ .” 
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘n = nums.length’
 *   • ‘1 ≤ n ≤ 2 × 10⁵’
 *   • ‘-10⁹ ≤ nums[i] ≤ 10⁹’
 *
 */

struct q456 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   public:
    bool find132pattern(vector<int>& nums) {
      int n = nums.size();
      vector<int> dp(n, 0);
      dp.front() = nums[0];
      for (int i = 1; i < nums.size(); ++i) {
        dp[i] = min(dp[i - 1], nums[i]);
      }

      set<int> memos;
      memos.insert(nums.back());
      for (int i = n - 2; i > 0; --i) {
        auto l = memos.begin(),
             r = --memos.end();

        if (*l < nums[i]) {
          if (*r < nums[i]) {
            if (dp[i - 1] < *r) {
              return true;
            }
          } else {
            auto find = --memos.lower_bound(nums[i]);
            if (*find > dp[i - 1]) {
              return true;
            }
          }
        }

        memos.insert(nums[i]);
      }

      return false;
    }
  };

  class Solution *solution;
};

TEST_F(q456, sample_input01) {
  solution = new Solution();
  vector<int> nums = {1, 2, 3, 4};
  bool exp = false;
  bool act = solution->find132pattern(nums);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q456, sample_input02) {
  solution = new Solution();
  vector<int> nums = {3, 1, 4, 2};
  bool exp = true;
  bool act = solution->find132pattern(nums);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q456, sample_input03) {
  solution = new Solution();
  vector<int> nums = {-1, 3, 2, 0};
  bool exp = true;
  bool act = solution->find132pattern(nums);
  EXPECT_EQ(act, exp);
  delete solution;
}