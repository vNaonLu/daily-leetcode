#include <gtest/gtest.h>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 1337.
 *       The K Weakest Rows in a Matrix
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   You are given an ‘m x n’ binary matrix ‘mat’ of ‘1’ 's (representing
 *   soldiers) and ‘0’ 's (representing civilians). The soldiers are
 *   positioned “in front” of the civilians. That is, all the ‘1’ 's will
 *   appear to the “left” of all the ‘0’ 's in each
 *   A row ‘i’ is “weaker” than a row ‘j’ if one of the following is
 *       - The number of soldiers in row ‘i’ is less than the number of
 *   soldiers in row ‘j’
 *       - Both rows have the same number of soldiers and ‘i < j’
 *   Return “the indices of the ” ‘k’ “ “weakest” rows in the matrix
 *   ordered from weakest to strongest” .
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘m = mat.length’
 *   • ‘n = mat[i].length’
 *   • ‘2 ≤ n, m ≤ 100’
 *   • ‘1 ≤ k ≤ m’
 *   • ‘matrix[i][j]’ is either 0 or 1.
 *
 */

struct q1337 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   public:
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k) {
      priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

      int row = 0;
      for (const auto &v : mat) {
        int l = 0, r = v.size() - 1;
        while (l <= r) {
          int mid = l + (r - l) / 2;
          if (v[mid] == 1) {
            l = mid + 1;
          } else {
            r = mid - 1;
          }
        }
        pq.emplace(l, row++);
      }
      vector<int> res;
      while (k-- && !pq.empty()) {
        res.emplace_back(pq.top().second);
        pq.pop();
      }

      return res;
    }
  };

  class Solution *solution;
};

TEST_F(q1337, sample_input01) {
  solution = new Solution();
  vector<vector<int>> mat = {{1, 1, 0, 0, 0}, {1, 1, 1, 1, 0}, {1, 0, 0, 0, 0}, {1, 1, 0, 0, 0}, {1, 1, 1, 1, 1}};
  vector<int> exp = {2, 0, 3};
  int k = 3;
  vector<int> act = solution->kWeakestRows(mat, k);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q1337, sample_input02) {
  solution = new Solution();
  vector<vector<int>> mat = {{1, 0, 0, 0}, {1, 1, 1, 1}, {1, 0, 0, 0}, {1, 0, 0, 0}};
  vector<int> exp = {0, 2};
  int k = 2;
  vector<int> act = solution->kWeakestRows(mat, k);
  EXPECT_EQ(act, exp);
  delete solution;
}