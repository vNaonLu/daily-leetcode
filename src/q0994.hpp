
#ifndef LEETCODE_Q994_H__
#define LEETCODE_Q994_H__
#include <iostream>
#include <queue>
#include <vector>

namespace l994 {
using namespace std;

/**
  * this file is generated by gquestion.py
  *
  * 994. Rotting Oranges
  *
  * You are given an m x n grid where each cell can
  * have one of three values:
  * -  0 representing an empty cell,
  * -  1 representing a fresh orange, or
  * -  2 representing a rotten orange.
  * Every minute, any fresh orange that is
  * “4-directionally adjacent“ to a rotten orange becomes
  * rotten.
  * Return the minimum number of minutes that must
  * elapse until no cell has a fresh orange . If this is
  * impossible, return -1 .
  *
  * Constraints:
  * -  m == grid.length 
  * -  n == grid[i].length 
  * -  1 <= m, n <= 10 
  * -  grid[i][j] is 0 , 1 , or 2 .
  *
*/
class Solution {
 private:
  vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

 public:
  int orangesRotting(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    queue<pair<int, int>> rot;
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (grid[i][j] == 2) rot.push({i * n + j, 0});

    int res = 0;

    while (!rot.empty()) {
      int idx = rot.front().first;
      int time = rot.front().second;
      res = max(res, time);
      rot.pop();

      int r = idx / n, c = idx % n;
      for (int i = 0; i < 4; ++i) {
        int nr = r + dir[i].first, nc = c + dir[i].second;
        if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
          if (grid[nr][nc] == 1) {
            rot.push({nr * n + nc, time + 1});
            grid[nr][nc] = 2;
          }
        }
      }
    }

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 1) return -1;
      }
    }

    return res;
  }
};
}  // namespace l994
#endif