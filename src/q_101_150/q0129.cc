#include <gtest/gtest.h>
#include <iostream>
#include <leetcode/treenode.hpp>
#include <numeric>

using namespace std;

/**
 * This file is generated by leetcode_add.py v1.0
 *
 * 129.
 *      Sum Root to Leaf Numbers
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   You are given the ‘root’ of a binary tree containing digits from ‘0’
 *   to ‘9’
 *   Each root-to-leaf path in the tree represents a
 *       - For example, the root-to-leaf path ‘1 -> 2 -> 3’ represents the
 *   number ‘123’
 *   Return “the total sum of all root-to-leaf numbers” . Test cases are
 *   generated so that the answer will fit in a “32-bit”
 *   A “leaf” node is a node with no children.
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • The number of nodes in the tree is in the range ‘[1, 1000]’ .
 *   • ‘0 ≤ Node.val ≤ 9’
 *   • The depth of the tree will not exceed ‘10’ .
 *
 */

struct q129 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   private:
    void helper(TreeNode *p, vector<int> &nums, int current = 0) {
      if (p != nullptr) {
        current = current * 10 + p->val;
        if (p->left == nullptr && p->right == nullptr) {
          nums.push_back(current);
        } else {
          helper(p->left, nums, current);
          helper(p->right, nums, current);
        }
      }
    }
   public:
    int sumNumbers(TreeNode *root) {
      vector<int> leavesSum;
      helper(root, leavesSum);
      return accumulate(leavesSum.begin(), leavesSum.end(), 0);
    }
  };

  class Solution *solution;
};

TEST_F(q129, sample_input01) {
  solution = new Solution();
  TreeNode* root = TreeNode::generate({1, 2, 3});
  int exp = 25;
  EXPECT_EQ(solution->sumNumbers(root), exp);
  delete solution;
}

TEST_F(q129, sample_input02) {
  solution = new Solution();
  TreeNode* root = TreeNode::generate({4, 9, 0, 5, 1});
  int exp = 1026;
  EXPECT_EQ(solution->sumNumbers(root), exp);
  delete solution;
}