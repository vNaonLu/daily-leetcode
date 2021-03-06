#include <gtest/gtest.h>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 473.
 *      Matchsticks to Square
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   You are given an integer array ‘matchsticks’ where ‘matchsticks[i]’ is
 *   the length of the ‘iᵗʰ’ matchstick. You want to use “all the
 *   matchsticks” to make one square. You “should not break” any stick, but
 *   you can link them up, and each matchstick must be used “exactly one
 *   time”
 *   Return ‘true’ if you can make this square and ‘false’ otherwise.
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤ matchsticks.length ≤ 15’
 *   • ‘1 ≤ matchsticks[i] ≤ 10⁸’
 *
 */

struct q473 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
  private:
    map<pair<int, int>, bool> memo;
    vector<int> nums;
    int possible;

    bool helper(int mask, int side) {
      int total = 0,
          n = nums.size();

      auto k = make_pair(mask, side);
      for (int i = n - 1; i >= 0; --i) {
        if ((mask & (1 << i)) == 0) {
          total += nums[n - 1 - i];
        }
      }

      if (total > 0 && total % possible == 0) {
        ++side;
      }

      if (side == 3) {
        return true;
      }

      if (memo.count(k)) {
        return memo[k];
      }

      bool res = false;
      int c = total / possible,
          rem = possible * (c + 1) - total;

      for (int i = n - 1; i >= 0; --i) {
        if (nums[n - 1 - i] <= rem && (mask & (1 << i)) > 0) {
          if (helper(mask ^ (1 << i), side)) {
            res = true;
            break;
          }
        }
      }

      return memo[k] = res;
    }

  public:
    bool makesquare(vector<int> &matchsticks) {
      possible = accumulate(matchsticks.begin(), matchsticks.end(), 0);
      nums = move(matchsticks);

      if (possible == 0 || possible % 4 != 0) {

        return false;
      }
      possible /= 4;

      return helper((1 << nums.size()) - 1, 0);
    }
  };

  class Solution *solution;
};

TEST_F(q473, sample_input01) {
  solution = new Solution();
  vector<int> matchsticks = {1, 1, 2, 2, 2};
  bool exp = true;
  bool act = solution->makesquare(matchsticks);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q473, sample_input02) {
  solution = new Solution();
  vector<int> matchsticks = {3, 3, 3, 3, 4};
  bool exp = false;
  bool act = solution->makesquare(matchsticks);
  EXPECT_EQ(act, exp);
  delete solution;
}