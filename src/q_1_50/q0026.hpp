
#ifndef LEETCODE_Q26_H__
#define LEETCODE_Q26_H__
#include <algorithm>
#include <iostream>
#include <vector>

namespace l26 {
using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 26.
 *     Remove Duplicates from Sorted Array
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   Given an integer array ‘nums’ sorted in “non-decreasing order” ,
 *   remove the duplicates <a
 *   href="https://en.wikipedia.org/wiki/In-place_algorithm"
 *   target="_blank"> “in-place” </a> such that each unique element appears
 *   only “once” . The “relative order” of the elements should be kept the
 *   “same”
 *   Since it is impossible to change the length of the array in some
 *   languages, you must instead have the result be placed in the “first
 *   part” of the array ‘nums’ . More formally, if there are ‘k’ elements
 *   after removing the duplicates, then the first ‘k’ elements of ‘nums’
 *   should hold the final result. It does not matter what you leave beyond
 *   the first ‘k’
 *   Return ‘k’ “ after placing the final result in the first ” ‘k’ “ slots
 *   of ” ‘nums’
 *   Do “not” allocate extra space for another array. You must do this by
 *   “modifying the input array <a
 *   href="https://en.wikipedia.org/wiki/In-place_algorithm"
 *   target="_blank">in-place</a>” with O(1) extra
 *    “Custom Judge:”
 *   The judge will test your solution with the following
 *   int[] nums = [...]; // Input
 *   int[] expectedNums = [...]; // The expected answer with correct
 *   int k = removeDuplicates(nums); // Calls your
 *   assert k ==
 *   for (int i = 0; i < k; i++)
 *       assert nums[i] ==
 *   If all assertions pass, then your solution will be “accepted” .
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘0 ≤ nums.length ≤ 3 × 10⁴’
 *   • ‘-100 ≤ nums[i] ≤ 100’
 *   • ‘nums’ is sorted in “non-decreasing” order.
 *
 */

class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0;
    int cur = 0;
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] != nums[cur]) {
        swap(nums[++cur], nums[i]);
      }
    }
    return cur + 1;
  }
};
}  // namespace l26

#endif