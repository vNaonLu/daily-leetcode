
#ifndef LEETCODE_Q621_H__
#define LEETCODE_Q621_H__
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

namespace l621 {
using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 621.
 *      Task Scheduler
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   Given a characters array ‘tasks’ , representing the tasks a CPU needs
 *   to do, where each letter represents a different task. Tasks could be
 *   done in any order. Each task is done in one unit of time. For each
 *   unit of time, the CPU could complete either one task or just be
 *   However, there is a non-negative integer ‘n’ that represents the
 *   cooldown period betweentwo “same tasks” (the same letter in the
 *   array), that is that there must be at least ‘n’ units of time between
 *   any two same
 *   Return “the least number of units of times that the CPU will take to
 *   finish all the given tasks” .
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤ task.length ≤ 10⁴’
 *   • ‘tasks[i]’ is upper-case English letter.
 *   • The integer ‘n’ is in the range ‘[0, 100]’ .
 *
 */

class Solution {
 public:
  int leastInterval(vector<char> &tasks, int n) {
    unordered_map<char, int> cnt;
    priority_queue<int> pq;
    for (const auto &x : tasks) ++cnt[x];
    for (const auto &x : cnt) pq.push(x.second);
    int res = 0;
    while (!pq.empty()) {
      ++res;
      int top = pq.top();
      pq.pop();
      top -= 1;
      vector<int> v;
      if (top > 0) v.emplace_back(top);
      int i = 0;
      while (i < n && !pq.empty()) {
        if (pq.top() > 1)
          v.emplace_back(pq.top() - 1);
        pq.pop();
        ++res;
        ++i;
      }
      if (i < n && v.size() > 0) res += n - i;
      for (int i = 0; i < v.size(); ++i) pq.push(v[i]);
    }
    return res;
  }
};
}  // namespace l621

#endif