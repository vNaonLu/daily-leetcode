
#ifndef Q693_UNITTEST_H__
#define Q693_UNITTEST_H__
#include <gtest/gtest.h>

#include "q0693.hpp"
using namespace std;

/**
  * This file is generated by leetcode_add.py
  *
  * 693.
  *      Binary Number with Alternating Bits
  *
  * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
  *
  *   Given a positive integer, check whether it has alternating bits:
  *   namely, if two adjacent bits will always have different values.
  *
  * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
  *
  *   • ‘1 ≤ n ≤ 2³¹ - 1’
  *
*/

TEST(q693, sample_input01) {
  l693::Solution solver;
  int n = 5;
  bool exp = true;
  EXPECT_EQ(solver.hasAlternatingBits(n), exp);
}

TEST(q693, sample_input02) {
  l693::Solution solver;
  int n = 7;
  bool exp = false;
  EXPECT_EQ(solver.hasAlternatingBits(n), exp);
}

TEST(q693, sample_input03) {
  l693::Solution solver;
  int n = 11;
  bool exp = false;
  EXPECT_EQ(solver.hasAlternatingBits(n), exp);
}

TEST(q693, sample_input04) {
  l693::Solution solver;
  int n = 10;
  bool exp = true;
  EXPECT_EQ(solver.hasAlternatingBits(n), exp);
}

TEST(q693, sample_input05) {
  l693::Solution solver;
  int n = 3;
  bool exp = false;
  EXPECT_EQ(solver.hasAlternatingBits(n), exp);
}

TEST(q693, input01) {
  l693::Solution solver;
  int n = 4;
  bool exp = false;
  EXPECT_EQ(solver.hasAlternatingBits(n), exp);
}

#endif