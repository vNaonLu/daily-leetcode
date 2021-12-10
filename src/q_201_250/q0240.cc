#include <gtest/gtest.h>
#include <iostream>
#include <vector>

using namespace std;

/**
 * This file is generated by leetcode_add.py v1.0
 *
 * 240.
 *      Search a 2D Matrix II
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   Write an efficient algorithm that searches for a ‘target’ value in an
 *   ‘m x n’ integer ‘matrix’ . The ‘matrix’ has the following
 *       - Integers in each row are sorted in ascending from left to
 *       - Integers in each column are sorted in ascending from top to
 *   bottom.
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘m = matrix.length’
 *   • ‘n = matrix[i].length’
 *   • ‘1 ≤ n, m ≤ 300’
 *   • ‘-10⁹ ≤ matrix[i][j] ≤ 10⁹’
 *   • All the integers in each row are “sorted” in ascending order.
 *   • All the integers in each column are “sorted” in ascending order.
 *   • ‘-10⁹ ≤ target ≤ 10⁹’
 *
 */

struct q240 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      int r = 0, c = matrix[0].size() - 1;
      while (r < matrix.size() && c >= 0) {
        if (matrix[r][c] == target)
          return true;
        else if (matrix[r][c] > target)
          --c;
        else
          ++r;
      }
      return false;
    }
  };

  class Solution *solution;
};

TEST_F(q240, sample_input01) {
  solution = new Solution();
  vector<vector<int>> matrix = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
  int target = 5;
  bool exp = true;
  EXPECT_EQ(solution->searchMatrix(matrix, target), exp);
  delete solution;
}

TEST_F(q240, sample_input02) {
  solution = new Solution();
  vector<vector<int>> matrix = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
  int target = 20;
  bool exp = false;
  EXPECT_EQ(solution->searchMatrix(matrix, target), exp);
  delete solution;
}