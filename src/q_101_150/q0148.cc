#include <gtest/gtest.h>
#include <iostream>
#include <leetcode/listnode.hpp>

using namespace std;

/**
 * This file is generated by leetcode_add.py v1.0
 *
 * 148.
 *      Sort List
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   Given the ‘head’ of a linked list, return “the list after sorting it
 *   in “ascending order” ” .
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • The number of nodes in the list is in the range ‘[0, 5 × 10⁴]’ .
 *   • ‘-10⁵ ≤ Node.val ≤ 10⁵’
 *
 */

struct q148 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   private:
    ListNode* merge(ListNode* l1, ListNode* l2) {
      ListNode dummy(0);
      ListNode* res = &dummy;
      while (l1 != nullptr && l2 != nullptr) {
        if (l1->val < l2->val) {
          res->next = l1;
          l1 = l1->next;
        } else {
          res->next = l2;
          l2 = l2->next;
        }
        res = res->next;
      }
      if (l1 != nullptr) res->next = l1;
      if (l2 != nullptr) res->next = l2;
      return dummy.next;
    }
    ListNode* sort(ListNode* beg, ListNode* end) {
      if (beg == end) return beg;
      ListNode *slow = beg, *fast = beg;
      while (fast != end && fast->next != end) {
        slow = slow->next;
        fast = fast->next->next;
      }
      ListNode* tmp = slow;
      slow = slow->next;
      tmp->next = nullptr;
      return merge(sort(beg, tmp), sort(slow, end));
    }
   public:
    ListNode* sortList(ListNode* head) {
      if (head == nullptr) return nullptr;
      return sort(head, nullptr);
    }
  };

  class Solution *solution;
};

TEST_F(q148, sample_input01) {
  solution = new Solution();
  ListNode* head = ListNode::generate({4, 2, 1, 3});
  ListNode* exp = ListNode::generate({1, 2, 3, 4});
  ListNode* act = solution->sortList(head);
  EXPECT_LISTNODE_EQ(act, exp);
  ListNode::release(head, exp, act);
  delete solution;
}

TEST_F(q148, sample_input02) {
  solution = new Solution();
  ListNode* head = ListNode::generate({-1, 5, 3, 4, 0});
  ListNode* exp = ListNode::generate({-1, 0, 3, 4, 5});
  ListNode* act = solution->sortList(head);
  EXPECT_LISTNODE_EQ(act, exp);
  ListNode::release(head, exp, act);
  delete solution;
}

TEST_F(q148, sample_input03) {
  solution = new Solution();
  ListNode* head = ListNode::generate({});
  ListNode* exp = ListNode::generate({});
  ListNode* act = solution->sortList(head);
  EXPECT_LISTNODE_EQ(act, exp);
  ListNode::release(head, exp, act);
  delete solution;
}