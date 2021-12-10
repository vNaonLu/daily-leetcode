#include <gtest/gtest.h>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/**
 * This file is generated by leetcode_add.py v1.0
 *
 * 841.
 *      Keys and Rooms
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   There are ‘n’ rooms labeled from ‘0’ to ‘n - 1’ and all the rooms are
 *   locked except for room ‘0’ . Your goal is to visit all the rooms.
 *   However, you cannot enter a locked room without having its
 *   When you visit a room, you may find a set of “distinct keys” in it.
 *   Each key has a number on it, denoting which room it unlocks, and you
 *   can take all of them with you to unlock the other
 *   Given an array ‘rooms’ where ‘rooms[i]’ is the set of keys that you
 *   can obtain if you visited room ‘i’ , return ‘true’ “if you can visit
 *   “all” the rooms, or” ‘false’ “otherwise” .
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘n = rooms.length’
 *   • ‘2 ≤ n ≤ 1000’
 *   • ‘0 ≤ rooms[i].length ≤ 1000’
 *   • ‘1 ≤ sum(rooms[i].length) ≤ 3000’
 *   • ‘0 ≤ rooms[i][j] < n’
 *   • All the values of ‘rooms[i]’ are “unique” .
 *
 */

struct q841 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
      int n = rooms.size();
      stack<vector<int>> keys;
      vector<int> reachable(n, false);
      reachable[0] = true;
      keys.push(rooms[0]);
      while (!keys.empty()) {
        auto rms = keys.top();
        keys.pop();
        for (auto it = rms.begin(); it != rms.end(); ++it) {
          if (!reachable[*it]) {
            reachable[*it] = true;
            keys.push(rooms[*it]);
          }
        }
      }
      for (const auto& r : reachable)
        if (!r) return false;
      return true;
    }
  };

  class Solution *solution;
};

TEST_F(q841, sample_input01) {
  solution = new Solution();
  vector<vector<int>> rooms = {{1}, {2}, {3}, {}};
  bool exp = true;
  EXPECT_EQ(solution->canVisitAllRooms(rooms), exp);
  delete solution;
}

TEST_F(q841, sample_input02) {
  solution = new Solution();
  vector<vector<int>> rooms = {{1, 3}, {3, 0, 1}, {2}, {0}};
  bool exp = false;
  EXPECT_EQ(solution->canVisitAllRooms(rooms), exp);
  delete solution;
}