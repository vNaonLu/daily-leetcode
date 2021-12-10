#include <gtest/gtest.h>
#include <iostream>
#include <leetcode/listnode.hpp>
#include <vector>

using namespace std;

/**
 * This file is generated by leetcode_add.py v1.0
 *
 * 725.
 *      Split Linked List in Parts
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   Given the ‘head’ of a singly linked list and an integer ‘k’ , split
 *   the linked list into ‘k’ consecutive linked list
 *   The length of each part should be as equal as possible: no two parts
 *   should have a size differing by more than one. This may lead to some
 *   parts being
 *   The parts should be in the order of occurrence in the input list, and
 *   parts occurring earlier should always have a size greater than or
 *   equal to parts occurring
 *   Return “an array of the ” ‘k’ “ parts” .
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • The number of nodes in the list is in the range ‘[0, 1000]’ .
 *   • ‘0 ≤ Node.val ≤ 1000’
 *   • ‘1 ≤ k ≤ 50’
 *
 */

struct q725 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
      int cnt = 0;
      ListNode *p = head, *q = nullptr;
      while (p != nullptr) {
        ++cnt;
        p = p->next;
      }
      vector<ListNode*> res;
      int split = cnt / k, left = cnt % k;
      p = head;
      for (int i = 0; i < k; ++i) {
        q = p;
        int cur = split + (left > 0 ? 1 : 0) - 1;
        --left;
        while (p != nullptr && cur > 0) {
          --cur;
          p = p->next;
        }
        res.push_back(q);
        if (p != nullptr) {
          q = p;
          p = p->next;
          q->next = nullptr;
        }
      }
      return res;
    }
  };

  class Solution *solution;
};

TEST_F(q725, sample_input01) {
  solution = new Solution();
  ListNode* head = ListNode::generate({1, 2, 3});
  int k = 5;
  vector<ListNode*> exp = {ListNode::generate({1}), ListNode::generate({2}), ListNode::generate({3}), ListNode::generate({}), ListNode::generate({})};
  vector<ListNode*> ans = solution->splitListToParts(head, k);
  EXPECT_EQ(ans.size(), exp.size());
  for (int i = 0; i < ans.size(); ++i) {
    EXPECT_LISTNODE_EQ(ans[i], exp[i]);
  }
  delete solution;
}

TEST_F(q725, sample_input02) {
  solution = new Solution();
  ListNode* head = ListNode::generate({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
  int k = 3;
  vector<ListNode*> exp = {ListNode::generate({1, 2, 3, 4}), ListNode::generate({5, 6, 7}), ListNode::generate({8, 9, 10})};
  vector<ListNode*> ans = solution->splitListToParts(head, k);
  EXPECT_EQ(ans.size(), exp.size());
  for (int i = 0; i < ans.size(); ++i) {
    EXPECT_LISTNODE_EQ(ans[i], exp[i]);
  }
  delete solution;
}