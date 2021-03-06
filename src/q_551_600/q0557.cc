#include <gtest/gtest.h>
#include <iostream>
#include <string>

using namespace std;

/**
 * This file is generated by leetcode_add.py v1.0
 *
 * 557.
 *      Reverse Words in a String III
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   Given a string ‘s’ , reverse the order of characters in each word
 *   within a sentence while still preserving whitespace and initial word
 *   order.
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤ s.length ≤ 5 × 10⁴’
 *   • ‘s’ contains printable “ASCII” characters.
 *   • ‘s’ does not contain any leading or trailing spaces.
 *   • There is “at least one” word in ‘s’ .
 *   • All the words in ‘s’ are separated by a single space.
 *
 */

struct q557 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   public:
    string reverseWords(string s) {
      int l = 0;
      for (int i = 1; i <= s.size(); ++i) {
        if ((i == s.size() || s[i] == ' ')) {
          reverse(s, l, i - 1);
          l = i;
        } else if (s[l] == ' ') {
          l = i;
        }
      }
      return s;
    }
   private:
    void reverse(string &s, int l, int r) {
      char c = ' ';
      while (l < r) {
        c = s[l];
        s[l++] = s[r];
        s[r--] = c;
      }
    }
  };

  class Solution *solution;
};

TEST_F(q557, sample_input01) {
  solution = new Solution();
  string s = "Let\"s take LeetCode contest";
  string exp = "s\"teL ekat edoCteeL tsetnoc";
  EXPECT_EQ(solution->reverseWords(s), exp);
  delete solution;
}

TEST_F(q557, sample_input02) {
  solution = new Solution();
  string s = "God Ding";
  string exp = "doG gniD";
  EXPECT_EQ(solution->reverseWords(s), exp);
  delete solution;
}