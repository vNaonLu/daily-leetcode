#include <gtest/gtest.h>
#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 365.
 *      Water and Jug Problem
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   You are given two jugs with capacities ‘jug1Capacity’ and
 *   ‘jug2Capacity’ liters. There is an infinite amount of water supply
 *   available. Determine whether it is possible to measure exactly
 *   ‘targetCapacity’ liters using these two
 *   If ‘targetCapacity’ liters of water are measurable, you must have
 *   ‘targetCapacity’ liters of water contained “within one or both
 *   buckets” by the
 *   Operations
 *       - Fill any of the jugs with
 *       - Empty any of the
 *       - Pour water from one jug into another till the other jug is
 *   completely full, or the first jug itself is empty.
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤ jug1Capacity, jug2Capacity, targetCapacity ≤ 10⁶’
 *
 */

struct q365 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
      unordered_set<int> visit;
      queue<int> step;
      vector<int> dir = {jug1Capacity, -jug1Capacity, jug2Capacity, -jug2Capacity};

      step.emplace(0);
      visit.emplace(0);

      while (!step.empty()) {
        int water = step.front(); step.pop();

        for (auto &p : dir) {
          int x = water + p;

          if (x < 0 || x > jug1Capacity + jug2Capacity) continue;

          if (x == targetCapacity) return true;

          if (visit.emplace(x).second) {
            step.emplace(x);
          }
        }
      }

      return false;
    }
  };

  class Solution *solution;
};

TEST_F(q365, sample_input01) {
  solution = new Solution();
  int jug1Capacity = 3;
  int jug2Capacity = 5;
  int targetCapacity = 4;
  bool exp = true;
  bool act = solution->canMeasureWater(jug1Capacity, jug2Capacity, targetCapacity);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q365, sample_input02) {
  solution = new Solution();
  int jug1Capacity = 2;
  int jug2Capacity = 6;
  int targetCapacity = 5;
  bool exp = false;
  bool act = solution->canMeasureWater(jug1Capacity, jug2Capacity, targetCapacity);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q365, sample_input03) {
  solution = new Solution();
  int jug1Capacity = 1;
  int jug2Capacity = 2;
  int targetCapacity = 3;
  bool exp = true;
  bool act = solution->canMeasureWater(jug1Capacity, jug2Capacity, targetCapacity);
  EXPECT_EQ(act, exp);
  delete solution;
}