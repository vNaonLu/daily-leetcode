#include <gtest/gtest.h>
#include <iostream>
#include <leetcode/treenode.hpp>
#include <vector>

using namespace std;

/**
 * This file is generated by leetcode_add.py v1.0
 *
 * 113.
 *      Path Sum II
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   Given the ‘root’ of a binary tree and an integer ‘targetSum’ , return
 *   “all “root-to-leaf” paths where the sum of the node values in the path
 *   equals ” ‘targetSum’ “. Each path should be returned as a list of the
 *   node “values” , not node references”
 *   A “root-to-leaf” path is a path starting from the root and ending at
 *   any leaf node. A “leaf” is a node with no children.
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • The number of nodes in the tree is in the range ‘[0, 5000]’ .
 *   • ‘-1000 ≤ Node.val ≤ 1000’
 *   • ‘-1000 ≤ targetSum ≤ 1000’
 *
 */

struct q113 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   private:
    void helper(TreeNode *p, vector<vector<int>> &r, vector<int> &cur, const int &t, int sum = 0) {
      if (p == nullptr) return;
      sum += p->val;
      cur.push_back(p->val);
      if (sum == t && p->left == nullptr && p->right == nullptr) {
        r.push_back(cur);
      } else {
        helper(p->left, r, cur, t, sum);
        helper(p->right, r, cur, t, sum);
      }
      sum -= p->val;
      cur.pop_back();
    }
   public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
      vector<vector<int>> res;
      vector<int> tmp;
      helper(root, res, tmp, targetSum);
      return res;
    }
  };

  class Solution *solution;
};

TEST_F(q113, sample_input01) {
  solution = new Solution();
  TreeNode* root = TreeNode::generate({5, 4, 8, 11, NULL_TREENODE, 13, 4, 7, 2, NULL_TREENODE, NULL_TREENODE, 5, 1});
  int targetSum = 22;
  vector<vector<int>> exp = {{5, 4, 11, 2}, {5, 8, 4, 5}};
  EXPECT_EQ(solution->pathSum(root, targetSum), exp);
  delete solution;
}

TEST_F(q113, sample_input02) {
  solution = new Solution();
  TreeNode* root = TreeNode::generate({1, 2, 3});
  int targetSum = 5;
  vector<vector<int>> exp = {};
  EXPECT_EQ(solution->pathSum(root, targetSum), exp);
  delete solution;
}

TEST_F(q113, sample_input03) {
  solution = new Solution();
  TreeNode* root = TreeNode::generate({1, 2});
  int targetSum = 0;
  vector<vector<int>> exp = {};
  EXPECT_EQ(solution->pathSum(root, targetSum), exp);
  delete solution;
}