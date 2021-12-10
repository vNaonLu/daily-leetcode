#include <gtest/gtest.h>
#include <iostream>
#include <leetcode/treenode.hpp>

using namespace std;

/**
 * This file is generated by leetcode_add.py v1.0
 *
 * 104.
 *      Maximum Depth of Binary Tree
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   Given the ‘root’ of a binary tree, return “its maximum depth”
 *   A binary tree's “maximum depth” is the number of nodes along the
 *   longest path from the root node down to the farthest leaf node.
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • The number of nodes in the tree is in the range ‘[0, 10⁴]’ .
 *   • ‘-100 ≤ Node.val ≤ 100’
 *
 */

struct q104 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   private:
    int helper(TreeNode* p, int h = 0) {
      if (p == nullptr) return h;
      return max({h, helper(p->left, h + 1), helper(p->right, h + 1)});
    }
   public:
    int maxDepth(TreeNode* root) {
      int res = helper(root);
      return res;
    }
  };

  class Solution *solution;
};

TEST_F(q104, sample_input01) {
  solution = new Solution();
  TreeNode* root = TreeNode::generate({3, 9, 20, NULL_TREENODE, NULL_TREENODE, 15, 7});
  int exp = 3;
  EXPECT_EQ(solution->maxDepth(root), exp);
  delete solution;
}

TEST_F(q104, sample_input02) {
  solution = new Solution();
  TreeNode* root = TreeNode::generate({1, NULL_TREENODE, 2});
  int exp = 2;
  EXPECT_EQ(solution->maxDepth(root), exp);
  delete solution;
}

TEST_F(q104, sample_input03) {
  solution = new Solution();
  TreeNode* root = TreeNode::generate({});
  int exp = 0;
  EXPECT_EQ(solution->maxDepth(root), exp);
  delete solution;
}

TEST_F(q104, sample_input04) {
  solution = new Solution();
  TreeNode* root = TreeNode::generate({0});
  int exp = 1;
  EXPECT_EQ(solution->maxDepth(root), exp);
  delete solution;
}