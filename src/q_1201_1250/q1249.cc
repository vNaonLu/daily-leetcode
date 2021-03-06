#include <gtest/gtest.h>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

/**
 * This file is generated by leetcode_add.py v1.0
 *
 * 1249.
 *       Minimum Remove to Make Valid Parentheses
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   Given a string <font face="monospace">s</font> of ‘'('’ , ‘')'’ and
 *   lowercase English
 *   Your task is to remove the minimum number of parentheses ( ‘'('’ or
 *   ‘')'’ , in any positions ) so that the resulting “parentheses string”
 *   is valid and return “any” valid
 *   Formally, a “parentheses string” is valid if and only
 *       - It is the empty string, contains only lowercase characters,
 *       - It can be written as ‘AB’ ( ‘A’ concatenated with ‘B’ ), where
 *   ‘A’ and ‘B’ are valid strings,
 *       - It can be written as ‘(A)’ , where ‘A’ is a valid string.
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤ s.length ≤ 10⁵’
 *   • ‘s[i]’ is either ‘'('’ , ‘')'’ , or lowercase English letter ‘.’
 *
 */

struct q1249 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   public:
    string minRemoveToMakeValid(string s) {
      string res;
      stack<int> left_parentheses;
      set<int> removes;
      for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(') {
          left_parentheses.push(i);
        } else if (s[i] == ')') {
          if (left_parentheses.empty()) {
            removes.insert(i);
          } else {
            left_parentheses.pop();
          }
        }
      }
      while (!left_parentheses.empty()) {
        removes.insert(left_parentheses.top());
        left_parentheses.pop();
      }
      for (int i = 0; i < s.size(); ++i) {
        if (removes.count(i)) continue;
        res.push_back(s[i]);
      }
      return res;
    }
  };

  class Solution *solution;
};

TEST_F(q1249, sample_input01) {
  solution = new Solution();
  string s = "lee(t(c)o)de)";
  string exp = "lee(t(c)o)de";
  EXPECT_EQ(solution->minRemoveToMakeValid(s), exp);
  delete solution;
}

TEST_F(q1249, sample_input02) {
  solution = new Solution();
  string s = "a)b(c)d";
  string exp = "ab(c)d";
  EXPECT_EQ(solution->minRemoveToMakeValid(s), exp);
  delete solution;
}

TEST_F(q1249, sample_input03) {
  solution = new Solution();
  string s = "))((";
  string exp = "";
  EXPECT_EQ(solution->minRemoveToMakeValid(s), exp);
  delete solution;
}

TEST_F(q1249, sample_input04) {
  solution = new Solution();
  string s = "(a(b(c)d)";
  string exp = "a(b(c)d)";
  EXPECT_EQ(solution->minRemoveToMakeValid(s), exp);
  delete solution;
}