
#ifndef Q122_UNITTEST_H__
#define Q122_UNITTEST_H__
#include <gtest/gtest.h>

#include "q0122.hpp"
using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 122.
 *      Best Time to Buy and Sell Stock II
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   You are given an integer array ‘prices’ where ‘prices[i]’ is the price
 *   of a given stock on the ‘iᵗʰ’
 *   On each day, you may decide to buy and/or sell the stock. You can only
 *   hold “at most one” share of the stock at any time. However, you can
 *   buy it then immediately sell it on the “same day”
 *   Find and return “the “maximum” profit you can achieve” .
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤ prices.length ≤ 3 × 10⁴’
 *   • ‘0 ≤ prices[i] ≤ 10⁴’
 *
 */

TEST(q122, sample_input01) {
  l122::Solution solver;
  vector<int> prices = {7, 1, 5, 3, 6, 4};
  int exp = 7;
  EXPECT_EQ(solver.maxProfit(prices), exp);
}

TEST(q122, sample_input02) {
  l122::Solution solver;
  vector<int> prices = {1, 2, 3, 4, 5};
  int exp = 4;
  EXPECT_EQ(solver.maxProfit(prices), exp);
}

TEST(q122, sample_input03) {
  l122::Solution solver;
  vector<int> prices = {7, 6, 4, 3, 1};
  int exp = 0;
  EXPECT_EQ(solver.maxProfit(prices), exp);
}

#endif