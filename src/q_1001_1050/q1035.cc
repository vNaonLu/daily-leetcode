#include <gtest/gtest.h>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 1035.
 *       Uncrossed Lines
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   You are given two integer arrays ‘nums1’ and ‘nums2’ . We write the
 *   integers of ‘nums1’ and ‘nums2’ (in the order they are given) on two
 *   separate horizontal
 *   We may draw connecting lines: a straight line connecting two numbers
 *   ‘nums1[i]’ and ‘nums2[j]’ such
 *       -  ‘nums1[i] = nums2[j]’ ,
 *       - the line we draw does not intersect any other connecting
 *   (non-horizontal)
 *   Note that a connecting line cannot intersect even at the endpoints
 *   (i.e., each number can only belong to one connecting
 *   Return “the maximum number of connecting lines we can draw in this
 *   way” .
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤ nums1.length, nums2.length ≤ 500’
 *   • ‘1 ≤ nums1[i], nums2[j] ≤ 2000’
 *
 */

struct q1035 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   private:
    unordered_map<int, int> memos;
    int n;

    int encode(int i, int j) {
      return i * n + j;
    }

    int helper(vector<int> &nums1, int i1, vector<int> &nums2, int i2) {
      if (i1 >= nums1.size() || i2 >= nums2.size()) {
        return 0;
      }

      if (memos.count(encode(i1, i2))) {
        return memos[encode(i1, i2)];
      }

      int res = max(helper(nums1, i1, nums2, i2 + 1), helper(nums1, i1 + 1, nums2, i2));
      res = max(res, helper(nums1, i1 + 1, nums2, i2 + 1) + (nums1[i1] == nums2[i2] ? 1 : 0));

      return memos[encode(i1, i2)] = res;
    }

   public:
    int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2) {
      n = nums2.size();
      return helper(nums1, 0, nums2, 0);
    }
  };

  class Solution *solution;
};

TEST_F(q1035, sample_input01) {
  solution = new Solution();
  vector<int> nums1 = {1, 4, 2};
  vector<int> nums2 = {1, 2, 4};
  int exp = 2;
  int act = solution->maxUncrossedLines(nums1, nums2);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q1035, sample_input02) {
  solution = new Solution();
  vector<int> nums1 = {2, 5, 1, 2, 5};
  vector<int> nums2 = {10, 5, 2, 1, 5, 2};
  int exp = 3;
  int act = solution->maxUncrossedLines(nums1, nums2);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q1035, sample_input03) {
  solution = new Solution();
  vector<int> nums1 = {1, 3, 7, 1, 7, 5};
  vector<int> nums2 = {1, 9, 2, 5, 1};
  int exp = 2;
  int act = solution->maxUncrossedLines(nums1, nums2);
  EXPECT_EQ(act, exp);
  delete solution;
}