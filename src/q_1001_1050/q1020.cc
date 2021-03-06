#include <gtest/gtest.h>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 1020.
 *       Number of Enclaves
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   You are given an ‘m x n’ binary matrix ‘grid’ , where ‘0’ represents a
 *   sea cell and ‘1’ represents a land
 *   A “move” consists of walking from one land cell to another adjacent (
 *   “4-directionally” ) land cell or walking off the boundary of the
 *   ‘grid’
 *   Return “the number of land cells in” ‘grid’ “for which we cannot walk
 *   off the boundary of the grid in any number of “moves” ” .
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘m = grid.length’
 *   • ‘n = grid[i].length’
 *   • ‘1 ≤ m, n ≤ 500’
 *   • ‘grid[i][j]’ is either ‘0’ or ‘1’ .
 *
 */

struct q1020 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   private:
    int m, n;
    const vector<int> dir = {1, 0, 0, 1, -1, 0, 0, -1};
    bool isBound(int row, int col) {
      return row == 0 || row == m - 1 || col == 0 || col == n - 1;
    }
    bool isValid(int row, int col) {
      return row >= 0 && row <= m - 1 && col >= 0 && col <= n - 1;
    }
    int walkOff(vector<vector<int>> &grid, int row, int col) {
      stack<pair<int, int>> stk;
      stk.emplace(row, col);
      grid[row][col] = 0;
      int land_cnt = 0;
      bool bound = false;
      while (!stk.empty()) {
        auto [px, py] = stk.top(); stk.pop();
        ++land_cnt;
        if (isBound(px, py)) bound = true;
        for (int i = 0; i < dir.size();) {
          int x = px + dir[i++],
              y = py + dir[i++];
          if (isValid(x, y) && grid[x][y] == 1) {
            grid[x][y] = 0;
            stk.emplace(x, y);
          }
        }
      }
      return bound ? 0 : land_cnt;
    }

   public:
    int numEnclaves(vector<vector<int>> &grid) {
      m = grid.size();
      n = grid[0].size();
      int res = 0;
      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
          if (grid[i][j] == 1) {
            res += walkOff(grid, i, j);
          }
        }
      }
      return res;
    }
  };

  class Solution *solution;
};

TEST_F(q1020, sample_input01) {
  solution = new Solution();
  vector<vector<int>> grid = {{0, 0, 0, 0}, {1, 0, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}};
  int exp = 3;
  int act = solution->numEnclaves(grid);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q1020, sample_input02) {
  solution = new Solution();
  vector<vector<int>> grid = {{0, 1, 1, 0}, {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 0, 0}};
  int exp = 0;
  int act = solution->numEnclaves(grid);
  EXPECT_EQ(act, exp);
  delete solution;
}