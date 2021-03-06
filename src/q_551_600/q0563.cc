#include <gtest/gtest.h>
#include <iostream>
#include <leetcode/treenode.hpp>

using namespace std;

/**
 * This file is generated by leetcode_add.py v1.0
 *
 * 563.
 *      Binary Tree Tilt
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   Given the ‘root’ of a binary tree, return “the sum of every tree
 *   node's “tilt” .”
 *   The “tilt” of a tree node is the “absolute difference” between the sum
 *   of all left subtree node “values” and all right subtree node “values”
 *   . If a node does not have a left child, then the sum of the left
 *   subtree node “values” is treated as ‘0’ . The rule is similar if the
 *   node does not have a right child.
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • The number of nodes in the tree is in the range ‘[0, 10⁴]’ .
 *   • ‘-1000 ≤ Node.val ≤ 1000’
 *
 */

struct q563 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   private:
    int helper(TreeNode *p, int &res) {
      if (nullptr == p) return 0;
      int L = helper(p->left, res),
          R = helper(p->right, res);
      res += abs(L - R);
      return p->val + L + R;
    }
   public:
    int findTilt(TreeNode *root) {
      int res = 0;
      helper(root, res);
      return res;
    }
  };

  class Solution *solution;
};

TEST_F(q563, sample_input01) {
  solution = new Solution();
  TreeNode* root = TreeNode::generate({1, 2, 3});
  int exp = 1;
  EXPECT_EQ(solution->findTilt(root), exp);
  delete solution;
}

TEST_F(q563, sample_input02) {
  solution = new Solution();
  TreeNode* root = TreeNode::generate({4, 2, 9, 3, 5, NULL_TREENODE, 7});
  int exp = 15;
  EXPECT_EQ(solution->findTilt(root), exp);
  delete solution;
}

TEST_F(q563, sample_input03) {
  solution = new Solution();
  TreeNode* root = TreeNode::generate({21, 7, 14, 1, 1, 2, 2, 3, 3});
  int exp = 9;
  EXPECT_EQ(solution->findTilt(root), exp);
  delete solution;
}