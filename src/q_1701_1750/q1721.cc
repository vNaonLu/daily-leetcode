#include <gtest/gtest.h>
#include <iostream>
#include <leetcode/listnode.hpp>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 1721.
 *       Swapping Nodes in a Linked List
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   You are given the ‘head’ of a linked list, and an integer ‘k’
 *   Return “the head of the linked list after “swapping” the values of the
 *   ” ‘kᵗʰ’ “node from the beginning and the ” ‘kᵗʰ’ “node from the end
 *   (the list is “1-indexed” ).” 
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • The number of nodes in the list is ‘n’ .
 *   • ‘1 ≤ k ≤ n ≤ 10⁵’
 *   • ‘0 ≤ Node.val ≤ 100’
 *
 */

struct q1721 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   public:
    ListNode* swapNodes(ListNode* head, int k) {
      ListNode *left = head,
               *right = head,
               *curr = head;

      int counter = 1;
      while (nullptr != curr) {
        if (counter < k) {
          left = left->next;
        }
        if (counter > k) {
          right = right->next;
        }
        curr = curr->next;
        counter++;
      }

      swap(left->val, right->val);

      return head;
    }
  };

  class Solution *solution;
};

TEST_F(q1721, sample_input01) {
  solution = new Solution();
  ListNode* head = ListNode::generate({1, 2, 3, 4, 5});
  int k = 2;
  ListNode* exp = ListNode::generate({1, 4, 3, 2, 5});
  ListNode* act = solution->swapNodes(head, k);
  EXPECT_LISTNODE_EQ(act, exp);
  ListNode::release(head, exp, act);
  delete solution;
}

TEST_F(q1721, sample_input02) {
  solution = new Solution();
  ListNode* head = ListNode::generate({7, 9, 6, 6, 7, 8, 3, 0, 9, 5});
  int k = 5;
  ListNode* exp = ListNode::generate({7, 9, 6, 6, 8, 7, 3, 0, 9, 5});
  ListNode* act = solution->swapNodes(head, k);
  EXPECT_LISTNODE_EQ(act, exp);
  ListNode::release(head, exp, act);
  delete solution;
}