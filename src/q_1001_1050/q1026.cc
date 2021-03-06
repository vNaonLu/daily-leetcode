#include <gtest/gtest.h>
#include <iostream>
#include <leetcode/treenode.hpp>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 1026.
 *       Maximum Difference Between Node and Ancestor
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   Given the ‘root’ of a binary tree, find the maximum value ‘v’ for
 *   which there exist “different” nodes ‘a’ and ‘b’ where ‘v = |a.val -
 *   b.val|’ and ‘a’ is an ancestor of ‘b’
 *   A node ‘a’ is an ancestor of ‘b’ if either: any child of ‘a’ is equal
 *   to ‘b’ or any child of ‘a’ is an ancestor of ‘b’ .
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • The number of nodes in the tree is in the range ‘[2, 5000]’ .
 *   • ‘0 ≤ Node.val ≤ 10⁵’
 *
 */

struct q1026 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   private:
    int res;
    void diff(TreeNode* p, int cmax, int cmin) {
      if (nullptr == p) return;
      res = max({res, abs(cmax - p->val), abs(cmin - p->val)});
      cmax = max(cmax, p->val);
      cmin = min(cmin, p->val);
      diff(p->left, cmax, cmin);
      diff(p->right, cmax, cmin);
    }

   public:
    int maxAncestorDiff(TreeNode* root) {
      res = 0;
      diff(root, root->val, root->val);
      return res;
    }
  };

  class Solution *solution;
};

TEST_F(q1026, sample_input01) {
  solution = new Solution();
  TreeNode* root = TreeNode::generate({8, 3, 10, 1, 6, NULL_TREENODE, 14, NULL_TREENODE, NULL_TREENODE, 4, 7, 13});
  int exp = 7;
  int act = solution->maxAncestorDiff(root);
  EXPECT_EQ(act, exp);
  TreeNode::release(root);
  delete solution;
}

TEST_F(q1026, sample_input02) {
  solution = new Solution();
  TreeNode* root = TreeNode::generate({1, NULL_TREENODE, 2, NULL_TREENODE, 0, 3});
  int exp = 3;
  int act = solution->maxAncestorDiff(root);
  EXPECT_EQ(act, exp);
  TreeNode::release(root);
  delete solution;
}