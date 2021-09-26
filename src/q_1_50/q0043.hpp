
#ifndef LEETCODE_Q43_H__
#define LEETCODE_Q43_H__
#include <string>
#include <iostream>
#include <vector>

namespace l43 {
using namespace std;

/**
  * This file is generated by leetcode_add.py
  *
  * 43. Multiply Strings
  * Given two non-negative integers num1 and num2
  * represented as strings, return the product of num1
  * and num2 , also represented as a string.
  * “Note:” You must not use any built-in BigInteger
  * library or convert the inputs to integer
  * directly.
  *
  * Constraints:
  * -  1 <= num1.length, num2.length <= 200 
  * -  num1 and num2 consist of digits only.
  * - Both num1 and num2 do not contain any leading zero, except the number 0 itself.
  *
*/

class Solution {
 public:
  string multiply(string num1, string num2) {
    vector<int> ans(num1.size() + num2.size(), 0);
    int j = num2.size();
    while (--j >= 0) {
      int i = num1.size();
      while (--i >= 0) {
        int piv = i + j + 1;
        int val = (num2[j] - '0') * (num1[i] - '0');
        ans[piv] += val;
        ans[piv - 1] += ans[piv] / 10;
        ans[piv] %= 10;
      }
    }

    string res;
    for (const auto &n : ans) {
      if (!res.empty() || n != 0) {
        res.push_back(n + '0');
      }
    }
    return res.empty() ? "0" : res;
  }
};
}  // namespace l43

#endif