
#ifndef Q162_UNITTEST_H__
#define Q162_UNITTEST_H__
#include <gtest/gtest.h>

#include "q0162.hpp"
using namespace std;

/**
  * this file is generated by gquestion.py
  *
  * 162. Find Peak Element
  *
  * A peak element is an element that is strictly
  * greater than its neighbors.
  * Given an integer array nums , find a peak
  * element, and return its index. Ifthe array contains
  * multiple peaks, return the index to “any of the peaks“
  * .
  * You may imagine that nums[-1] = nums[n] =
  * -&infin; .
  * You must write an algorithm that runs in O(log n)
  * time.
  *
  * Constraints:
  * -  1 <= nums.length <= 1000 
  * -  -2^(31) <= nums[i] <= 2^(31) - 1 
  * -  nums[i] != nums[i + 1] for all valid i .
  *
*/

TEST(q162, sample_input01) {
  vector<int> nums = {1, 2, 3, 1};
  int exp = 2;
  l162::Solution solver;
  EXPECT_EQ(solver.findPeakElement(nums), exp);
}

TEST(q162, sample_input02) {
  vector<int> nums = {1, 2, 1, 3, 5, 6, 4};
  int exp = 5;
  l162::Solution solver;
  EXPECT_EQ(solver.findPeakElement(nums), exp);
}

#endif