
#ifndef LEETCODE_Q1306_H__
#define LEETCODE_Q1306_H__
#include <iostream>
#include <vector>
#include <queue>

namespace l1306 {
using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 1306.
 *       Jump Game III
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   Given an array of non-negative integers ‘arr’ , you are initially
 *   positioned at ‘start’ index of the array. When you are at index ‘i’ ,
 *   you can jumpto ‘i + arr[i]’ or ‘i - arr[i]’ , check if you can reach
 *   to “any” index with value
 *   Notice that you can not jump outside of the array at any time.
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤ arr.length ≤ 5 × 10⁴’
 *   • ‘0 ≤ arr[i] <arr.length’
 *   • ‘0 ≤ start < arr.length’
 *
 */

class Solution {
 public:
  bool canReach(vector<int>& arr, int start) {
    queue<int> q;
    int n = arr.size();
    q.push(start);
    while (!q.empty()) {
      int f = q.front();
      q.pop();
      if (f - arr[f] >= 0) {
        if (arr[f - arr[f]] == 0) {
          return true;
        } else if (arr[f - arr[f]] > 0) {
          q.push(f - arr[f]);
        }
      }
      if (f + arr[f] < n) {
        if (arr[f + arr[f]] == 0) {
          return true;
        } else if (arr[f + arr[f]] > 0) {
          q.push(f + arr[f]);
        }
      }
      arr[f] = -1;
    }
    return false;
  }
};
}  // namespace l1306

#endif