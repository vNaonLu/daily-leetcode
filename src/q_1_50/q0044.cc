#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 44.
 *     Wildcard Matching
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   Given an input string ( ‘s’ ) and a pattern ( ‘p’ ), implement
 *   wildcard pattern matching with support for ‘'?'’ and ‘'×'’
 *       -  ‘'?'’ Matches any single
 *       -  ‘'×'’ Matches any sequence of characters (including the empty
 *   The matching should cover the “entire” input string (not partial).
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘0 ≤ s.length, p.length ≤ 2000’
 *   • ‘s’ contains only lowercase English letters.
 *   • ‘p’ contains only lowercase English letters, ‘'?'’ or ‘'×'’ .
 *
 */

struct q44 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   public:
    bool isMatch(string s, string p) {
      int sn = s.size(), pn = p.size();
      vector<vector<int>> dp(sn + 1, vector<int>(pn + 1, 0));
      dp[0][0] = 1;
      for (int i = 1; i < pn + 1; i++)
        dp[0][i] = p[i - 1] == '*' ? dp[0][i - 1] : 0;

      for (int i = 1; i < sn + 1; i++) {
        for (int j = 1; j < pn + 1; j++) {
          dp[i][j] = p[j - 1] == '*' ? (dp[i - 1][j] || dp[i][j - 1]) : ((s[i - 1] == p[j - 1] || p[j - 1] == '?') && dp[i - 1][j - 1]);
        }
      }
      return dp[sn][pn];
    }
  };

  class Solution *solution;
};

TEST_F(q44, sample_input01) {
  solution = new Solution();
  string s = "aa";
  string p = "a";
  bool exp = false;
  bool act = solution->isMatch(s, p);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q44, sample_input02) {
  solution = new Solution();
  string s = "aa";
  string p = "*";
  bool exp = true;
  bool act = solution->isMatch(s, p);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q44, sample_input03) {
  solution = new Solution();
  string s = "cb";
  string p = "?a";
  bool exp = false;
  bool act = solution->isMatch(s, p);
  EXPECT_EQ(act, exp);
  delete solution;
}