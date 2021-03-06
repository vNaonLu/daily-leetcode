#include <array>
#include <gtest/gtest.h>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 1905.
 *       Count Sub Islands
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   You are given two ‘m x n’ binary matrices ‘grid1’ and ‘grid2’
 *   containing only ‘0’ 's (representing water) and ‘1’ 's (representing
 *   land). An “island” is a group of ‘1’ 's connected “4-directionally”
 *   (horizontal or vertical). Any cells outside of the grid are considered
 *   water
 *   An island in ‘grid2’ is considered a “sub-island ” if there is an
 *   island in ‘grid1’ that contains “all” the cells that make up “this”
 *   island in ‘grid2’
 *   Return the “ “number” of islands in ” ‘grid2’ “that are considered
 *   “sub-islands” ” .
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘m = grid1.length = grid2.length’
 *   • ‘n = grid1[i].length = grid2[i].length’
 *   • ‘1 ≤ m, n ≤ 500’
 *   • ‘grid1[i][j]’ and ‘grid2[i][j]’ are either ‘0’ or ‘1’ .
 *
 */

struct q1905 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   private:
    vector<vector<int>> g1, g2;
    int m, n;
    array<int, 8> dir = {1, 0, 0, 1, -1, 0, 0, -1};
    inline bool is_valid(int x, int y) {
      return x >= 0 && x < m && y >= 0 && y < n;
    }
    inline bool helper(int i, int j) {
      queue<pair<int, int>> q;
      bool                  res = true;
      q.emplace(i, j);
      while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < dir.size(); ++i) {
          auto dx = x + dir[i],
               dy = y + dir[++i];
          if (is_valid(dx, dy) && g2[dx][dy] == 1) {
            res &= g1[dx][dy] == 1;
            g2[dx][dy] = 0;
            q.emplace(dx, dy);
          }
        }
      }

      return res;
    }

   public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
      int res = 0;
      m = grid1.size(); n = grid1[0].size();
      g1 = move(grid1); g2 = move(grid2);
      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
          if (g2[i][j] == 1) {
            g2[i][j] = 0;
            if (helper(i, j) && g1[i][j] == 1) {
              ++res;
            }
          }
        }
      }

      return res;
    }
  };

  class Solution *solution;
};

TEST_F(q1905, sample_input01) {
  solution = new Solution();
  vector<vector<int>> grid1 = {{1, 1, 1, 0, 0}, {0, 1, 1, 1, 1}, {0, 0, 0, 0, 0}, {1, 0, 0, 0, 0}, {1, 1, 0, 1, 1}};
  vector<vector<int>> grid2 = {{1, 1, 1, 0, 0}, {0, 0, 1, 1, 1}, {0, 1, 0, 0, 0}, {1, 0, 1, 1, 0}, {0, 1, 0, 1, 0}};
  int exp = 3;
  int act = solution->countSubIslands(grid1, grid2);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q1905, sample_input02) {
  solution = new Solution();
  vector<vector<int>> grid1 = {{1, 0, 1, 0, 1}, {1, 1, 1, 1, 1}, {0, 0, 0, 0, 0}, {1, 1, 1, 1, 1}, {1, 0, 1, 0, 1}};
  vector<vector<int>> grid2 = {{0, 0, 0, 0, 0}, {1, 1, 1, 1, 1}, {0, 1, 0, 1, 0}, {0, 1, 0, 1, 0}, {1, 0, 0, 0, 1}};
  int exp = 2;
  int act = solution->countSubIslands(grid1, grid2);
  EXPECT_EQ(act, exp);
  delete solution;
}