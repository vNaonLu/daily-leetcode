
#ifndef Q922_UNITTEST_H__
#define Q922_UNITTEST_H__
#include <gtest/gtest.h>

#include "q0922.hpp"
using namespace std;

/**
  * This file is generated by leetcode_add.py
  *
  * 922.
  *      Sort Array By Parity II
  *
  * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
  *
  *   Given an array of integers ‘nums’ , half of the integers in ‘nums’ are
  *   “odd” , and the other half are “even”.
  *   
  *   Sort the array so that whenever ‘nums[i]’ is odd, ‘i’ is “odd” , and
  *   whenever ‘nums[i]’ is even, ‘i’ is “even”.
  *   
  *   Return “any answer array that satisfies this condition”.
  *
  * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
  *
  *   • ‘2 ≤ nums.length ≤ 2 × 10⁴’
  *   • ‘nums.length’ is even.
  *   • Half of the integers in ‘nums’ are even.
  *   • ‘0 ≤ nums[i] ≤ 1000’
  *
*/

TEST(q922, sample_input01) {
  l922::Solution solver;
  vector<int> nums = {4, 2, 5, 7};
  vector<int> exp = {4, 5, 2, 7};
  EXPECT_EQ(solver.sortArrayByParityII(nums), exp);
}

TEST(q922, sample_input02) {
  l922::Solution solver;
  vector<int> nums = {2, 3};
  vector<int> exp = {2, 3};
  EXPECT_EQ(solver.sortArrayByParityII(nums), exp);
}

#endif