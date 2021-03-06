#include <gtest/gtest.h>
#include <iostream>
#include <vector>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 989.
 *      Add to Array-Form of Integer
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   The “array-form” of an integer ‘num’ is an array representing its
 *   digits in left to right
 *       - For example, for ‘num = 1321’ , the array form is ‘[1,3,2,1]’
 *   Given ‘num’ , the “array-form” of an integer, and an integer ‘k’ ,
 *   return “the “array-form” of the integer” ‘num + k’ .
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤ num.length ≤ 10⁴’
 *   • ‘0 ≤ num[i] ≤ 9’
 *   • ‘num’ does not contain any leading zeros except for the zero itself.
 *   • ‘1 ≤ k ≤ 10⁴’
 *
 */

struct q989 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
      vector<int> res;
      int         carry = 0;
      auto        it = num.rbegin();

      while (k > 0 && it != num.rend()) {
        res.emplace_back(k % 10 + *it + carry);
        carry = res.back() / 10;
        res.back() %= 10;

        k /= 10;
        ++it;
      }

      while (k > 0) {
        res.emplace_back(k % 10 + carry);
        carry = res.back() / 10;
        res.back() %= 10;

        k /= 10;
      }

      while (it != num.rend()) {
        res.emplace_back(*it + carry);
        carry = res.back() / 10;
        res.back() %= 10;

        ++it;
      }

      if (carry > 0) {
        res.emplace_back(carry);
      }

      reverse(res.begin(), res.end());
      return res;
    }
  };

  class Solution *solution;
};

TEST_F(q989, sample_input01) {
  solution = new Solution();
  vector<int> num = {1, 2, 0, 0};
  int k = 34;
  vector<int> exp = {1, 2, 3, 4};
  vector<int> act = solution->addToArrayForm(num, k);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q989, sample_input02) {
  solution = new Solution();
  vector<int> num = {2, 7, 4};
  int k = 181;
  vector<int> exp = {4, 5, 5};
  vector<int> act = solution->addToArrayForm(num, k);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q989, sample_input03) {
  solution = new Solution();
  vector<int> num = {2, 1, 5};
  int k = 806;
  vector<int> exp = {1, 0, 2, 1};
  vector<int> act = solution->addToArrayForm(num, k);
  EXPECT_EQ(act, exp);
  delete solution;
}