
#ifndef LEETCODE_Q17_H__
#define LEETCODE_Q17_H__
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

namespace l17 {
using namespace std;

/**
  * This file is generated by leetcode_add.py
  *
  * 17.
  *     Letter Combinations of a Phone Number
  *
  * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
  *
  *   Given a string containing digits from ‘2-9’ inclusive, return all
  *   possible letter combinations that the number could represent. Return
  *   the answer in “any order”.
  *   
  *   A mapping of digit to letters (just like on the telephone buttons) is
  *   given below. Note that 1 does not map to any letters.
  *
  * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
  *
  *   • ‘0 ≤ digits.length ≤ 4’
  *   • ‘digits[i]’ is a digit in the range ‘['2', '9']’ .
  *
*/

class Solution {
 private:
  unordered_map<char, string> phone = {
      {'2', "abc"},
      {'3', "def"},
      {'4', "ghi"},
      {'5', "jkl"},
      {'6', "mno"},
      {'7', "pqrs"},
      {'8', "tuv"},
      {'9', "wxyz"}};
  void helper(vector<string> &r, string &s, string &cur, int beg = 0) {
    if (s.empty()) return;
    if (beg == s.size()) {
      r.push_back(cur);
    } else {
      auto characters = phone[s[beg]];
      for (const auto &c : characters) {
        cur.push_back(c);
        helper(r, s, cur, beg + 1);
        cur.pop_back();
      }
    }
  }

 public:
  vector<string> letterCombinations(string digits) {
    vector<string> res;
    string tmp = "";
    helper(res, digits, tmp);
    return res;
  }
};
}  // namespace l17

#endif