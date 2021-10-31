
#ifndef Q376_UNITTEST_H__
#define Q376_UNITTEST_H__
#include <gtest/gtest.h>

#include "q0376.hpp"
using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 376.
 *      Wiggle Subsequence
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   A “wiggle sequence” is a sequence where the differences between
 *   successive numbers strictly alternate between positive and negative.
 *   The first difference (if one exists) may be either positive or
 *   negative. A sequence with one element and a sequence with two
 *   non-equal elements are trivially wiggle
 *       - For example, ‘[1, 7, 4, 9, 2, 5]’ is a “wiggle sequence” because
 *   the differences ‘(6, -3, 5, -7, 3)’ alternate between positive and
 *       - In contrast, ‘[1, 4, 7, 2, 5]’ and ‘[1, 7, 4, 5, 5]’ are not
 *   wiggle sequences. The first is not because its first two differences
 *   are positive, and the second is not because its last difference is
 *   A “subsequence” is obtained by deleting some elements (possibly zero)
 *   from the original sequence, leaving the remaining elements in their
 *   original
 *   Given an integer array ‘nums’ , return “the length of the longest
 *   “wiggle subsequence” of ” ‘nums’ .
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤ nums.length ≤ 1000’
 *   • ‘0 ≤ nums[i] ≤ 1000’
 *
 */

TEST(q376, sample_input01) {
  l376::Solution solver;
  vector<int> nums = {1, 7, 4, 9, 2, 5};
  int exp = 6;
  EXPECT_EQ(solver.wiggleMaxLength(nums), exp);
}

TEST(q376, sample_input02) {
  l376::Solution solver;
  vector<int> nums = {1, 17, 5, 10, 13, 15, 10, 5, 16, 8};
  int exp = 7;
  EXPECT_EQ(solver.wiggleMaxLength(nums), exp);
}

TEST(q376, sample_input03) {
  l376::Solution solver;
  vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int exp = 2;
  EXPECT_EQ(solver.wiggleMaxLength(nums), exp);
}

#endif