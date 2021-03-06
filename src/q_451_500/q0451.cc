#include <gtest/gtest.h>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

/**
 * This file is generated by leetcode_add.py v1.0
 *
 * 451.
 *      Sort Characters By Frequency
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   Given a string ‘s’ , sort it in “decreasing order” based on the
 *   “frequency” of the characters. The “frequency” of a character is the
 *   number of times it appears in the
 *   Return “the sorted string” . If there are multiple answers, return
 *   “any of them” .
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤ s.length ≤ 5 × 10⁵’
 *   • ‘s’ consists of uppercase and lowercase English letters and digits.
 *
 */

struct q451 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   public:
    string frequencySort(string s) {
      string res;
      map<char, int> cnt;
      for (const auto &c : s) ++cnt[c];
      priority_queue<int> pq;
      for (const auto &it : cnt) pq.push(it.second);
      while (!pq.empty()) {
        int count = pq.top();
        pq.pop();
        for (const auto &it : cnt) {
          if (it.second == count) {
            while (count--)
              res.push_back(it.first);
            cnt.erase(it.first);
            break;
          }
        }
      }
      return res;
    }
  };

  class Solution *solution;
};

TEST_F(q451, sample_input01) {
  solution = new Solution();
  string s = "tree";
  string exp = "eert";
  EXPECT_EQ(solution->frequencySort(s), exp);
  delete solution;
}

TEST_F(q451, sample_input02) {
  solution = new Solution();
  string s = "cccaaa";
  string exp = "aaaccc";
  EXPECT_EQ(solution->frequencySort(s), exp);
  delete solution;
}

TEST_F(q451, sample_input03) {
  solution = new Solution();
  string s = "Aabb";
  string exp = "bbAa";
  EXPECT_EQ(solution->frequencySort(s), exp);
  delete solution;
}