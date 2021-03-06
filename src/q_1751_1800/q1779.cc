#include <gtest/gtest.h>
#include <iostream>
#include <vector>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 1779.
 *       Find Nearest Point That Has the Same X or Y Coordinate
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   You are given two integers, ‘x’ and ‘y’ , which represent your current
 *   location on a Cartesian grid: ‘(x, y)’ . You are also given an array
 *   ‘points’ where each ‘points[i] = [aᵢ, bᵢ]’ represents that a point
 *   exists at ‘(aᵢ, bᵢ)’ . A point is “valid” if it shares the same
 *   x-coordinate or the same y-coordinate as your
 *   Return “the index “(0-indexed)” of the “valid” point with the smallest
 *   “Manhattan distance” from your current location” . If there are
 *   multiple, return “the valid point with the “smallest” index” . If
 *   there are no valid points, return ‘-1’
 *   The “Manhattan distance” between two points ‘(x₁, y₁)’ and ‘(x₂, y₂)’
 *   is ‘abs(x₁ - x₂) + abs(y₁ - y₂)’ .
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤ points.length ≤ 10⁴’
 *   • ‘points[i].length = 2’
 *   • ‘1 ≤ x, y, aᵢ, bᵢ ≤ 10⁴’
 *
 */

struct q1779 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   public:
    int nearestValidPoint(int x, int y, vector<vector<int>> &points) {
      int dist = numeric_limits<int>::max(),
          res = -1;

      for (int i = 0; i < points.size(); ++i) {
        auto &v = points[i];
        int manhattan_dist = abs(x - v[0]) + abs(y - v[1]);
        if ((v[0] == x || v[1] == y) && manhattan_dist < dist) {
          dist = manhattan_dist;
          res = i;
        }
      }

      return res;
    }
  };

  class Solution *solution;
};

TEST_F(q1779, sample_input01) {
  solution = new Solution();
  int x = 3;
  int y = 4;
  vector<vector<int>> points = {{1, 2}, {3, 1}, {2, 4}, {2, 3}, {4, 4}};
  int exp = 2;
  int act = solution->nearestValidPoint(x, y, points);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q1779, sample_input02) {
  solution = new Solution();
  int x = 3;
  int y = 4;
  vector<vector<int>> points = {{3, 4}};
  int exp = 0;
  int act = solution->nearestValidPoint(x, y, points);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q1779, sample_input03) {
  solution = new Solution();
  int x = 3;
  int y = 4;
  vector<vector<int>> points = {{2, 3}};
  int exp = -1;
  int act = solution->nearestValidPoint(x, y, points);
  EXPECT_EQ(act, exp);
  delete solution;
}