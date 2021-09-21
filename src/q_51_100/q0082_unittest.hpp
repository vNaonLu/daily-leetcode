
#ifndef Q82_UNITTEST_H__
#define Q82_UNITTEST_H__
#include <gtest/gtest.h>

#include "q0082.hpp"
using namespace std;

/**
  * this file is generated by gquestion.py
  *
  * 82. Remove Duplicates from Sorted List II
  *
  * Given the head of a sorted linked list, delete
  * all nodes that have duplicate numbers, leaving only
  * distinct numbers from the original list . Return
  * the linked list “sorted“ as well .
  *
  * Constraints:
  * - The number of nodes in the list is in the range [0, 300] .
  * -  -100 <= Node.val <= 100 
  * - The list is guaranteed to be “sorted“ in ascending order.
  *
*/

TEST(q82, sample_input01) {
  ListNode *head = ListNode::generate({1, 2, 3, 3, 4, 4, 5});
  ListNode *exp = ListNode::generate({1, 2, 5});
  l82::Solution solver;
  EXPECT_TRUE(ListNode::equal(solver.deleteDuplicates(head), exp));
  ListNode::release(head);
  ListNode::release(exp);
}

TEST(q82, sample_input02) {
  ListNode *head = ListNode::generate({1, 1, 1, 2, 3});
  ListNode *exp = ListNode::generate({2, 3});
  l82::Solution solver;
  EXPECT_TRUE(ListNode::equal(solver.deleteDuplicates(head), exp));
  ListNode::release(head);
  ListNode::release(exp);
}

#endif