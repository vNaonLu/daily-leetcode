#include <gtest/gtest.h>
#include <iostream>
#include <string>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 2042.
 *       Check if Numbers Are Ascending in a Sentence
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   A sentence is a list of “tokens” separated by a “single” space with no
 *   leading or trailing spaces. Every token is either a “positive number”
 *   consisting of digits ‘0-9’ with no leading zeros, or a “word”
 *   consisting of lowercase English
 *       - For example, ‘'a puppy has 2 eyes 4 legs'’ is a sentence with
 *   seven tokens: ‘'2'’ and ‘'4'’ are numbers and the other tokens such as
 *   ‘'puppy'’ are
 *   Given a string ‘s’ representing a sentence, you need to check if “all”
 *   the numbers in ‘s’ are “strictly increasing” from left to right (i.e.,
 *   other than the last number, “each” number is “strictly smaller” than
 *   the number on its “right” in ‘s’
 *   Return ‘true’ “ if so, or ” ‘false’ “ otherwise” .
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘3 ≤ s.length ≤ 200’
 *   • ‘s’ consists of lowercase English letters, spaces, and digits from ‘0’ to ‘9’ , inclusive.
 *   • The number of tokens in ‘s’ is between ‘2’ and ‘100’ , inclusive.
 *   • The tokens in ‘s’ are separated by a single space.
 *   • There are at least “two” numbers in ‘s’ .
 *   • Each number in ‘s’ is a “positive” number “less” than ‘100’ , with no leading zeros.
 *   • ‘s’ contains no leading or trailing spaces.
 *
 */

struct q2042 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   public:
    bool areNumbersAscending(string s) {
      int current_num = -1;
      int maximum = -1;
      for (const auto &c : s) {
        if (isdigit(c)) {
          if (current_num > 0) {
            current_num *= 10;
            current_num += c - '0';
          } else {
            current_num = c - '0';
          }
        } else if (current_num > 0) {
          if (current_num <= maximum) return false;
          maximum = current_num;
          current_num = -1;
        }
      }
      return current_num == -1 ? true : current_num > maximum;
    }
  };

  class Solution *solution;
};

TEST_F(q2042, sample_input01) {
  solution = new Solution();
  string s = "1 box has 3 blue 4 red 6 green and 12 yellow marbles";
  bool exp = true;
  bool act = solution->areNumbersAscending(s);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q2042, sample_input02) {
  solution = new Solution();
  string s = "hello world 5 x 5";
  bool exp = false;
  bool act = solution->areNumbersAscending(s);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q2042, sample_input03) {
  solution = new Solution();
  string s = "sunset is at 7 51 pm overnight lows will be in the low 50 and 60 s";
  bool exp = false;
  bool act = solution->areNumbersAscending(s);
  EXPECT_EQ(act, exp);
  delete solution;
}