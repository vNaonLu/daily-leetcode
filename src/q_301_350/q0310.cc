#include <gtest/gtest.h>
#include <iostream>
#include <leetcode/anyorder.hpp>
#include <queue>
#include <vector>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 310.
 *      Minimum Height Trees
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   A tree is an undirected graph in which any two vertices are connected
 *   by<i>exactly</i>one path. In other words, any connected graph without
 *   simple cycles is a
 *   Given a tree of ‘n’ nodeslabelled from ‘0’ to ‘n - 1’ , and an array
 *   of ‘n - 1’  ‘edges’ where ‘edges[i] = [aᵢ, bᵢ]’ indicates that there
 *   is an undirected edge between the two nodes ‘aᵢ’ and ‘bᵢ’ in the
 *   tree,you can choose any node of the tree as the root. When you select
 *   a node ‘x’ as the root, the result tree has height ‘h’ . Among all
 *   possible rooted trees, those with minimum height (i.e. ‘min(h)’ ) are
 *   called “minimum height trees”
 *   Return “a list of all “MHTs'” root labels” .You can return the answer
 *   in “any order”
 *   The “height” of a rooted tree is the number of edges on the longest
 *   downward path between the root and a leaf.
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤ n ≤ 2 × 10⁴’
 *   • ‘edges.length = n - 1’
 *   • ‘0 ≤ aᵢ, bᵢ < n’
 *   • ‘aᵢ ≠ bᵢ’
 *   • All the pairs ‘(aᵢ, bᵢ)’ are distinct.
 *   • The given input is “guaranteed” to be a tree and there will be “no repeated” edges.
 *
 */

struct q310 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
      if (n == 1) return vector<int>{0};
      vector<vector<int>> graph(n);
      vector<int>         degree(n, 0);
      vector<int>         res;
      queue<int>          q;
      for (const auto &e : edges) {
        graph[e[0]].push_back(e[1]); graph[e[1]].push_back(e[0]);
        degree[e[0]]++; degree[e[1]]++;
      }
      for (int i = 0; i < n; i++) if (degree[i] == 1) q.push(i);
      while (!q.empty()) {
        int n = q.size();
        res.clear();
        while (n--) {
          int node = q.front(); q.pop();
          res.push_back(node);
          for (const auto &x : graph[node])
            if (--degree[x] == 1) q.push(x);
        }
      }
      return res;
    }
  };

  class Solution *solution;
};

TEST_F(q310, sample_input01) {
  solution = new Solution();
  int n = 4;
  vector<vector<int>> edges = {{1, 0}, {1, 2}, {1, 3}};
  vector<int> exp = {1};
  // Try EXPECT_EQ_ANY_ORDER_RECURSIVE
  // if the element is also matched in any order.
  EXPECT_EQ_ANY_ORDER(solution->findMinHeightTrees(n, edges), exp);
  delete solution;
}

TEST_F(q310, sample_input02) {
  solution = new Solution();
  int n = 6;
  vector<vector<int>> edges = {{3, 0}, {3, 1}, {3, 2}, {3, 4}, {5, 4}};
  vector<int> exp = {3, 4};
  // Try EXPECT_EQ_ANY_ORDER_RECURSIVE
  // if the element is also matched in any order.
  EXPECT_EQ_ANY_ORDER(solution->findMinHeightTrees(n, edges), exp);
  delete solution;
}

TEST_F(q310, sample_input03) {
  solution = new Solution();
  int n = 1;
  vector<vector<int>> edges = {};
  vector<int> exp = {0};
  // Try EXPECT_EQ_ANY_ORDER_RECURSIVE
  // if the element is also matched in any order.
  EXPECT_EQ_ANY_ORDER(solution->findMinHeightTrees(n, edges), exp);
  delete solution;
}

TEST_F(q310, sample_input04) {
  solution = new Solution();
  int n = 2;
  vector<vector<int>> edges = {{0, 1}};
  vector<int> exp = {0, 1};
  // Try EXPECT_EQ_ANY_ORDER_RECURSIVE
  // if the element is also matched in any order.
  EXPECT_EQ_ANY_ORDER(solution->findMinHeightTrees(n, edges), exp);
  delete solution;
}