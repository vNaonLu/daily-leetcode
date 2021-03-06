#include <array>
#include <gtest/gtest.h>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 1631.
 *       Path With Minimum Effort
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   You are a hiker preparing for an upcoming hike. You are given
 *   ‘heights’ , a 2D array of size ‘rows x columns’ , where
 *   ‘heights[row][col]’ represents the height of cell ‘(row, col)’ . You
 *   are situated in the top-left cell, ‘(0, 0)’ , and you hope to travel
 *   to the bottom-right cell, ‘(rows-1, columns-1)’ (i.e., “0-indexed” ).
 *   You can move “up” , “down” , “left” , or “right” , and you wish to
 *   find a route that requires the minimum “effort”
 *   A route's “effort” is the “maximum absolute difference”  “ ” in
 *   heights between two consecutive cells of the
 *   Return “the minimum “effort” required to travel from the top-left cell
 *   to the bottom-right cell.”
 *   
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘rows = heights.length’
 *   • ‘columns = heights[i].length’
 *   • ‘1 ≤ rows, columns ≤ 100’
 *   • ‘1 ≤ heights[i][j] ≤ 10⁶’
 *
 */

struct q1631 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   private:
    typedef pair<int, int> pos_t;
    int m, n;
    constexpr static array<pos_t, 4> dir{{{1, 0}, {0, 1}, {-1, 0}, {0, -1}}};

    bool is_valid(int x, int y) {
      return x >= 0 && x < m && y >= 0 && y < n;
    }

   public:
    int minimumEffortPath(vector<vector<int>> &heights) {
      priority_queue<pair<int, pos_t>,
                     vector<pair<int, pos_t>>,
                     greater<pair<int, pos_t>>>
          pq;
      m = heights.size();
      n = heights[0].size();

      vector<vector<int>> dist(m, vector<int>(n, numeric_limits<int>::max()));
      dist[0][0] = 0;

      pq.emplace(0, make_pair(0, 0));
      while (!pq.empty()) {
        auto [d, coord] = pq.top();
        auto &[x, y] = coord;
        pq.pop();

        if (dist[x][y] < d) {
          continue;
        }

        if (x == m - 1 && y == n - 1) {
          return d;
        }

        for (auto &[dx, dy] : dir) {
          auto nx = x + dx,
               ny = y + dy;

          if (is_valid(nx, ny)) {
            auto nd = max(abs(heights[x][y] - heights[nx][ny]), d);
            if (dist[nx][ny] > nd) {
              dist[nx][ny] = nd;
              pq.emplace(nd, make_pair(nx, ny));
            }
          }
        }
      }

      return -1;
    }
  };

  class Solution *solution;
};

TEST_F(q1631, sample_input01) {
  solution = new Solution();
  vector<vector<int>> heights = {{1, 2, 2}, {3, 8, 2}, {5, 3, 5}};
  int exp = 2;
  int act = solution->minimumEffortPath(heights);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q1631, sample_input02) {
  solution = new Solution();
  vector<vector<int>> heights = {{1, 2, 3}, {3, 8, 4}, {5, 3, 5}};
  int exp = 1;
  int act = solution->minimumEffortPath(heights);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q1631, sample_input03) {
  solution = new Solution();
  vector<vector<int>> heights = {{1, 2, 1, 1, 1}, {1, 2, 1, 2, 1}, {1, 2, 1, 2, 1}, {1, 2, 1, 2, 1}, {1, 1, 1, 2, 1}};
  int exp = 0;
  int act = solution->minimumEffortPath(heights);
  EXPECT_EQ(act, exp);
  delete solution;
}