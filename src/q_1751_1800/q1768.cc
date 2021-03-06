#include <gtest/gtest.h>
#include <iostream>
#include <string>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 1768.
 *       Merge Strings Alternately
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   You are given two strings ‘word1’ and ‘word2’ . Merge the strings by
 *   adding letters in alternating order, starting with ‘word1’ . If a
 *   string is longer than the other, append the additional letters onto
 *   the end of the merged
 *   Return “the merged string.”
 *   
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤ word1.length, word2.length ≤ 100’
 *   • ‘word1’ and ‘word2’ consist of lowercase English letters.
 *
 */

struct q1768 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   public:
    string mergeAlternately(string word1, string word2) {
      string res;
      auto w1 = word1.begin(), w2 = word2.begin();
      while (w1 != word1.end() && w2 != word2.end()) {
        res.push_back(*(w1++));
        res.push_back(*(w2++));
      }
      while (w1 != word1.end()) {
        res.push_back(*(w1++));
      }
      while (w2 != word2.end()) {
        res.push_back(*(w2++));
      }

      return res;
    }
  };

  class Solution *solution;
};

TEST_F(q1768, sample_input01) {
  solution = new Solution();
  string word1 = "abc";
  string word2 = "pqr";
  string exp = "apbqcr";
  string act = solution->mergeAlternately(word1, word2);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q1768, sample_input02) {
  solution = new Solution();
  string word1 = "ab";
  string word2 = "pqrs";
  string exp = "apbqrs";
  string act = solution->mergeAlternately(word1, word2);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q1768, sample_input03) {
  solution = new Solution();
  string word1 = "abcd";
  string word2 = "pq";
  string exp = "apbqcd";
  string act = solution->mergeAlternately(word1, word2);
  EXPECT_EQ(act, exp);
  delete solution;
}