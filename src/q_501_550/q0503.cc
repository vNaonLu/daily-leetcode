#include <gtest/gtest.h>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 503.
 *      Next Greater Element II
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   Given a circular integer array ‘nums’ (i.e., the next element of
 *   ‘nums[nums.length - 1]’ is ‘nums[0]’ ), return “the “next greater
 *   number” for every element in” ‘nums’
 *   The “next greater number” of a number ‘x’ is the first greater number
 *   to its traversing-order next in the array, which means you could
 *   search circularly to find its next greater number. If it doesn't
 *   exist, return ‘-1’ for this number.
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤ nums.length ≤ 10⁴’
 *   • ‘-10⁹ ≤ nums[i] ≤ 10⁹’
 *
 */

struct q503 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   public:
    vector<int> nextGreaterElements(vector<int>& nums) {
      int n = nums.size();
      stack<int> stk;
      vector<int> res(n);

      for (int i = 2 * n - 1; i >= 0; --i) {
        while (!stk.empty() && stk.top() <= nums[i % n]) {
          stk.pop();
        }

        if (stk.empty()) {
          res[i % n] = -1;
        } else {
          res[i % n] = stk.top();
        }
        stk.emplace(nums[i % n]);
      }

      return res;
    }
  };

  class Solution *solution;
};

TEST_F(q503, sample_input01) {
  solution = new Solution();
  vector<int> nums = {1, 2, 1};
  vector<int> exp = {2, -1, 2};
  vector<int> act = solution->nextGreaterElements(nums);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q503, sample_input02) {
  solution = new Solution();
  vector<int> nums = {1, 2, 3, 4, 3};
  vector<int> exp = {2, 3, 4, -1, 4};
  vector<int> act = solution->nextGreaterElements(nums);
  EXPECT_EQ(act, exp);
  delete solution;
}