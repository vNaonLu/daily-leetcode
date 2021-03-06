#include <gtest/gtest.h>
#include <iostream>
#include <string>

using namespace std;

/**
 * This file is generated by leetcode_add.py v1.0
 *
 * 151.
 *      Reverse Words in a String
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   Given an input string ‘s’ , reverse the order of the “words”
 *   A “word” is defined as a sequence of non-space characters. The “words”
 *   in ‘s’ will be separated by at least one
 *   Return “a string of the words in reverse order concatenated by a
 *   single space.”
 *    “Note” that ‘s’ may contain leading or trailing spaces or multiple
 *   spaces between two words. The returned string should only have a
 *   single space separating the words. Do not include any extra spaces.
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤ s.length ≤ 10⁴’
 *   • ‘s’ contains English letters (upper-case and lower-case), digits, and spaces ‘' '’ .
 *   • There is “at least one” word in ‘s’ .
 *
 */

struct q151 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   public:
    string reverseWords(string s) {
      string res;
      int length = 0;
      for (int i = s.size() - 1; i >= 0; --i) {
        if (s[i] != ' ') ++length;
        if (length > 0 && (s[i] == ' ' || i == 0)) {
          if (!res.empty()) res.push_back(' ');
          res += s.substr(s[i] == ' ' ? i + 1 : i, length);
          length = 0;
        }
      }
      return res;
    }
  };

  class Solution *solution;
};

TEST_F(q151, sample_input01) {
  solution = new Solution();
  string s = "the sky is blue";
  string exp = "blue is sky the";
  EXPECT_EQ(solution->reverseWords(s), exp);
  delete solution;
}

TEST_F(q151, sample_input02) {
  solution = new Solution();
  string s = "  hello world  ";
  string exp = "world hello";
  EXPECT_EQ(solution->reverseWords(s), exp);
  delete solution;
}

TEST_F(q151, sample_input03) {
  solution = new Solution();
  string s = "a good   example";
  string exp = "example good a";
  EXPECT_EQ(solution->reverseWords(s), exp);
  delete solution;
}

TEST_F(q151, sample_input04) {
  solution = new Solution();
  string s = "  Bob    Loves  Alice   ";
  string exp = "Alice Loves Bob";
  EXPECT_EQ(solution->reverseWords(s), exp);
  delete solution;
}

TEST_F(q151, sample_input05) {
  solution = new Solution();
  string s = "Alice does not even like bob";
  string exp = "bob like even not does Alice";
  EXPECT_EQ(solution->reverseWords(s), exp);
  delete solution;
}