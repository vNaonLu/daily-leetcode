
#ifndef LEETCODE_Q1822_H__
#define LEETCODE_Q1822_H__
#include <iostream>
#include <vector>

namespace l1822 {
using namespace std;

/**
  * This file is generated by leetcode_add.py
  *
  * 1822.
  *       Sign of the Product of an Array
  *
  * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
  *
  *   There is a function ‘signFunc(x)’ that.
  *   
  *   - ‘1’ if ‘x’ is positive.
  *   
  *   - ‘-1’ if ‘x’ is negative.
  *   
  *   - ‘0’ if ‘x’ is equal to ‘0’.
  *   
  *   You are given an integer array ‘nums’ . Let ‘product’ be the product
  *   of all values in the array ‘nums’.
  *   
  *   Return ‘signFunc(product)’.
  *
  * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
  *
  *   • ‘1 ≤ nums.length ≤ 1000’
  *   • ‘-100 ≤ nums[i] ≤ 100’
  *
*/

class Solution {
 public:
  int arraySign(vector<int>& nums) {
    bool res = true;
    for (const auto& x : nums) {
      if (x < 0)
        res = !res;
      else if (x == 0)
        return 0;
    }
    return res ? 1 : -1;
  }
};
}  // namespace l1822

#endif