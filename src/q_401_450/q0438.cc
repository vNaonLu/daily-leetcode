#include <gtest/gtest.h>
#include <iostream>
#include <leetcode/anyorder.hpp>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * This file is generated by leetcode_add.py v1.0
 *
 * 438.
 *      Find All Anagrams in a String
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   Given two strings ‘s’ and ‘p’ , return “an array of all the start
 *   indices of ” ‘p’ “'s anagrams in ” ‘s’ . You may return the answer in
 *   “any order”
 *   An “Anagram” is a word or phrase formed by rearranging the letters of
 *   a different word or phrase, typically using all the original letters
 *   exactly once.
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤ s.length, p.length ≤ 3 × 10⁴’
 *   • ‘s’ and ‘p’ consist of lowercase English letters.
 *
 */

struct q438 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   public:
    vector<int> findAnagrams(string s, string p) {
      vector<int> res;
      unordered_map<char, int> sc, pc;
      if (p.size() > s.size()) return res;
      for (int i = 0; i < p.size(); ++i) {
        ++sc[s[i]];
        ++pc[p[i]];
      }
      for (int i = 0; i < s.size() - p.size() + 1; ++i) {
        if (sc == pc) res.push_back(i);
        if (i + p.size() < s.size()) {
          --sc[s[i]];
          ++sc[s[i + p.size()]];
          if (!sc[s[i]]) sc.erase(s[i]);
        }
      }
      return res;
    }
  };

  class Solution *solution;
};

TEST_F(q438, sample_input01) {
  solution = new Solution();
  string s = "cbaebabacd";
  string p = "abc";
  vector<int> exp = {0, 6};
  // Try EXPECT_EQ_ANY_ORDER_RECURSIVE
  // if the element is also matched in any order.
  EXPECT_EQ_ANY_ORDER(solution->findAnagrams(s, p), exp);
  delete solution;
}

TEST_F(q438, sample_input02) {
  solution = new Solution();
  string s = "abab";
  string p = "ab";
  vector<int> exp = {0, 1, 2};
  // Try EXPECT_EQ_ANY_ORDER_RECURSIVE
  // if the element is also matched in any order.
  EXPECT_EQ_ANY_ORDER(solution->findAnagrams(s, p), exp);
  delete solution;
}