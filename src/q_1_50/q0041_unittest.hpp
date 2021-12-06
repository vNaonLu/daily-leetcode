
#ifndef Q41_UNITTEST_H__
#define Q41_UNITTEST_H__
#include <gtest/gtest.h>

#include "q0041.hpp"
using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 41.
 *     First Missing Positive
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   Given an unsorted integer array ‘nums’ , return the smallest missing
 *   positive
 *   You must implement an algorithm that runs in ‘O(n)’ time and uses
 *   constant extra space.
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤ nums.length ≤ 5 × 10⁵’
 *   • ‘-2³¹ ≤ nums[i] ≤ 2³¹ - 1’
 *
 */

TEST(q41, sample_input01) {
  l41::Solution solver;
  vector<int> nums = {1, 2, 0};
  int exp = 3;
  EXPECT_EQ(solver.firstMissingPositive(nums), exp);
}

TEST(q41, sample_input02) {
  l41::Solution solver;
  vector<int> nums = {3, 4, -1, 1};
  int exp = 2;
  EXPECT_EQ(solver.firstMissingPositive(nums), exp);
}

TEST(q41, sample_input03) {
  l41::Solution solver;
  vector<int> nums = {7, 8, 9, 11, 12};
  int exp = 1;
  EXPECT_EQ(solver.firstMissingPositive(nums), exp);
}

#endif