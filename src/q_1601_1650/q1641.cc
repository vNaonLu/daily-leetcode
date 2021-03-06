#include <gtest/gtest.h>
#include <iostream>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 1641.
 *       Count Sorted Vowel Strings
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   Given an integer ‘n’ , return “the number of strings of length ” ‘n’ “
 *   that consist only of vowels (” ‘a’ “, ” ‘e’ “, ” ‘i’ “, ” ‘o’ “, ” ‘u’
 *   “) and are “lexicographically sorted” .”
 *   A string ‘s’ is “lexicographically sorted” if for all valid ‘i’ ,
 *   ‘s[i]’ is the same as or comes before ‘s[i+1]’ in the alphabet.
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤ n ≤ 50’
 *
 */

struct q1641 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   public:
    int countVowelStrings(int n) {
      
      return (n + 4) * (n + 3) * (n + 2) * (n + 1) / 24;
    }
  };

  class Solution *solution;
};

TEST_F(q1641, sample_input01) {
  solution = new Solution();
  int n = 1;
  int exp = 5;
  int act = solution->countVowelStrings(n);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q1641, sample_input02) {
  solution = new Solution();
  int n = 2;
  int exp = 15;
  int act = solution->countVowelStrings(n);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q1641, sample_input03) {
  solution = new Solution();
  int n = 33;
  int exp = 66045;
  int act = solution->countVowelStrings(n);
  EXPECT_EQ(act, exp);
  delete solution;
}