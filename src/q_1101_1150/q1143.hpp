
#ifndef LEETCODE_Q1143_H__
#define LEETCODE_Q1143_H__
#include <iostream>
#include <string>
#include <vector>

namespace l1143 {
using namespace std;

/**
  * This file is generated by leetcode_add.py
  *
  * 1143.
  *       Longest Common Subsequence
  *
  * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
  *
  *   Given two strings ‘text1’ and ‘text2’ , return “the length of their
  *   longest “common subsequence” . ” If there is no “common subsequence” ,
  *   return ‘0’.
  *   
  *   A “subsequence” of a string is a new string generated from the
  *   original string with some characters (can be none) deleted without
  *   changing the relative order of the remaining characters.
  *   
  *   - For example, ‘"ace"’ is a subsequence of ‘"abcde"’.
  *   
  *   A “common subsequence” of two strings is a subsequence that is common
  *   to both strings.
  *
  * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
  *
  *   • ‘1 ≤ text1.length, text2.length ≤ 1000’
  *   • ‘text1’ and ‘text2’ consist of only lowercase English characters.
  *
*/

class Solution {
 public:
  int longestCommonSubsequence(string text1, string text2) {
    int m = text1.size() + 1;
    int n = text2.size() + 1;
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        if (text1[i - 1] == text2[j - 1]) {
          dp[i][j] = 1 + dp[i - 1][j - 1];
        } else {
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    }
    return dp.back().back();
  }
};
}  // namespace l1143

#endif