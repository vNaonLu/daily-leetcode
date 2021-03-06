#include <gtest/gtest.h>
#include <iostream>
#include <leetcode/listnode.hpp>

using namespace std;

/**
 * This file is generated by leetcode_add.py v1.0
 *
 * 82.
 *     Remove Duplicates from Sorted List II
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   Given the ‘head’ of a sorted linked list, “delete all nodes that have
 *   duplicate numbers, leaving only distinct numbers from the original
 *   list” . Return “the linked list “sorted” as well” .
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • The number of nodes in the list is in the range ‘[0, 300]’ .
 *   • ‘-100 ≤ Node.val ≤ 100’
 *   • The list is guaranteed to be “sorted” in ascending order.
 *
 */

struct q82 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   public:
    ListNode* deleteDuplicates(ListNode* head) {
      ListNode dummy(-101, head);
      ListNode* p = &dummy;
      while (head != nullptr) {
        if (head->next != nullptr && head->val == head->next->val) {
          while (head->next != nullptr && head->val == head->next->val) {
            head = head->next;
          }
          p->next = head->next;
        } else {
          p = p->next;
        }
        head = head->next;
      }
      return dummy.next;
    }
  };

  class Solution *solution;
};

TEST_F(q82, sample_input01) {
  solution = new Solution();
  ListNode* head = ListNode::generate({1, 2, 3, 3, 4, 4, 5});
  ListNode* exp = ListNode::generate({1, 2, 5});
  ListNode* act = solution->deleteDuplicates(head);
  EXPECT_LISTNODE_EQ(act, exp);
  ListNode::release(head, exp, act);
  delete solution;
}

TEST_F(q82, sample_input02) {
  solution = new Solution();
  ListNode* head = ListNode::generate({1, 1, 1, 2, 3});
  ListNode* exp = ListNode::generate({2, 3});
  ListNode* act = solution->deleteDuplicates(head);
  EXPECT_LISTNODE_EQ(act, exp);
  ListNode::release(head, exp, act);
  delete solution;
}