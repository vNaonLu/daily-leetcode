
#ifndef LEETCODE_Q547_H__
#define LEETCODE_Q547_H__
#include <iostream>
#include <stack>
#include <vector>

namespace l547 {
using namespace std;

/**
  * this file is generated by gquestion.py
  *
  * 547. Number of Provinces
  * There are n cities. Some of them are connected,
  * while some are not. If city a is connected directly
  * with city b , and city b is connected directly
  * with city c , then city a is connected indirectly
  * with city c .
  * A “province“ is a group of directly or indirectly
  * connected cities and no other cities outside of
  * the group.
  * You are given an n x n matrix isConnected where
  * isConnected[i][j] = 1 if the i^(th) city and the
  * j^(th) city are directly connected, and
  * isConnected[i][j] = 0 otherwise.
  * Return the total number of “provinces“ .
  *
  * Constraints:
  * -  1 <= n <= 200 
  * -  n == isConnected.length 
  * -  n == isConnected[i].length 
  * -  isConnected[i][j] is 1 or 0 .
  * -  isConnected[i][i] == 1 
  * -  isConnected[i][j] == isConnected[j][i] 
  *
*/
class Solution {
 public:
  int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    for (int i = 0; i < n; ++i) {
      if (isConnected[i][i] == 1) {
        stack<int> dir;
        dir.push(i);
        while (!dir.empty()) {
          auto cur = dir.top();
          dir.pop();
          for (int j = 0; j < n; ++j) {
            if (cur == j) continue;
            if (isConnected[cur][j] == 1) {
              isConnected[j][cur] = 0;
              isConnected[cur][j] = 0;
              isConnected[j][j] = 0;
              dir.push(j);
            }
          }
        }
      }
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
      if (isConnected[i][i] == 1) ++res;
    }
    return res;
  }
};
}  // namespace l547
#endif