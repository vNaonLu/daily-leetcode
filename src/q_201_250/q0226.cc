#include <gtest/gtest.h>
#include <iostream>
#include <leetcode/treenode.hpp>

using namespace std;

/**
 * This file is generated by leetcode_add.py v1.0
 *
 * 226.
 *      Invert Binary Tree
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   Given the ‘root’ of a binary tree, invert the tree, and return “its
 *   root” .
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • The number of nodes in the tree is in the range ‘[0, 100]’ .
 *   • ‘-100 ≤ Node.val ≤ 100’
 *
 */

struct q226 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   public:
    TreeNode* invertTree(TreeNode* root) {
      if (root == nullptr) return root;
      TreeNode* tmp = invertTree(root->left);
      root->left = invertTree(root->right);
      root->right = tmp;
      return root;
    }
  };

  class Solution *solution;
};

TEST_F(q226, sample_input01) {
  solution = new Solution();
  TreeNode* root = TreeNode::generate({4, 2, 7, 1, 3, 6, 9});
  TreeNode* exp = TreeNode::generate({4, 7, 2, 9, 6, 3, 1});
  TreeNode* act = solution->invertTree(root);
  EXPECT_TREENODE_EQ(act, exp);
  TreeNode::release(root, exp, act);
  delete solution;
}

TEST_F(q226, sample_input02) {
  solution = new Solution();
  TreeNode* root = TreeNode::generate({2, 1, 3});
  TreeNode* exp = TreeNode::generate({2, 3, 1});
  TreeNode* act = solution->invertTree(root);
  EXPECT_TREENODE_EQ(act, exp);
  TreeNode::release(root, exp, act);
  delete solution;
}

TEST_F(q226, sample_input03) {
  solution = new Solution();
  TreeNode* root = TreeNode::generate({});
  TreeNode* exp = TreeNode::generate({});
  TreeNode* act = solution->invertTree(root);
  EXPECT_TREENODE_EQ(act, exp);
  TreeNode::release(root, exp, act);
  delete solution;
}