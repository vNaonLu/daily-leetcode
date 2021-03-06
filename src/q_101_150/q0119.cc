#include <gtest/gtest.h>
#include <iostream>
#include <vector>

using namespace std;

/**
 * This file is generated by leetcode_add.py v1.0
 *
 * 119.
 *      Pascal's Triangle II
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   Given an integer ‘rowIndex’ , return the ‘rowIndexᵗʰ’ ( “0-indexed” )
 *   row of the “Pascal's triangle”
 *   In “Pascal's triangle” , each number is the sum of the two numbers
 *   directly above it as shown:
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘0 ≤ rowIndex ≤ 33’
 *
 */

struct q119 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   public:
    vector<int> getRow(int rowIndex) {
      vector<int> res(rowIndex + 1, 1);
      for (int i = 1; i < rowIndex; ++i) {
        res[i] = (double)res[i - 1] * (double)(rowIndex - i + 1) / (double)i;
      }
      return res;
    }
  };

  class Solution *solution;
};

TEST_F(q119, sample_input01) {
  solution = new Solution();
  int rowIndex = 3;
  vector<int> exp = {1, 3, 3, 1};
  EXPECT_EQ(solution->getRow(rowIndex), exp);
  delete solution;
}

TEST_F(q119, sample_input02) {
  solution = new Solution();
  int rowIndex = 0;
  vector<int> exp = {1};
  EXPECT_EQ(solution->getRow(rowIndex), exp);
  delete solution;
}

TEST_F(q119, sample_input03) {
  solution = new Solution();
  int rowIndex = 1;
  vector<int> exp = {1, 1};
  EXPECT_EQ(solution->getRow(rowIndex), exp);
  delete solution;
}