#include <gtest/gtest.h>
#include <iostream>
#include <leetcode/treenode.hpp>

using namespace std;

/**
 * This file is generated by leetcode_add.py v1.0
 *
 * 101.
 *      Symmetric Tree
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   Given the ‘root’ of a binary tree, “check whether it is a mirror of
 *   itself” (i.e., symmetric around its center).
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • The number of nodes in the tree is in the range ‘[1, 1000]’ .
 *   • ‘-100 ≤ Node.val ≤ 100’
 *
 */

struct q101 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   private:
    bool isSymmetric(TreeNode *l, TreeNode *r) {
      if (l == nullptr && r == nullptr)
        return true;
      else if (l == nullptr)
        return false;
      else if (r == nullptr)
        return false;
      else {
        return l->val == r->val &&
               isSymmetric(l->left, r->right) &&
               isSymmetric(l->right, r->left);
      }
    }
   public:
    bool isSymmetric(TreeNode *root) {
      if (root == nullptr) return true;
      return isSymmetric(root->left, root->right);
    }
  };

  class Solution *solution;
};

TEST_F(q101, sample_input01) {
  solution = new Solution();
  TreeNode* root = TreeNode::generate({1, 2, 2, 3, 4, 4, 3});
  bool exp = true;
  EXPECT_EQ(solution->isSymmetric(root), exp);
  delete solution;
}

TEST_F(q101, sample_input02) {
  solution = new Solution();
  TreeNode* root = TreeNode::generate({1, 2, 2, NULL_TREENODE, 3, NULL_TREENODE, 3});
  bool exp = false;
  EXPECT_EQ(solution->isSymmetric(root), exp);
  delete solution;
}