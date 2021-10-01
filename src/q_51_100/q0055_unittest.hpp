
#ifndef Q55_UNITTEST_H__
#define Q55_UNITTEST_H__
#include <gtest/gtest.h>

#include "q0055.hpp"
using namespace std;

/**
  * This file is generated by leetcode_add.py
  *
  * 55.
  *     Jump Game
  *
  * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
  *
  *   You are given an integer array ‘nums’ . You are initially positioned
  *   at the array&#39;s “first index” , and each element in the array
  *   represents your maximum jump length at that position.
  *   
  *   Return ‘true’ “ if you can reach the last index, or ” ‘false’ “
  *   otherwise”.
  *
  * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
  *
  *   • ‘1 ≤ nums.length ≤ 10⁴’
  *   • ‘0 ≤ nums[i] ≤ 10⁵’
  *
*/

TEST(q55, sample_input01) {
  l55::Solution solver;
  vector<int> nums = {2, 3, 1, 1, 4};
  bool exp = true;
  EXPECT_EQ(solver.canJump(nums), exp);
}

TEST(q55, sample_input02) {
  l55::Solution solver;
  vector<int> nums = {3, 2, 1, 0, 4};
  bool exp = false;
  EXPECT_EQ(solver.canJump(nums), exp);
}

#endif