#include <gtest/gtest.h>
#include <iostream>
#include <leetcode/listnode.hpp>

using namespace std;

/**
 * This file is generated by leetcode_add.py v1.0
 *
 * 143.
 *      Reorder List
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   You are given the head of a singly linked-list. The list can be
 *   represented
 *   L₀ &rarr; L₁ &rarr; &hellip; &rarr; L⎽(n - 1) &rarr;
 *    “Reorder the list to be on the following form:”
 *   L₀ &rarr; Lₙ &rarr; L₁ &rarr; L⎽(n - 1) &rarr; L₂ &rarr; L⎽(n - 2)
 *   &rarr;
 *   You may not modify the values in the list's nodes. Only nodes
 *   themselves may be changed.
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • The number of nodes in the list is in the range ‘[1, 5 × 10⁴]’ .
 *   • ‘1 ≤ Node.val ≤ 1000’
 *
 */

struct q143 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   public:
    void reorderList(ListNode* head) {
      vector<int> arr;
      ListNode* p = head;
      while (p != nullptr) {
        arr.push_back(p->val);
        p = p->next;
      }
      int i = 1, j = arr.size() - 1, cnt = 0;
      p = head;
      while (i <= j) {
        if (cnt++ % 2 == 0) {
          p->next = new ListNode(arr[j--]);
        } else {
          p->next = new ListNode(arr[i++]);
        }
        p = p->next;
      }
    }
  };

  class Solution *solution;
};

TEST_F(q143, sample_input01) {
  solution = new Solution();
  ListNode* head = ListNode::generate({1, 2, 3, 4});
  ListNode* exp = ListNode::generate({1, 4, 2, 3});
  solution->reorderList(head);
  // Assume the first argument is answer.
  EXPECT_LISTNODE_EQ(head, exp);
  delete solution;
}

TEST_F(q143, sample_input02) {
  solution = new Solution();
  ListNode* head = ListNode::generate({1, 2, 3, 4, 5});
  ListNode* exp = ListNode::generate({1, 5, 2, 4, 3});
  solution->reorderList(head);
  // Assume the first argument is answer.
  EXPECT_LISTNODE_EQ(head, exp);
  delete solution;
}