#include <gtest/gtest.h>
#include <iostream>
#include <vector>

using namespace std;

/**
 * This file is generated by leetcode_add.py v1.0
 *
 * 1361.
 *       Validate Binary Tree Nodes
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   You have ‘n’ binary tree nodes numbered from ‘0’ to ‘n - 1’ where node
 *   ‘i’ has two children ‘leftChild[i]’ and ‘rightChild[i]’ , return
 *   ‘true’ if and only if “all” the given nodes form “exactly one” valid
 *   binary
 *   If node ‘i’ has no left child then ‘leftChild[i]’ will equal ‘-1’ ,
 *   similarly for the right
 *   Note that the nodes have no values and that we only use the node
 *   numbers in this problem.
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤ n ≤ 10⁴’
 *   • ‘leftChild.length = rightChild.length = n’
 *   • ‘-1 ≤ leftChild[i], rightChild[i] ≤ n - 1’
 *
 */

struct q1361 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   private:
    vector<int> indegree;
    vector<bool> visited;
    vector<bool> visiting;
    bool hasCycle(int n, const vector<int>& l, const vector<int>& r) {
      if (n >= 0) {
        if (visiting[n]) {
          return true;
        } else if (visited[n]) {
          ++indegree[n];
          return false;
        }
        visiting[n] = true;
        if (hasCycle(l[n], l, r) || hasCycle(r[n], l, r)) return true;
        visiting[n] = false;
        visited[n] = true;
      }
      return false;
    }
   public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
      indegree.resize(n, 0);
      visited.resize(n, false);
      visiting.resize(n, false);
      for (int i = 0; i < n; ++i)
        if (hasCycle(i, leftChild, rightChild)) return false;
      int root = 0;
      for (int i = 0; i < n; ++i) {
        if (indegree[i] > 1) return false;
        if (indegree[i] == 0) ++root;
      }
      return root == 1;
    }
  };

  class Solution *solution;
};

TEST_F(q1361, sample_input01) {
  solution = new Solution();
  int n = 4;
  vector<int> leftChild = {1, -1, 3, -1};
  vector<int> rightChild = {2, -1, -1, -1};
  bool exp = true;
  EXPECT_EQ(solution->validateBinaryTreeNodes(n, leftChild, rightChild), exp);
  delete solution;
}

TEST_F(q1361, sample_input02) {
  solution = new Solution();
  int n = 4;
  vector<int> leftChild = {1, -1, 3, -1};
  vector<int> rightChild = {2, 3, -1, -1};
  bool exp = false;
  EXPECT_EQ(solution->validateBinaryTreeNodes(n, leftChild, rightChild), exp);
  delete solution;
}

TEST_F(q1361, sample_input03) {
  solution = new Solution();
  int n = 2;
  vector<int> leftChild = {1, 0};
  vector<int> rightChild = {-1, -1};
  bool exp = false;
  EXPECT_EQ(solution->validateBinaryTreeNodes(n, leftChild, rightChild), exp);
  delete solution;
}

TEST_F(q1361, sample_input04) {
  solution = new Solution();
  int n = 6;
  vector<int> leftChild = {1, -1, -1, 4, -1, -1};
  vector<int> rightChild = {2, -1, -1, 5, -1, -1};
  bool exp = false;
  EXPECT_EQ(solution->validateBinaryTreeNodes(n, leftChild, rightChild), exp);
  delete solution;
}