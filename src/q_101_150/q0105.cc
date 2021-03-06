#include <gtest/gtest.h>
#include <iostream>
#include <leetcode/treenode.hpp>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * This file is generated by leetcode_add.py v1.0
 *
 * 105.
 *      Construct Binary Tree from Preorder and Inorder Traversal
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   Given two integer arrays ‘preorder’ and ‘inorder’ where ‘preorder’ is
 *   the preorder traversal of a binary tree and ‘inorder’ is the inorder
 *   traversal of the same tree, construct and return “the binary tree” .
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤ preorder.length ≤ 3000’
 *   • ‘inorder.length = preorder.length’
 *   • ‘-3000 ≤ preorder[i], inorder[i] ≤ 3000’
 *   • ‘preorder’ and ‘inorder’ consist of “unique” values.
 *   • Each value of ‘inorder’ also appears in ‘preorder’ .
 *   • ‘preorder’ is “guaranteed” to be the preorder traversal of the tree.
 *   • ‘inorder’ is “guaranteed” to be the inorder traversal of the tree.
 *
 */

struct q105 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   private:
    unordered_map<int, int> memo;
    TreeNode* helper(vector<int>& pre, vector<int>& in, int in_beg, int in_end, int index) {
      if (in_end < in_beg) return nullptr;
      if (index >= pre.size()) return nullptr;
      int i = memo[pre[index]];
      return new TreeNode(pre[index],
                          helper(pre, in, in_beg, i - 1, index + 1),
                          helper(pre, in, i + 1, in_end, index + i - in_beg + 1));
    }
   public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
      for (int i = 0; i < inorder.size(); ++i)
        memo[inorder[i]] = i;
      return helper(preorder, inorder,
                    0, inorder.size() - 1, 0);
    }
  };

  class Solution *solution;
};

TEST_F(q105, sample_input01) {
  solution = new Solution();
  vector<int> preorder = {3, 9, 20, 15, 7};
  vector<int> inorder = {9, 3, 15, 20, 7};
  TreeNode* exp = TreeNode::generate({3, 9, 20, NULL_TREENODE, NULL_TREENODE, 15, 7});
  TreeNode* act = solution->buildTree(preorder, inorder);
  EXPECT_TREENODE_EQ(act, exp);
  TreeNode::release(exp, act);
  delete solution;
}

TEST_F(q105, sample_input02) {
  solution = new Solution();
  vector<int> preorder = {-1};
  vector<int> inorder = {-1};
  TreeNode* exp = TreeNode::generate({-1});
  TreeNode* act = solution->buildTree(preorder, inorder);
  EXPECT_TREENODE_EQ(act, exp);
  TreeNode::release(exp, act);
  delete solution;
}