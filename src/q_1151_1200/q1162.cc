#include <gtest/gtest.h>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 1162.
 *       As Far from Land as Possible
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   Given an ‘n x n’  ‘grid’ containing only values ‘0’ and ‘1’ , where
 *   ‘0’ represents waterand ‘1’ represents land, find a water cell such
 *   that its distance to the nearest land cell is maximized, and return
 *   the distance.If no land or water exists in the grid, return ‘-1’
 *   The distance used in this problem is the Manhattan distance:the
 *   distance between two cells ‘(x0, y0)’ and ‘(x1, y1)’ is ‘|x0 - x1| +
 *   |y0 - y1|’ .
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘n = grid.length’
 *   • ‘n = grid{i}.length’
 *   • ‘1 ≤ n≤ 100’
 *   • ‘grid{i}{j}’ is ‘0’ or ‘1’
 *
 */

struct q1162 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   public:
    int maxDistance(vector<vector<int>>& grid) {
      queue<pair<int, int>> land_pos;
      int m = grid.size(),
          n = grid[0].size();
      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
          if (grid[i][j] == 1) {
            land_pos.emplace(i, j);
          }
        }
      }

      if (land_pos.empty() || land_pos.size() == m * n) return -1;
      int res = -1;

      while (!land_pos.empty()) {
        auto temp = move(land_pos);
        ++res;

        while (!temp.empty()) {
          auto [x, y] = temp.front();
          temp.pop();

          if (x + 1 < m && grid[x + 1][y] == 0) {
            land_pos.emplace(x + 1, y);
            grid[x + 1][y] = 1;
          }

          if (x - 1 >= 0 && grid[x - 1][y] == 0) {
            land_pos.emplace(x - 1, y);
            grid[x - 1][y] = 1;
          }

          if (y + 1 < n && grid[x][y + 1] == 0) {
            land_pos.emplace(x, y + 1);
            grid[x][y + 1] = 1;
          }

          if (y - 1 >= 0 && grid[x][y - 1] == 0) {
            land_pos.emplace(x, y - 1);
            grid[x][y - 1] = 1;
          }
        }
      }

      return res;
    }
  };

  class Solution *solution;
};

TEST_F(q1162, sample_input01) {
  solution = new Solution();
  vector<vector<int>> grid = {{1, 0, 1}, {0, 0, 0}, {1, 0, 1}};
  int exp = 2;
  int act = solution->maxDistance(grid);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q1162, sample_input02) {
  solution = new Solution();
  vector<vector<int>> grid = {{1, 0, 0}, {0, 0, 0}, {0, 0, 0}};
  int exp = 4;
  int act = solution->maxDistance(grid);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q1162, input01) {
  solution = new Solution();
  vector<vector<int>> grid = {{1, 1, 1, 1, 1}, {1, 1, 1, 1, 1}, {1, 1, 1, 1, 1}, {1, 1, 1, 1, 1}, {1, 1, 1, 1, 1}};
  int exp = -1;
  int act = solution->maxDistance(grid);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q1162, input02) {
  solution = new Solution();
  vector<vector<int>> grid = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
  int exp = -1;
  int act = solution->maxDistance(grid);
  EXPECT_EQ(act, exp);
  delete solution;
}