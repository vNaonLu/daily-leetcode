#include <gtest/gtest.h>
#include <iostream>
#include <vector>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 1351.
 *       Count Negative Numbers in a Sorted Matrix
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   Given a ‘m x n’ matrix ‘grid’ which is sorted in non-increasing order
 *   both row-wise and column-wise, return “the number of “negative”
 *   numbers in” ‘grid’ .
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘m = grid.length’
 *   • ‘n = grid[i].length’
 *   • ‘1 ≤ m, n ≤ 100’
 *   • ‘-100 ≤ grid[i][j] ≤ 100’
 *
 */

struct q1351 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   private:
    int count(vector<int> &v) {
      int l = 0, r = v.size();
      while (l < r) {
        int m = l + (r - l) / 2;
        if (v[m] >= 0) {
          l = m + 1;
        } else {
          r = m;
        }
      }

      return v.size() - l;
    }

   public:
    int countNegatives(vector<vector<int>> &grid) {
      int res = 0;
      for (auto &v : grid) {
        res += count(v);
      }

      return res;
    }
  };

  class Solution *solution;
};

TEST_F(q1351, sample_input01) {
  solution = new Solution();
  vector<vector<int>> grid = {{4, 3, 2, -1}, {3, 2, 1, -1}, {1, 1, -1, -2}, {-1, -1, -2, -3}};
  int exp = 8;
  int act = solution->countNegatives(grid);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q1351, sample_input02) {
  solution = new Solution();
  vector<vector<int>> grid = {{3, 2}, {1, 0}};
  int exp = 0;
  int act = solution->countNegatives(grid);
  EXPECT_EQ(act, exp);
  delete solution;
}