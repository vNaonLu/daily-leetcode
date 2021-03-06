#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * This file is generated by leetcode_add.py v1.0
 *
 * 2018.
 *       Check if Word Can Be Placed In Crossword
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   You are given an ‘m x n’ matrix ‘board’ , representing the “ current ”
 *   state of a crossword puzzle. The crossword contains lowercase English
 *   letters (from solved words), ‘' '’ to represent any “empty ” cells,
 *   and ‘'#'’ to represent any “blocked”
 *   A word can be placed “ horizontally” (left to right “or” right to
 *   left) or “vertically” (top to bottom “or” bottom to top) in the board
 *       - It does not occupy a cell containing the character ‘'#'’
 *       - The cell each letter is placed in must either be ‘' '’ (empty)
 *   or “match” the letter already on the ‘board’
 *       - There must not be any empty cells ‘' '’ or other lowercase
 *   letters “directly left or right”  “ ” of the word if the word was
 *   placed “horizontally”
 *       - There must not be any empty cells ‘' '’ or other lowercase
 *   letters “directly above or below” the word if the word was placed
 *   “vertically”
 *   Given a string ‘word’ , return ‘true’ “ if ” ‘word’ “ can be placed in
 *   ” ‘board’ “, or ” ‘false’ “ “otherwise” ” .
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘m = board.length’
 *   • ‘n = board[i].length’
 *   • ‘1 ≤ m × n ≤ 2 × 10⁵’
 *   • ‘board[i][j]’ will be ‘' '’ , ‘'#'’ , or a lowercase English letter.
 *   • ‘1 ≤ word.length ≤ max(m, n)’
 *   • ‘word’ will contain only lowercase English letters.
 *
 */

struct q2018 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   private:
    inline vector<vector<char>> transpose(const vector<vector<char>> &in) {
      vector<vector<char>> res(in[0].size(), vector<char>(in.size(), 0));
      for (int i = 0; i < in.size(); ++i)
        for (int j = 0; j < in[0].size(); ++j)
          res[j][i] = in[i][j];
      return res;
    }
    template <typename T>
    inline bool same(T beg, T end, const string &s) {
      auto c = s.begin();
      while (beg != end && c != s.end()) {
        if (*beg != ' ' && *beg != *c) return false;
        ++beg;
        ++c;
      }
      return beg == end;
    }
    bool match_horizontally(const vector<vector<char>> &b, string s) {
      int N = b[0].size();
      for (const auto &row : b) {
        for (int i = 0; i < N;) {
          while (i < N && row[i] == '#') ++i;
          int beg = i;
          while (i < N && row[i] != '#') ++i;
          if (i - beg == s.size()) {
            if (same(row.cbegin() + beg, row.cbegin() + i, s))
              return true;
          }
        }
      }
      return false;
    }
   public:
    bool placeWordInCrossword(vector<vector<char>> &board, string word) {
      auto trans = transpose(board);
      return match_horizontally(board, word) ||
             match_horizontally(board, string(word.rbegin(), word.rend())) ||
             match_horizontally(trans, word) ||
             match_horizontally(trans, string(word.rbegin(), word.rend()));
    }
  };

  class Solution *solution;
};

TEST_F(q2018, sample_input01) {
  solution = new Solution();
  vector<vector<char>> board = {{'#', ' ', '#'}, {' ', ' ', '#'}, {'#', 'c', ' '}};
  string word = "abc";
  bool exp = true;
  EXPECT_EQ(solution->placeWordInCrossword(board, word), exp);
  delete solution;
}

TEST_F(q2018, sample_input02) {
  solution = new Solution();
  vector<vector<char>> board = {{' ', '#', 'a'}, {' ', '#', 'c'}, {' ', '#', 'a'}};
  string word = "ac";
  bool exp = false;
  EXPECT_EQ(solution->placeWordInCrossword(board, word), exp);
  delete solution;
}

TEST_F(q2018, sample_input03) {
  solution = new Solution();
  vector<vector<char>> board = {{'#', ' ', '#'}, {' ', ' ', '#'}, {'#', ' ', 'c'}};
  string word = "ca";
  bool exp = true;
  EXPECT_EQ(solution->placeWordInCrossword(board, word), exp);
  delete solution;
}