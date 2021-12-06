
#ifndef Q1217_UNITTEST_H__
#define Q1217_UNITTEST_H__
#include <gtest/gtest.h>

#include "q1217.hpp"
using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 1217.
 *       Minimum Cost to Move Chips to The Same Position
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   We have ‘n’ chips, where the position of the ‘iᵗʰ’ chip is
 *   ‘position[i]’
 *   We need to move all the chips to “the same position” . In one step, we
 *   can change the position of the ‘iᵗʰ’ chip from ‘position[i]’
 *       -  ‘position[i] + 2’ or ‘position[i] - 2’ with ‘cost = 0’
 *       -  ‘position[i] + 1’ or ‘position[i] - 1’ with ‘cost = 1’
 *   Return “the minimum cost” needed to move all the chips to the same
 *   position.
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤ position.length ≤ 100’
 *   • ‘1 ≤ position[i] ≤ 10^9’
 *
 */

TEST(q1217, sample_input01) {
  l1217::Solution solver;
  vector<int> position = {1, 2, 3};
  int exp = 1;
  EXPECT_EQ(solver.minCostToMoveChips(position), exp);
}

TEST(q1217, sample_input02) {
  l1217::Solution solver;
  vector<int> position = {2, 2, 2, 3, 3};
  int exp = 2;
  EXPECT_EQ(solver.minCostToMoveChips(position), exp);
}

TEST(q1217, sample_input03) {
  l1217::Solution solver;
  vector<int> position = {1, 1000000000};
  int exp = 1;
  EXPECT_EQ(solver.minCostToMoveChips(position), exp);
}

#endif