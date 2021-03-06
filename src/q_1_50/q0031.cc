#include <gtest/gtest.h>
#include <iostream>
#include <vector>

using namespace std;

/**
 * This file is generated by leetcode_add.py v1.0
 *
 * 31.
 *     Next Permutation
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   Implement “next permutation” , which rearranges numbers into the
 *   lexicographically next greater permutation of
 *   If such an arrangement is not possible, it must rearrange it as the
 *   lowest possible order (i.e., sorted in ascending
 *   The replacement must be “<a
 *   href="http://en.wikipedia.org/wiki/In-place_algorithm"
 *   target="_blank">in place</a>” and use only constantextra memory.
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤ nums.length ≤ 100’
 *   • ‘0 ≤ nums[i] ≤ 100’
 *
 */

struct q31 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   public:
    void nextPermutation(vector<int>& nums) {
      bool permute = false;
      for (int i = nums.size() - 2; i > -1; i--) {
        if (nums[i] < nums[i + 1]) {
          int j = nums.size() - 1;
          while (j > i && nums[j] <= nums[i]) j--;
          swap(nums[i], nums[j]);
          reverse(nums.begin() + i + 1, nums.end());
          permute = true;
          break;
        }
      }
      if (!permute) reverse(nums.begin(), nums.end());
    }
  };

  class Solution *solution;
};

TEST_F(q31, sample_input01) {
  solution = new Solution();
  vector<int> nums = {1, 2, 3};
  vector<int> exp = {1, 3, 2};
  solution->nextPermutation(nums);
  // Assume the first argument is answer.
  EXPECT_EQ(nums, exp);
  delete solution;
}

TEST_F(q31, sample_input02) {
  solution = new Solution();
  vector<int> nums = {3, 2, 1};
  vector<int> exp = {1, 2, 3};
  solution->nextPermutation(nums);
  // Assume the first argument is answer.
  EXPECT_EQ(nums, exp);
  delete solution;
}

TEST_F(q31, sample_input03) {
  solution = new Solution();
  vector<int> nums = {1, 1, 5};
  vector<int> exp = {1, 5, 1};
  solution->nextPermutation(nums);
  // Assume the first argument is answer.
  EXPECT_EQ(nums, exp);
  delete solution;
}

TEST_F(q31, sample_input04) {
  solution = new Solution();
  vector<int> nums = {1};
  vector<int> exp = {1};
  solution->nextPermutation(nums);
  // Assume the first argument is answer.
  EXPECT_EQ(nums, exp);
  delete solution;
}