
#ifndef Q2011_UNITTEST_H__
#define Q2011_UNITTEST_H__
#include <gtest/gtest.h>

#include "q2011.hpp"
using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 2011.
 *       Final Value of Variable After Performing Operations
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   There is a programming language with only “four” operations and “one”
 *   variable ‘X’
 *       -  ‘++X’ and ‘X++’ “increments” the value of the variable ‘X’ by
 *   ‘1’
 *       -  ‘--X’ and ‘X--’ “decrements” the value of the variable ‘X’ by
 *   ‘1’
 *   Initially, the value of ‘X’ is ‘0’
 *   Given an array of strings ‘operations’ containing a list of
 *   operations, return “the “final ” value of ” ‘X’ “after performing all
 *   the operations” .
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤ operations.length ≤ 100’
 *   • ‘operations[i]’ will be either ‘'++X'’ , ‘'X++'’ , ‘'--X'’ , or ‘'X--'’ .
 *
 */

TEST(q2011, sample_input01) {
  l2011::Solution solver;
  vector<string> operations = {"--X", "X++", "X++"};
  int exp = 1;
  EXPECT_EQ(solver.finalValueAfterOperations(operations), exp);
}

TEST(q2011, sample_input02) {
  l2011::Solution solver;
  vector<string> operations = {"++X", "++X", "X++"};
  int exp = 3;
  EXPECT_EQ(solver.finalValueAfterOperations(operations), exp);
}

TEST(q2011, sample_input03) {
  l2011::Solution solver;
  vector<string> operations = {"X++", "++X", "--X", "X--"};
  int exp = 0;
  EXPECT_EQ(solver.finalValueAfterOperations(operations), exp);
}

#endif