#include <gtest/gtest.h>
#include <iostream>
#include <vector>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 303.
 *      Range Sum Query - Immutable
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   Given an integer array ‘nums’ , handle multiple queries of the
 *   following
 *       1. Calculate the “sum” of the elements of ‘nums’ between indices
 *   ‘left’ and ‘right’ “inclusive” where ‘left ≤ right’
 *   Implement the ‘NumArray’
 *       -  ‘NumArray(int[] nums)’ Initializes the object with the integer
 *   array ‘nums’
 *       -  ‘int sumRange(int left, int right)’ Returns the “sum” of the
 *   elements of ‘nums’ between indices ‘left’ and ‘right’ “inclusive”
 *   (i.e. ‘nums[left] + nums[left + 1] + ... + nums[right]’ ).
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤ nums.length ≤ 10⁴’
 *   • ‘-10⁵ ≤ nums[i] ≤ 10⁵’
 *   • ‘0 ≤ left ≤ right < nums.length’
 *   • At most ‘10⁴’ calls will be made to ‘sumRange’ .
 *
 */

struct q303 : public ::testing::Test {
  // Leetcode answer here
  class NumArray {
   private:
    vector<int> sums;

   public:
    NumArray(vector<int>& nums) : sums(nums.size() + 1, 0) {
      for (int i = 0; i < nums.size(); ++i) {
        sums[i + 1] = nums[i] + sums[i];
      }
    }

    int sumRange(int left, int right) {
      return sums[right + 1] - sums[left];
    }
  };
  
  class NumArray *num_array;
};

TEST_F(q303, sample_input01) {
  vector<int> nums = {-2, 0, 3, -5, 2, -1};
  num_array = new NumArray(nums);
  EXPECT_EQ(num_array->sumRange(0, 2), 1);
  EXPECT_EQ(num_array->sumRange(2, 5), -1);
  EXPECT_EQ(num_array->sumRange(0, 5), -3);
  delete num_array;
}