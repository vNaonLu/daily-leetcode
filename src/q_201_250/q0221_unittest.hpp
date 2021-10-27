
#ifndef Q221_UNITTEST_H__
#define Q221_UNITTEST_H__
#include <gtest/gtest.h>

#include "q0221.hpp"
using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 221.
 *      Maximal Square
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   Given an ‘m x n’ binary ‘matrix’ filled with ‘0’ 's and ‘1’ 's, “find
 *   the largest square containing only” ‘1’ 's “and return its area” .
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘m = matrix.length’
 *   • ‘n = matrix[i].length’
 *   • ‘1 ≤ m, n ≤ 300’
 *   • ‘matrix[i][j]’ is ‘'0'’ or ‘'1'’ .
 *
 */

TEST(q221, sample_input01) {
  l221::Solution solver;
  vector<vector<char>> matrix = {{'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}};
  int exp = 4;
  EXPECT_EQ(solver.maximalSquare(matrix), exp);
}

TEST(q221, sample_input02) {
  l221::Solution solver;
  vector<vector<char>> matrix = {{'0', '1'}, {'1', '0'}};
  int exp = 1;
  EXPECT_EQ(solver.maximalSquare(matrix), exp);
}

TEST(q221, sample_input03) {
  l221::Solution solver;
  vector<vector<char>> matrix = {{'0'}};
  int exp = 0;
  EXPECT_EQ(solver.maximalSquare(matrix), exp);
}

#endif