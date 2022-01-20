#include <gtest/gtest.h>
#include <iostream>
#include <vector>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 875.
 *      Koko Eating Bananas
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   Koko loves to eat bananas. There are ‘n’ piles of bananas, the ‘iᵗʰ’
 *   pile has ‘piles[i]’ bananas. The guards have gone and will come back
 *   in ‘h’
 *   Koko can decide her bananas-per-hour eating speed of ‘k’ . Each hour,
 *   she chooses some pile of bananas and eats ‘k’ bananas from that pile.
 *   If the pile has less than ‘k’ bananas, she eats all of them instead
 *   and will not eat any more bananas during this
 *   Koko likes to eat slowly but still wants to finish eating all the
 *   bananas before the guards
 *   Return “the minimum integer” ‘k’ “such that she can eat all the
 *   bananas within” ‘h’ “hours” .
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤ piles.length ≤ 10⁴’
 *   • ‘piles.length ≤ h ≤ 10⁹’
 *   • ‘1 ≤ piles[i] ≤ 10⁹’
 *
 */

struct q875 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   public:
    int minEatingSpeed(vector<int>& piles, int h) {
      int left = 1, right = *max_element(piles.begin(), piles.end());

      while (left < right) {
        int mid = left + (right - left) / 2;
        int spent = 0;

        for (int pile : piles) {
          spent += pile / mid + (pile % mid == 0 ? 0 : 1);
        }

        if (spent <= h) {
          right = mid;
        } else {
          left = mid + 1;
        }
      }

      return right;
    }
  };

  class Solution *solution;
};

TEST_F(q875, sample_input01) {
  solution = new Solution();
  vector<int> piles = {3, 6, 7, 11};
  int h = 8;
  int exp = 4;
  int act = solution->minEatingSpeed(piles, h);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q875, sample_input02) {
  solution = new Solution();
  vector<int> piles = {30, 11, 23, 4, 20};
  int h = 5;
  int exp = 30;
  int act = solution->minEatingSpeed(piles, h);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q875, sample_input03) {
  solution = new Solution();
  vector<int> piles = {30, 11, 23, 4, 20};
  int h = 6;
  int exp = 23;
  int act = solution->minEatingSpeed(piles, h);
  EXPECT_EQ(act, exp);
  delete solution;
}