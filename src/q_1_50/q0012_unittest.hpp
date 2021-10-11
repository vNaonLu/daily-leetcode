
#ifndef Q12_UNITTEST_H__
#define Q12_UNITTEST_H__
#include <gtest/gtest.h>

#include "q0012.hpp"
using namespace std;

/**
  * This file is generated by leetcode_add.py
  *
  * 12.
  *     Integer to Roman
  *
  * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
  *
  *   Roman numerals are represented by seven different symbols: ‘I’ , ‘V’ ,
  *   ‘X’ , ‘L’ , ‘C’ , ‘D’ and ‘M’.
  *   
  *   “Symbol”  “Value”.
  *   
  *   I.
  *   
  *   V.
  *   
  *   X.
  *   
  *   L.
  *   
  *   C.
  *   
  *   D.
  *   
  *   M.
  *   
  *   For example, ‘2’ is written as ‘II’ in Roman numeral, just two
  *   one&#39;s added together. ‘12’ is written as ‘XII’ , which is simply
  *   ‘X + II’ . The number ‘27’ is written as ‘XXVII’ , which is ‘XX + V +
  *   II’.
  *   
  *   Roman numerals are usually written largest to smallest from left to
  *   right. However, the numeral for four is not ‘IIII’ . Instead, the
  *   number four is written as ‘IV’ . Because the one is before the five we
  *   subtract it making four. The same principle applies to the number
  *   nine, which is written as ‘IX’ . There are six instances where
  *   subtraction is.
  *   
  *   - ‘I’ can be placed before ‘V’ (5) and ‘X’ (10) to make 4 and 9.
  *   
  *   - ‘X’ can be placed before ‘L’ (50) and ‘C’ (100) to make 40 and 90.
  *   
  *   - ‘C’ can be placed before ‘D’ (500) and ‘M’ (1000) to make 400 and
  *   900.
  *   
  *   Given an integer, convert it to a roman numeral.
  *
  * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
  *
  *   • ‘1 ≤ num ≤ 3999’
  *
*/

TEST(q12, sample_input01) {
  l12::Solution solver;
  int num = 3;
  string exp = "III";
  EXPECT_EQ(solver.intToRoman(num), exp);
}

TEST(q12, sample_input02) {
  l12::Solution solver;
  int num = 4;
  string exp = "IV";
  EXPECT_EQ(solver.intToRoman(num), exp);
}

TEST(q12, sample_input03) {
  l12::Solution solver;
  int num = 9;
  string exp = "IX";
  EXPECT_EQ(solver.intToRoman(num), exp);
}

TEST(q12, sample_input04) {
  l12::Solution solver;
  int num = 58;
  string exp = "LVIII";
  EXPECT_EQ(solver.intToRoman(num), exp);
}

TEST(q12, sample_input05) {
  l12::Solution solver;
  int num = 1994;
  string exp = "MCMXCIV";
  EXPECT_EQ(solver.intToRoman(num), exp);
}

#endif