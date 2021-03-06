#include <gtest/gtest.h>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * This file is generated by leetcode_add.py v1.0
 *
 * 149.
 *      Max Points on a Line
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   Given an array of ‘points’ where ‘points[i] = [xᵢ, yᵢ]’ represents a
 *   point on the “X-Y” plane, return “the maximum number of points that
 *   lie on the same straight line” .
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤ points.length ≤ 300’
 *   • ‘points[i].length = 2’
 *   • ‘-10⁴ ≤ xᵢ, yᵢ ≤ 10⁴’
 *   • All the ‘points’ are “unique” .
 *
 */

struct q149 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   public:
    int maxPoints(vector<vector<int>>& points) {
      int res = 0;
      for (auto pt1 = points.begin(); pt1 != points.end(); ++pt1) {
        unordered_map<double, int> slope;
        int same = 1;
        for (auto pt2 = pt1 + 1; pt2 != points.end(); ++pt2) {
          if (*pt1 == *pt2) {
            ++same;
          } else if ((*pt1)[0] == (*pt2)[0]) {
            ++slope[numeric_limits<double>::max()];
          } else {
            double s = (double)((*pt2)[1] - (*pt1)[1]) / (double)((*pt2)[0] - (*pt1)[0]);
            ++slope[s];
          }
        }
        int local_max = 0;
        for (auto it = slope.begin(); it != slope.end(); ++it)
          local_max = max(local_max, it->second);
        res = max(res, local_max + same);
      }
      return res;
    }
  };

  class Solution *solution;
};

TEST_F(q149, sample_input01) {
  solution = new Solution();
  vector<vector<int>> points = {{1, 1}, {2, 2}, {3, 3}};
  int exp = 3;
  EXPECT_EQ(solution->maxPoints(points), exp);
  delete solution;
}

TEST_F(q149, sample_input02) {
  solution = new Solution();
  vector<vector<int>> points = {{1, 1}, {3, 2}, {5, 3}, {4, 1}, {2, 3}, {1, 4}};
  int exp = 4;
  EXPECT_EQ(solution->maxPoints(points), exp);
  delete solution;
}