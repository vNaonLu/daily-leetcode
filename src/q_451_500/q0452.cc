#include <gtest/gtest.h>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 452.
 *      Minimum Number of Arrows to Burst Balloons
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   There are some spherical balloons taped onto a flat wall that
 *   represents the XY-plane. The balloons are represented as a 2D integer
 *   array ‘points’ where ‘points[i] = [xₛₜₐᵣₜ, xₑₙᵈ]’ denotes a balloon
 *   whose “horizontal diameter” stretches between ‘xₛₜₐᵣₜ’ and ‘xₑₙᵈ’ .
 *   You do not know the exact y-coordinates of the
 *   Arrows can be shot up “directly vertically” (in the positive
 *   y-direction) from different points along the x-axis. A balloon with
 *   ‘xₛₜₐᵣₜ’ and ‘xₑₙᵈ’ is “burst” by an arrow shot at ‘x’ if ‘xₛₜₐᵣₜ ≤ x
 *   ≤ xₑₙᵈ’ . There is “no limit” to the number of arrows that can be
 *   shot. A shot arrow keeps traveling up infinitely, bursting any
 *   balloons in its
 *   Given the array ‘points’ , return “the “minimum” number of arrows that
 *   must be shot to burst all balloons” .
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤ points.length ≤ 10⁵’
 *   • ‘points[i].length = 2’
 *   • ‘-2³¹ ≤ xₛₜₐᵣₜ < xₑₙᵈ ≤ 2³¹ - 1’
 *
 */

struct q452 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   private:
    using diameter_t = pair<int, int>;

   public:
    int findMinArrowShots(vector<vector<int>> &points) {
      if (points.empty()) return 0;
      priority_queue<diameter_t> pq;
      vector<int>                dp(points.size(), 0);

      for (const auto &v : points) {
        pq.emplace(v[0], v[1]);
      }

      dp.front() = 1;
      int  i = 1;
      auto range = pq.top(); pq.pop();
      while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        if (cur.second < range.first) {
          dp[i] = dp[i - 1] + 1;
          range = cur;
        } else {
          dp[i] = dp[i - 1];
          range.first  = min(range.first, cur.second);
          range.second = max(range.first, cur.second);
        }
        ++i;
      }
      return dp.back();
    }
  };

  class Solution *solution;
};

TEST_F(q452, sample_input01) {
  solution = new Solution();
  vector<vector<int>> points = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
  int exp = 2;
  int act = solution->findMinArrowShots(points);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q452, sample_input02) {
  solution = new Solution();
  vector<vector<int>> points = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};
  int exp = 4;
  int act = solution->findMinArrowShots(points);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q452, sample_input03) {
  solution = new Solution();
  vector<vector<int>> points = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
  int exp = 2;
  int act = solution->findMinArrowShots(points);
  EXPECT_EQ(act, exp);
  delete solution;
}