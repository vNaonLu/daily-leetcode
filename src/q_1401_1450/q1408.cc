#include <gtest/gtest.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 1408.
 *       String Matching in an Array
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   Given an array of string ‘words’ . Return all strings in ‘words’ which
 *   is substring of another word in “any”
 *   String ‘words[i]’ is substring of ‘words[j]’ ,ifcan be obtained
 *   removing some characters to left and/or right side of ‘words[j]’ .
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤ words.length ≤ 100’
 *   • ‘1 ≤ words[i].length ≤ 30’
 *   • ‘words[i]’ contains only lowercase English letters.
 *   • It's “guaranteed” that ‘words[i]’ will be unique.
 *
 */

struct q1408 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   public:
    vector<string> stringMatching(vector<string> &words) {
      sort(words.begin(), words.end(), [](auto &x, auto &y) {
        return x.size() == y.size() ? (x < y) : (x.size() < y.size());
      });
      vector<string> res;
      for (int i = 0; i < words.size(); ++i) {
        for (int j = i + 1; j < words.size(); ++j) {
          if (words[j].find(words[i]) != string::npos) {
            res.emplace_back(words[i]);
            break;
          }
        }
      }
      return res;
    }
  };

  class Solution *solution;
};

TEST_F(q1408, sample_input01) {
  solution = new Solution();
  vector<string> words = {"mass", "as", "hero", "superhero"};
  vector<string> exp = {"as", "hero"};
  vector<string> act = solution->stringMatching(words);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q1408, sample_input02) {
  solution = new Solution();
  vector<string> words = {"leetcode", "et", "code"};
  vector<string> exp = {"et", "code"};
  vector<string> act = solution->stringMatching(words);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q1408, sample_input03) {
  solution = new Solution();
  vector<string> words = {"blue", "green", "bu"};
  vector<string> exp = {};
  vector<string> act = solution->stringMatching(words);
  EXPECT_EQ(act, exp);
  delete solution;
}