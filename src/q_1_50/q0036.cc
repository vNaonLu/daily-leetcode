#include <gtest/gtest.h>
#include <iostream>
#include <vector>

using namespace std;

/**
 * This file is generated by leetcode_add.py v1.0
 *
 * 36.
 *     Valid Sudoku
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   Determine if a ‘9 x 9’ Sudoku boardis valid.Only the filled cells need
 *   to be validated “according to the following rules”
 *       1. Each rowmust contain thedigits ‘1-9’ without
 *       2. Each column must contain the digits ‘1-9’ without
 *       3. Each of the nine ‘3 x 3’ sub-boxes of the grid must contain the
 *   digits ‘1-9’ without
 *    “Note:”
 *       - A Sudoku board (partially filled) could be valid but is not
 *   necessarily
 *       - Only the filled cells need to be validated according to the
 *   mentionedrules.
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘board.length = 9’
 *   • ‘board[i].length = 9’
 *   • ‘board[i][j]’ is a digit ‘1-9’ or ‘'.'’ .
 *
 */

struct q36 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
      return helper(board, 0, 0);
    }
   private:
    bool helper(vector<vector<char>>& b, int c, int r) {
      if (r > 8) return true;
      if (c > 8) return helper(b, 0, r + 1);
      if (b[r][c] != '.') {
        char current = b[r][c];
        for (int i = 0; i < 9; ++i) {
          if (i == c) continue;
          if (b[r][i] == current) return false;
        }
        for (int i = 0; i < 9; ++i) {
          if (i == r) continue;
          if (b[i][c] == current) return false;
        }
        int block_col = c / 3 * 3,
            block_row = r / 3 * 3;
        for (int i = block_row; i < block_row + 3; ++i) {
          for (int j = block_col; j < block_col + 3; ++j) {
            if (i == r && j == c) continue;
            if (b[i][j] == current) return false;
          }
        }
      }
      return helper(b, c + 1, r);
    }
  };

  class Solution *solution;
};

TEST_F(q36, sample_input01) {
  solution = new Solution();
  vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
  bool exp = true;
  EXPECT_EQ(solution->isValidSudoku(board), exp);
  delete solution;
}

TEST_F(q36, sample_input02) {
  solution = new Solution();
  vector<vector<char>> board = {{'8', '3', '.', '.', '7', '.', '.', '.', '.'},
                                {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
  bool exp = false;
  EXPECT_EQ(solution->isValidSudoku(board), exp);
  delete solution;
}