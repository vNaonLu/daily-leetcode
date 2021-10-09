
#ifndef Q149_UNITTEST_H__
#define Q149_UNITTEST_H__
#include <gtest/gtest.h>

#include "q0149.hpp"
using namespace std;

/**
  * This file is generated by leetcode_add.py
  *
  * 149.
  *      Max Points on a Line
  *
  * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
  *
  *   Given an array of ‘points’ where ‘points[i] = [xᵢ, yᵢ]’ represents a
  *   point on the “X-Y” plane, return “the maximum number of points that
  *   lie on the same straight line”.
  *
  * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
  *
  *   • ‘1 ≤ points.length ≤ 300’
  *   • ‘points[i].length = 2’
  *   • ‘-10⁴ ≤ xᵢ, yᵢ ≤ 10⁴’
  *   • All the ‘points’ are “unique” .
  *
*/

TEST(q149, sample_input01) {
  l149::Solution solver;
  vector<vector<int>> points = {{1, 1}, {2, 2}, {3, 3}};
  int exp = 3;
  EXPECT_EQ(solver.maxPoints(points), exp);
}

TEST(q149, sample_input02) {
  l149::Solution solver;
  vector<vector<int>> points = {{1, 1}, {3, 2}, {5, 3}, {4, 1}, {2, 3}, {1, 4}};
  int exp = 4;
  EXPECT_EQ(solver.maxPoints(points), exp);
}

#endif