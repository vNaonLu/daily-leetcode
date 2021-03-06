#include <gtest/gtest.h>
#include <iostream>
#include <vector>

using namespace std;

/**
 * This file is generated by leetcode_add.py v1.0
 *
 * 120.
 *      Triangle
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   Given a ‘triangle’ array, return “the minimum path sum from top to
 *   bottom”
 *   For each step, you may move to an adjacent number of the row below.
 *   More formally, if you are on index ‘i’ on the current row, you may
 *   move to either index ‘i’ or index ‘i + 1’ on the next row.
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤ triangle.length ≤ 200’
 *   • ‘triangle[0].length = 1’
 *   • ‘triangle[i].length = triangle[i - 1].length + 1’
 *   • ‘-10⁴ ≤ triangle[i][j] ≤ 10⁴’
 *
 */

struct q120 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   public:
    int minimumTotal(vector<vector<int>>& triangle) {
      for (int i = triangle.size() - 2; i > -1; --i) {
        for (int j = 0; j < triangle[i].size(); ++j) {
          triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
        }
      }
      return triangle[0][0];
    }
  };

  class Solution *solution;
};

TEST_F(q120, sample_input01) {
  solution = new Solution();
  vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
  int exp = 11;
  EXPECT_EQ(solution->minimumTotal(triangle), exp);
  delete solution;
}

TEST_F(q120, sample_input02) {
  solution = new Solution();
  vector<vector<int>> triangle = {{-10}};
  int exp = -10;
  EXPECT_EQ(solution->minimumTotal(triangle), exp);
  delete solution;
}