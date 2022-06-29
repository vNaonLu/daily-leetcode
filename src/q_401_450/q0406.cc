#include <gtest/gtest.h>
#include <iostream>
#include <vector>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 406.
 *      Queue Reconstruction by Height
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   You are given an array of people, ‘people’ , which are the attributes
 *   of some people in a queue (not necessarily in order). Each ‘people[i]
 *   = [hᵢ, kᵢ]’ represents the ‘iᵗʰ’ person of height ‘hᵢ’ with “exactly”
 *   ‘kᵢ’ other people in front who have a height greater than or equal to
 *   ‘hᵢ’
 *   Reconstruct and return “the queue that is represented by the input
 *   array ” ‘people’ . The returned queue should be formatted as an array
 *   ‘queue’ , where ‘queue[j] = [hⱼ, kⱼ]’ is the attributes of the ‘jᵗʰ’
 *   person in the queue ( ‘queue[0]’ is the person at the front of the
 *   queue).
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤ people.length ≤ 2000’
 *   • ‘0 ≤ hᵢ ≤ 10⁶’
 *   • ‘0 ≤ kᵢ < people.length’
 *   • It is guaranteed that the queue can be reconstructed.
 *
 */

struct q406 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
  public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
      sort(people.begin(), people.end(), [](auto &x, auto &y) {
        return x[0] == y[0] ? x[1] < y[1] : x[0] > y[0];
      });
      vector<vector<int>> res;

      for (auto &v : people) {
        res.insert(res.begin() + v[1], v);
      }

      return res;
    }
  };

  class Solution *solution;
};

TEST_F(q406, sample_input01) {
  solution = new Solution();
  vector<vector<int>> people = {{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
  vector<vector<int>> exp = {{5, 0}, {7, 0}, {5, 2}, {6, 1}, {4, 4}, {7, 1}};
  vector<vector<int>> act = solution->reconstructQueue(people);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q406, sample_input02) {
  solution = new Solution();
  vector<vector<int>> people = {{6, 0}, {5, 0}, {4, 0}, {3, 2}, {2, 2}, {1, 4}};
  vector<vector<int>> exp = {{4, 0}, {5, 0}, {2, 2}, {3, 2}, {1, 4}, {6, 0}};
  vector<vector<int>> act = solution->reconstructQueue(people);
  EXPECT_EQ(act, exp);
  delete solution;
}