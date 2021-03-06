#include <gtest/gtest.h>
#include <iostream>
#include <vector>

using namespace std;

/**
 * This file is generated by leetcode_add.py v1.0
 *
 * 448.
 *      Find All Numbers Disappeared in an Array
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   Given an array ‘nums’ of ‘n’ integers where ‘nums[i]’ is in the range
 *   ‘[1, n]’ , return “an array of all the integers in the range” ‘[1, n]’
 *   “that do not appear in” ‘nums’ .
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘n = nums.length’
 *   • ‘1 ≤ n ≤ 10⁵’
 *   • ‘1 ≤ nums[i] ≤ n’
 *
 */

struct q448 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
      vector<bool> appear(nums.size() + 1, false);
      for (const auto x : nums) appear[x] = true;
      vector<int> res;
      for (int i = 1; i < appear.size(); ++i) {
        if (!appear[i]) res.emplace_back(i);
      }
      return res;
    }
  };

  class Solution *solution;
};

TEST_F(q448, sample_input01) {
  solution = new Solution();
  vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
  vector<int> exp = {5, 6};
  EXPECT_EQ(solution->findDisappearedNumbers(nums), exp);
  delete solution;
}

TEST_F(q448, sample_input02) {
  solution = new Solution();
  vector<int> nums = {1, 1};
  vector<int> exp = {2};
  EXPECT_EQ(solution->findDisappearedNumbers(nums), exp);
  delete solution;
}