#include <gtest/gtest.h>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 658.
 *      Find K Closest Elements
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   Given a “sorted” integer array ‘arr’ , two integers ‘k’ and ‘x’ ,
 *   return the ‘k’ closest integers to ‘x’ in the array. The result should
 *   also be sorted in ascending
 *   An integer ‘a’ is closer to ‘x’ than an integer ‘b’
 *       -  ‘|a - x| < |b - x|’ ,
 *       -  ‘|a - x| = |b - x|’ and ‘a < b’ 
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤ k ≤ arr.length’
 *   • ‘1 ≤ arr.length ≤ 10⁴’
 *   • ‘arr’ is sorted in “ascending” order.
 *   • ‘-10⁴ ≤ arr[i], x ≤ 10⁴’
 *
 */

struct q658 : public ::testing::Test {
  // Leetcode answer here
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (auto &z : arr) {
            pq.emplace(abs(z-x), z);
        }
        
        vector<int> res;
        while (k--) {
            res.emplace_back(pq.top().second);
            pq.pop();
        }
        
        sort(res.begin(), res.end());
        
        return res;
    }
};

  class Solution *solution;
};

TEST_F(q658, sample_input01) {
  solution = new Solution();
  vector<int> arr = {1, 2, 3, 4, 5};
  int k = 4;
  int x = 3;
  vector<int> exp = {1, 2, 3, 4};
  vector<int> act = solution->findClosestElements(arr, k, x);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q658, sample_input02) {
  solution = new Solution();
  vector<int> arr = {1, 2, 3, 4, 5};
  int k = 4;
  int x = -1;
  vector<int> exp = {1, 2, 3, 4};
  vector<int> act = solution->findClosestElements(arr, k, x);
  EXPECT_EQ(act, exp);
  delete solution;
}