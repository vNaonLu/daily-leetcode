#include <gtest/gtest.h>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 1423.
 *       Maximum Points You Can Obtain from Cards
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   There are several cards “arranged in a row” , and each card has an
 *   associated number of points. The points are given in the integer array
 *   ‘cardPoints’
 *   In one step, you can take one card from the beginning or from the end
 *   of the row. You have to take exactly ‘k’
 *   Your score is the sum of the points of the cards you have
 *   Given the integer array ‘cardPoints’ and the integer ‘k’ , return the
 *   “maximum score” you can obtain.
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤ cardPoints.length ≤ 10⁵’
 *   • ‘1 ≤ cardPoints[i] ≤ 10⁴’
 *   • ‘1 ≤ k ≤ cardPoints.length’
 *
 */

struct q1423 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
  public:
    int maxScore(vector<int> &cardPoints, int k) {
      int res = accumulate(cardPoints.begin(), cardPoints.begin() + k, 0);
      int curr = res,
          l = k, r = cardPoints.size() - 1;

      while (l) {
        curr -= cardPoints[l - 1];
        curr += cardPoints[r];
        res = max(curr, res);

        --l;
        --r;
      }

      return res;
    }
  };

  class Solution *solution;
};

TEST_F(q1423, sample_input01) {
  solution = new Solution();
  vector<int> cardPoints = {1, 2, 3, 4, 5, 6, 1};
  int k = 3;
  int exp = 12;
  int act = solution->maxScore(cardPoints, k);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q1423, sample_input02) {
  solution = new Solution();
  vector<int> cardPoints = {2, 2, 2};
  int k = 2;
  int exp = 4;
  int act = solution->maxScore(cardPoints, k);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q1423, sample_input03) {
  solution = new Solution();
  vector<int> cardPoints = {9, 7, 7, 9, 7, 7, 9};
  int k = 7;
  int exp = 55;
  int act = solution->maxScore(cardPoints, k);
  EXPECT_EQ(act, exp);
  delete solution;
}