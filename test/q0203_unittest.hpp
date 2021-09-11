
#ifndef Q203_UNITTEST_H__
#define Q203_UNITTEST_H__
#include <gtest/gtest.h>

#include "../src/q0203.hpp"
using namespace std;

/**
  * this file is generated by gquestion.py
  *
  * 203. Remove Linked List Elements
  *
  * Given the head of a linked list and an integer
  * val , remove all the nodes of the linked list that
  * has Node.val == val , and return the new head .
  *
  * Constraints:
  * - The number of nodes in the list is in the range [0, 10^(4)] .
  * -  1 <= Node.val <= 50 
  * -  0 <= val <= 50 
  *
*/

TEST(q203, sample_input01) {
  ListNode *head = ListNode::generate({1, 2, 6, 3, 4, 5, 6});
  int val = 6;
  ListNode *exp = ListNode::generate({1, 2, 3, 4, 5});
  l203::Solution solver;
  EXPECT_TRUE(ListNode::compare(solver.removeElements(head, val), exp));
}

TEST(q203, sample_input02) {
  ListNode *head = ListNode::generate({});
  int val = 1;
  ListNode *exp = ListNode::generate({});
  l203::Solution solver;
  EXPECT_TRUE(ListNode::compare(solver.removeElements(head, val), exp));
}

TEST(q203, sample_input03) {
  ListNode *head = ListNode::generate({7, 7, 7, 7});
  int val = 7;
  ListNode *exp = ListNode::generate({});
  l203::Solution solver;
  EXPECT_TRUE(ListNode::compare(solver.removeElements(head, val), exp));
}

#endif