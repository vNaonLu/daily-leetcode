
#ifndef LEETCODE_Q78_H__
#define LEETCODE_Q78_H__
#include <iostream>
#include <vector>

namespace l78 {
using namespace std;

/**
  * This file is generated by leetcode_add.py
  *
  * #78
  *     Subsets
  *
  *============================= Description =============================
  *
  *   Given an integer array ‘nums‘ of “unique” elements, return all
  *   possible subsets (the power set).
  *   
  *   The solution set “must not” contain duplicate subsets. Return the
  *   solution in “any order”.
  *
  * ============================= Constraints =============================
  *
  *   • ‘1 <= nums.length <= 10‘
  *   • ‘-10 <= nums[i] <= 10‘
  *   • All the numbers of ‘nums‘ are “unique” .
  *
*/

class Solution {
 public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;
    res.push_back({});
    for (const auto& n : nums) {
      int len = res.size();
      for (int i = 0; i < len; ++i) {
        vector<int> tmp = res[i];
        tmp.push_back(n);
        res.push_back(tmp);
      }
    }
    return res;
  }
};
}  // namespace l78

#endif