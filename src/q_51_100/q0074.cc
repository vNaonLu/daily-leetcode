#include <gtest/gtest.h>
#include <iostream>
#include <vector>

using namespace std;

/**
 * This file is generated by leetcode_add.py v1.0
 *
 * 74.
 *     Search a 2D Matrix
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   Write an efficient algorithm that searches for a value in an ‘m x n’
 *   matrix. This matrix has the following
 *       - Integers in each row are sorted from left to
 *       - The first integer of each row is greater than the last integer
 *   of the previous row.
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘m = matrix.length’
 *   • ‘n = matrix[i].length’
 *   • ‘1 ≤ m, n ≤ 100’
 *   • ‘-10⁴ ≤ matrix[i][j], target ≤ 10⁴’
 *
 */

struct q74 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      for (int i = 0; i < matrix.size(); ++i) {
        if (target > matrix[i].back()) continue;
        if (target < matrix[i].front()) continue;
        int l = 0, r = matrix[i].size() - 1;
        while (l <= r) {
          int mid = l + (r - l) / 2;
          if (target == matrix[i][mid]) return true;
          if (target < matrix[i][mid])
            r = mid - 1;
          else
            l = mid + 1;
        }
      }
      return false;
    }
  };

  class Solution *solution;
};

TEST_F(q74, sample_input01) {
  solution = new Solution();
  vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
  int target = 3;
  bool exp = true;
  EXPECT_EQ(solution->searchMatrix(matrix, target), exp);
  delete solution;
}

TEST_F(q74, sample_input02) {
  solution = new Solution();
  vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
  int target = 13;
  bool exp = false;
  EXPECT_EQ(solution->searchMatrix(matrix, target), exp);
  delete solution;
}