
#ifndef LEETCODE_Q75_H__
#define LEETCODE_Q75_H__
#include <algorithm>
#include <iostream>
#include <vector>

namespace l75 {
using namespace std;

/**
 * this file is generated by gquestion.py
 *
 * 75. Sort Colors
 *
 * Given an array nums with n objects colored red,
 * white, or blue, sort them “<a
 * href="https://en.wikipedia.org/wiki/In-place_algorithm"
 * target="_blank">in-place</a>“ so that objects of the same color
 * are adjacent, with the colors in the order red,
 * white, and blue.
 * We will use the integers 0 , 1 , and 2 to
 * represent the color red, white, and blue, respectively.
 * You must solve this problem without using the
 * library';s sort function.
 *
 * Constraints:
 * -  n == nums.length
 * -  1 <= n <= 300
 * -  nums[i] is 0 , 1 , or 2 .
 *  “Follow up:“ Could you come up with a one-pass algorithm using onlyconstant extra space?
 *
 */
class Solution {
 public:
  void sortColors(vector<int>& nums) {
    vector<int> count(3, 0);
    for (const auto& x : nums) ++count[x];
    fill(nums.begin(), nums.begin() + count[0], 0);
    fill(nums.begin() + count[0], nums.begin() + count[0] + count[1], 1);
    fill(nums.begin() + count[0] + count[1], nums.end(), 2);
  }
};
}  // namespace l75
#endif