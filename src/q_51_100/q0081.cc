#include <gtest/gtest.h>
#include <iostream>
#include <vector>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 81.
 *     Search in Rotated Sorted Array II
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   There is an integer array ‘nums’ sorted in non-decreasing order (not
 *   necessarily with “distinct”
 *   Before being passed to your function, ‘nums’ is “rotated” at an
 *   unknown pivot index ‘k’ ( ‘0 ≤ k < nums.length’ ) such that the
 *   resulting array is ‘[nums[k], nums[k+1], ..., nums[n-1], nums[0],
 *   nums[1], ..., nums[k-1]]’ ( “0-indexed” ). For example,
 *   ‘[0,1,2,4,4,4,5,6,6,7]’ might be rotated at pivot index ‘5’ and become
 *   ‘[4,5,6,6,7,0,1,2,4,4]’
 *   Given the array ‘nums’ “after” the rotation and an integer ‘target’ ,
 *   return ‘true’ “ if ” ‘target’ “ is in ” ‘nums’ “, or ” ‘false’ “ if it
 *   is not in ” ‘nums’ “.”
 *   You must decrease the overall operation steps as much as possible.
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤ nums.length ≤ 5000’
 *   • ‘-10⁴ ≤ nums[i] ≤ 10⁴’
 *   • ‘nums’ is guaranteed to be rotated at some pivot.
 *   • ‘-10⁴ ≤ target ≤ 10⁴’
 *
 */

struct q81 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   public:
    bool search(vector<int>& nums, int target) {
      int n = nums.size();
      if (n == 0) return false;
      int l = 0, r = n - 1;

      while (l <= r) {
        int mid = l + (r - l) / 2;

        if (nums[mid] == target) {
          return true;
        }

        if (nums[l] == nums[mid]) {
          ++l;
          continue;
        }

        bool pivot = nums[l] <= nums[mid],
             tar = nums[l] <= target;

        if (pivot ^ tar) {
          if (pivot) {
            l = mid + 1;
          } else {
            r = mid - 1;
          }
        } else {
          if (nums[mid] < target) {
            l = mid + 1;
          } else {
            r = mid - 1;
          }
        }
      }

      return false;
    }
  };

  class Solution *solution;
};

TEST_F(q81, sample_input01) {
  solution = new Solution();
  vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
  int target = 0;
  bool exp = true;
  bool act = solution->search(nums, target);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q81, sample_input02) {
  solution = new Solution();
  vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
  int target = 3;
  bool exp = false;
  bool act = solution->search(nums, target);
  EXPECT_EQ(act, exp);
  delete solution;
}