#include <gtest/gtest.h>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 219.
 *      Contains Duplicate II
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   Given an integer array ‘nums’ and an integer ‘k’ , return ‘true’ if
 *   there are two “distinct indices” ‘i’ and ‘j’ in the array such that
 *   ‘nums[i] = nums[j]’ and ‘abs(i - j) ≤ k’ .
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤ nums.length ≤ 10⁵’
 *   • ‘-10⁹ ≤ nums[i] ≤ 10⁹’
 *   • ‘0 ≤ k ≤ 10⁵’
 *
 */

struct q219 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   public:
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
      unordered_map<int, vector<int>> mp;
      for (int i = 0; i < nums.size(); ++i) {
        mp[nums[i]].emplace_back(i);
      }

      for (auto &[c, v] : mp) {
        if (v.size() > 1) {
          sort(v.begin(), v.end());

          for (int i = 1; i < v.size(); ++i) {
            if (abs(v[i - 1] - v[i]) <= k) {
              return true;
            }
          }
        }
      }

      return false;
    }
  };

  class Solution *solution;
};

TEST_F(q219, sample_input01) {
  solution = new Solution();
  vector<int> nums = {1, 2, 3, 1};
  int k = 3;
  bool exp = true;
  bool act = solution->containsNearbyDuplicate(nums, k);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q219, sample_input02) {
  solution = new Solution();
  vector<int> nums = {1, 0, 1, 1};
  int k = 1;
  bool exp = true;
  bool act = solution->containsNearbyDuplicate(nums, k);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q219, sample_input03) {
  solution = new Solution();
  vector<int> nums = {1, 2, 3, 1, 2, 3};
  int k = 2;
  bool exp = false;
  bool act = solution->containsNearbyDuplicate(nums, k);
  EXPECT_EQ(act, exp);
  delete solution;
}