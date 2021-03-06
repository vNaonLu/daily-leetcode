#include <gtest/gtest.h>
#include <iostream>
#include <vector>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 1232.
 *       Check If It Is a Straight Line
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   You are given an array ‘coordinates’ , ‘coordinates[i] = [x, y]’ ,
 *   where ‘[x, y]’ represents the coordinate of a point. Check if these
 *   pointsmake a straight line in the XY
 *   
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘2 ≤coordinates.length ≤ 1000’
 *   • ‘coordinates[i].length = 2’
 *   • ‘-10^4 ≤coordinates[i][0],coordinates[i][1] ≤ 10^4’
 *   • ‘coordinates’ contains no duplicate point.
 *
 */

struct q1232 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
      double x = coordinates[1][0] - coordinates[0][0],
             y = coordinates[1][1] - coordinates[0][1];

      for (int i = 1; i < coordinates.size() - 1; ++i) {
        double dx = coordinates[i + 1][0] - coordinates[i][0],
               dy = coordinates[i + 1][1] - coordinates[i][1];
        if (x * dy != y * dx) {
          return false;
        }

        x = dx;
        y = dy;
      }

      return true;
    }
  };

  class Solution *solution;
};

TEST_F(q1232, sample_input01) {
  solution = new Solution();
  vector<vector<int>> coordinates = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {6, 7}};
  bool exp = true;
  bool act = solution->checkStraightLine(coordinates);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q1232, sample_input02) {
  solution = new Solution();
  vector<vector<int>> coordinates = {{1, 1}, {2, 2}, {3, 4}, {4, 5}, {5, 6}, {7, 7}};
  bool exp = false;
  bool act = solution->checkStraightLine(coordinates);
  EXPECT_EQ(act, exp);
  delete solution;
}