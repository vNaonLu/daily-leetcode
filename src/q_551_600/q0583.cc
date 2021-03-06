#include <gtest/gtest.h>
#include <iostream>
#include <string>

using namespace std;

/**
 * This file is generated by leetcode_add.py v1.0
 *
 * 583.
 *      Delete Operation for Two Strings
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   Given two strings ‘word1’ and ‘word2’ , return “the minimum number of
 *   “steps” required to make” ‘word1’ “and” ‘word2’ “the same”
 *   In one “step” , you can delete exactly one character in either string.
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤ word1.length, word2.length ≤ 500’
 *   • ‘word1’ and ‘word2’ consist of only lowercase English letters.
 *
 */

struct q583 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   public:
    int minDistance(string word1, string word2) {
      int m = word1.size() + 1,
          n = word2.size() + 1;
      vector<vector<int>> dp(m, vector<int>(n, 0));
      for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
          if(word1[i-1] == word2[j-1]){
            dp[i][j] = max(dp[i][j], 1 + dp[i - 1][j - 1]);
          }
        }
      }
      int maxlen = dp.back().back();
      return word1.size() - maxlen + word2.size() - maxlen;
    }
  };

  class Solution *solution;
};

TEST_F(q583, sample_input01) {
  solution = new Solution();
  string word1 = "sea";
  string word2 = "eat";
  int exp = 2;
  EXPECT_EQ(solution->minDistance(word1, word2), exp);
  delete solution;
}

TEST_F(q583, sample_input02) {
  solution = new Solution();
  string word1 = "leetcode";
  string word2 = "etco";
  int exp = 4;
  EXPECT_EQ(solution->minDistance(word1, word2), exp);
  delete solution;
}