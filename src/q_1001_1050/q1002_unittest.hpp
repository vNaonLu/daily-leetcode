
#ifndef Q1002_UNITTEST_H__
#define Q1002_UNITTEST_H__
#include <gtest/gtest.h>

#include <leetcode/anyorder.hpp>

#include "q1002.hpp"
using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 1002.
 *       Find Common Characters
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   Given a string array ‘words’ , return “an array of all characters that
 *   show up in all strings within the ” ‘words’ “ (including duplicates)”
 *   . You may return the answer in “any order” .
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤ words.length ≤ 100’
 *   • ‘1 ≤ words[i].length ≤ 100’
 *   • ‘words[i]’ consists of lowercase English letters.
 *
 */

TEST(q1002, sample_input01) {
  l1002::Solution solver;
  vector<string> words = {"bella", "label", "roller"};
  vector<string> exp = {"e", "l", "l"};
  // Try EXPECT_EQ_ANY_ORDER_RECURSIVE
  // if the element is also matched in any order.
  EXPECT_EQ_ANY_ORDER(solver.commonChars(words), exp);
}

TEST(q1002, sample_input02) {
  l1002::Solution solver;
  vector<string> words = {"cool", "lock", "cook"};
  vector<string> exp = {"c", "o"};
  // Try EXPECT_EQ_ANY_ORDER_RECURSIVE
  // if the element is also matched in any order.
  EXPECT_EQ_ANY_ORDER(solver.commonChars(words), exp);
}

#endif