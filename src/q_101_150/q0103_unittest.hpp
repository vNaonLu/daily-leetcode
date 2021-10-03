
#ifndef Q103_UNITTEST_H__
#define Q103_UNITTEST_H__
#include <gtest/gtest.h>

#include "q0103.hpp"
using namespace std;

/**
  * This file is generated by leetcode_add.py
  *
  * 103.
  *      Binary Tree Zigzag Level Order Traversal
  *
  * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
  *
  *   Given the ‘root’ of a binary tree, return “the zigzag level order
  *   traversal of its nodes&#39; values” . (i.e., from left to right, then
  *   right to left for the next level and alternate between).
  *
  * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
  *
  *   • The number of nodes in the tree is in the range ‘[0, 2000]’ .
  *   • ‘-100 ≤ Node.val ≤ 100’
  *
*/

TEST(q103, sample_input01) {
  l103::Solution solver;
  TreeNode* root = TreeNode::generate({3, 9, 20, 15, 7});
  vector<vector<int>> exp = {{3}, {20, 9}, {15, 7}};
  EXPECT_EQ(solver.zigzagLevelOrder(root), exp);
}

TEST(q103, sample_input02) {
  l103::Solution solver;
  TreeNode* root = TreeNode::generate({1});
  vector<vector<int>> exp = {{1}};
  EXPECT_EQ(solver.zigzagLevelOrder(root), exp);
}

TEST(q103, sample_input03) {
  l103::Solution solver;
  TreeNode* root = TreeNode::generate({});
  vector<vector<int>> exp = {};
  EXPECT_EQ(solver.zigzagLevelOrder(root), exp);
}

#endif