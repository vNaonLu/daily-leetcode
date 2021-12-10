#include <gtest/gtest.h>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/**
 * This file is generated by leetcode_add.py v1.0
 *
 * 200.
 *      Number of Islands
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   Given an ‘m x n’ 2D binary grid ‘grid’ which represents a map of ‘'1'’
 *   s (land) and ‘'0'’ s (water), return “the number of islands”
 *   An “island” is surrounded by water and is formed by connecting
 *   adjacent lands horizontally or vertically. You may assume all four
 *   edges of the grid are all surrounded by water.
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘m = grid.length’
 *   • ‘n = grid[i].length’
 *   • ‘1 ≤ m, n ≤ 300’
 *   • ‘grid[i][j]’ is ‘'0'’ or ‘'1'’ .
 *
 */

struct q200 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   private:
    vector<int> dir = {-1, 0, 1, 0, 0, 1, 0, -1};
   public:
    int numIslands(vector<vector<char>>& grid) {
      int res = 0;
      int m = grid.size(), n = grid[0].size();
      queue<pair<int, int>> island;
      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
          if (grid[i][j] == '1') {
            island.push({i, j});
            grid[i][j] = '0';
            while (!island.empty()) {
              auto& p = island.front();
              for (int k = 0; k < dir.size(); ++k) {
                int x = p.first + dir[k],
                    y = p.second + dir[++k];
                if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == '1') {
                  grid[x][y] = '0';
                  island.emplace(x, y);
                }
              }
              island.pop();
            }
            ++res;
          }
        }
      }
      return res;
    }
  };

  class Solution *solution;
};

TEST_F(q200, sample_input01) {
  solution = new Solution();
  vector<vector<char>> grid = {{'1', '1', '1', '1', '0'}, {'1', '1', '0', '1', '0'}, {'1', '1', '0', '0', '0'}, {'0', '0', '0', '0', '0'}};
  int exp = 1;
  EXPECT_EQ(solution->numIslands(grid), exp);
  delete solution;
}

TEST_F(q200, sample_input02) {
  solution = new Solution();
  vector<vector<char>> grid = {{'1', '1', '0', '0', '0'}, {'1', '1', '0', '0', '0'}, {'0', '0', '1', '0', '0'}, {'0', '0', '0', '1', '1'}};
  int exp = 3;
  EXPECT_EQ(solution->numIslands(grid), exp);
  delete solution;
}