#include <gtest/gtest.h>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 630.
 *      Course Schedule III
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   There are ‘n’ different online courses numbered from ‘1’ to ‘n’ . You
 *   are given an array ‘courses’ where ‘courses[i] = [durationᵢ,
 *   lastDayᵢ]’ indicate that the ‘iᵗʰ’ course should be taken
 *   “continuously” for ‘durationᵢ’ days and must be finished before or on
 *   ‘lastDayᵢ’
 *   You will start on the ‘1ˢᵗ’ day and you cannot take two or more
 *   courses
 *   Return “the maximum number of courses that you can take” .
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤ courses.length ≤ 10⁴’
 *   • ‘1 ≤ durationᵢ, lastDayᵢ ≤ 10⁴’
 *
 */

struct q630 : public ::testing::Test {
  // Leetcode answer here
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        if (courses.empty()) {
            return 0;
        }
        sort(courses.begin(), courses.end(), [](auto &x, auto &y) {
            return x[1] < y[1];
        });
        priority_queue<int> pq;
        int total = 0;
        for (auto &x : courses) {
            total += x[0];
            pq.emplace(x[0]);
            if (total > x[1]) {
                total -= pq.top();
                pq.pop();
            }
        }
        
        return pq.size();
    }
};

  class Solution *solution;
};

TEST_F(q630, sample_input01) {
  solution = new Solution();
  vector<vector<int>> courses = {{100, 200}, {200, 1300}, {1000, 1250}, {2000, 3200}};
  int exp = 3;
  int act = solution->scheduleCourse(courses);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q630, sample_input02) {
  solution = new Solution();
  vector<vector<int>> courses = {{1, 2}};
  int exp = 1;
  int act = solution->scheduleCourse(courses);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q630, sample_input03) {
  solution = new Solution();
  vector<vector<int>> courses = {{3, 2}, {4, 3}};
  int exp = 0;
  int act = solution->scheduleCourse(courses);
  EXPECT_EQ(act, exp);
  delete solution;
}