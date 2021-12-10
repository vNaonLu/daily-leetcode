#include <gtest/gtest.h>
#include <iostream>
#include <leetcode/anyorder.hpp>
#include <string>
#include <vector>

using namespace std;

/**
 * This file is generated by leetcode_add.py v1.0
 *
 * 49.
 *     Group Anagrams
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   Given an array of strings ‘strs’ , group “the anagrams” together. You
 *   can return the answer in “any order”
 *   An “Anagram” is a word or phrase formed by rearranging the letters of
 *   a different word or phrase, typically using all the original letters
 *   exactly once.
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤ strs.length ≤ 10⁴’
 *   • ‘0 ≤ strs[i].length ≤ 100’
 *   • ‘strs[i]’ consists of lowercase English letters.
 *
 */

struct q49 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      map<vector<char>, vector<string>> mapping;
      for (const auto& s : strs) {
        vector<char> key(s.begin(), s.end());
        sort(key.begin(), key.end());
        mapping[key].push_back(s);
      }
      vector<vector<string>> res;
      for (auto it = mapping.begin(); it != mapping.end(); ++it) {
        res.push_back(it->second);
      }
      return res;
    }
  };

  class Solution *solution;
};

TEST_F(q49, sample_input01) {
  solution = new Solution();
  vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
  vector<vector<string>> exp = {{"bat"}, {"nat", "tan"}, {"ate", "eat", "tea"}};
  // Try EXPECT_EQ_ANY_ORDER_RECURSIVE
  // if the element is also matched in any order.
  EXPECT_EQ_ANY_ORDER_RECURSIVE(solution->groupAnagrams(strs), exp);
  delete solution;
}

TEST_F(q49, sample_input02) {
  solution = new Solution();
  vector<string> strs = {""};
  vector<vector<string>> exp = {{""}};
  // Try EXPECT_EQ_ANY_ORDER_RECURSIVE
  // if the element is also matched in any order.
  EXPECT_EQ_ANY_ORDER_RECURSIVE(solution->groupAnagrams(strs), exp);
  delete solution;
}

TEST_F(q49, sample_input03) {
  solution = new Solution();
  vector<string> strs = {"a"};
  vector<vector<string>> exp = {{"a"}};
  // Try EXPECT_EQ_ANY_ORDER_RECURSIVE
  // if the element is also matched in any order.
  EXPECT_EQ_ANY_ORDER_RECURSIVE(solution->groupAnagrams(strs), exp);
  delete solution;
}