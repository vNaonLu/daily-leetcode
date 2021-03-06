#include <gtest/gtest.h>
#include <iostream>
#include <leetcode/listnode.hpp>
#include <leetcode/treenode.hpp>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 109.
 *      Convert Sorted List to Binary Search Tree
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   Given the ‘head’ of a singly linked list where elements are “sorted in
 *   ascending order” , convert it to a height balanced
 *   For this problem, a height-balanced binary tree is defined as a binary
 *   tree in which the depth of the two subtrees of “every” node never
 *   differ by more than 1.
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • The number of nodes in ‘head’ is in the range ‘[0, 2 × 10⁴]’ .
 *   • ‘-10⁵ ≤ Node.val ≤ 10⁵’
 *
 */

struct q109 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   private:
    TreeNode* buildTree(ListNode* beg, ListNode* end = nullptr) {
      if (beg == end) return nullptr;
      ListNode *mid = beg,
               *fast = beg;
      while (fast != end && fast->next != end) {
        fast = fast->next->next;
        mid = mid->next;
      }
      return new TreeNode(mid->val, buildTree(beg, mid), buildTree(mid->next, end));
    }

   public:
    TreeNode* sortedListToBST(ListNode* head) {
      return buildTree(head);
    }
  };

  class Solution *solution;
};

TEST_F(q109, sample_input01) {
  solution = new Solution();
  ListNode* head = ListNode::generate({-10, -3, 0, 5, 9});
  TreeNode* exp = TreeNode::generate({0, -3, 9, -10, NULL_TREENODE, 5});
  TreeNode* act = solution->sortedListToBST(head);
  EXPECT_TREENODE_EQ(act, exp);
  ListNode::release(head);
  TreeNode::release(exp, act);
  delete solution;
}

TEST_F(q109, sample_input02) {
  solution = new Solution();
  ListNode* head = ListNode::generate({});
  TreeNode* exp = TreeNode::generate({});
  TreeNode* act = solution->sortedListToBST(head);
  EXPECT_TREENODE_EQ(act, exp);
  ListNode::release(head);
  TreeNode::release(exp, act);
  delete solution;
}