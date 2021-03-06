#include <gtest/gtest.h>
#include <iostream>
#include <vector>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 840.
 *      Magic Squares In Grid
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   A ‘3 x 3’ magic square is a ‘3 x 3’ grid filled with distinct numbers
 *   “from ” ‘1’ “ to ” ‘9’ such that each row, column, and both diagonals
 *   all have the same
 *   Given a ‘row x col’  ‘grid’ of integers, how many ‘3 x 3’ 'magic
 *   square' subgrids are there? (Each subgrid is contiguous).
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘row = grid.length’
 *   • ‘col = grid[i].length’
 *   • ‘1 ≤ row, col ≤ 10’
 *   • ‘0 ≤ grid[i][j] ≤ 15’
 *
 */

struct q840 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   private:
    int m, n;
    bool checkDistinct(vector<vector<int>> &grid, int row, int col) noexcept {
      vector<bool> exist(10, false);
      for (int i = row; i < row + 3; ++i) {
        for (int j = col; j < col + 3; ++j) {
          auto x = grid[i][j];
          if (x == 0 || x > 9 || exist[x]) return false;
          exist[x] = true;
        }
      }
      return true;
    }
    bool checkSum(vector<vector<int>> &grid, int row, int col) noexcept {
      int sum = grid[row][col] + grid[row][col + 1] + grid[row][col + 2];
      /// check rows
      for (int i = row + 1; i < row + 3; ++i) {
        if (sum != grid[i][col] + grid[i][col + 1] + grid[i][col + 2]) return false;
      }
      /// check cols
      for (int i = col; i < col + 3; ++i) {
        if (sum != grid[row][i] + grid[row + 1][i] + grid[row + 2][i]) return false;
      }
      /// check diagnal
      if (sum != grid[row][col] + grid[row + 1][col + 1] + grid[row + 2][col + 2]) return false;
      if (sum != grid[row + 2][col] + grid[row + 1][col + 1] + grid[row][col + 2]) return false;
      return true;
    }

   public:
    int numMagicSquaresInside(vector<vector<int>> &grid) {
      m = grid.size();
      n = grid[0].size();
      int res = 0;
      for (int i = 0; i < m - 2; ++i) {
        for (int j = 0; j < n - 2; ++j) {
          if (checkDistinct(grid, i, j) && checkSum(grid, i, j)) ++res;
        }
      }
      return res;
    }
  };

  class Solution *solution;
};

TEST_F(q840, sample_input01) {
  solution = new Solution();
  vector<vector<int>> grid = {{4, 3, 8, 4}, {9, 5, 1, 9}, {2, 7, 6, 2}};
  int exp = 1;
  int act = solution->numMagicSquaresInside(grid);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q840, sample_input02) {
  solution = new Solution();
  vector<vector<int>> grid = {{8}};
  int exp = 0;
  int act = solution->numMagicSquaresInside(grid);
  EXPECT_EQ(act, exp);
  delete solution;
}