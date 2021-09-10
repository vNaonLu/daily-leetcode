
#ifndef Q19_UNITTEST_H__
#define Q19_UNITTEST_H__
#include <gtest/gtest.h>

#include "../src/q0019.hpp"
using namespace std;

/**
  * this file is generated by gquestion.py

  *
  * 19. Remove Nth Node From End of List
  *
  * Given the head of a linked list, remove the
  * n^(th) node from the end of the list and return its
  * head.
  *
  * Constraints:
  * - The number of nodes in the list is sz .
  * -  1 <= sz <= 30 
  * -  0 <= Node.val <= 100 
  * -  1 <= n <= sz 
  *  “Follow up:“ Could you do this in one pass?
  *
*/

#include <vector>

namespace l19 {
void release(l19::ListNode *p) {
  if (!p) return;
  release(p->next);
  delete p;
}

inline l19::ListNode *generate(const vector<int> &v) {
  if (v.empty()) return nullptr;
  l19::ListNode *res = new l19::ListNode(v[0]);
  l19::ListNode *p = res;
  for (auto it = v.begin() + 1; it != v.end(); ++it) {
    p->next = new l19::ListNode(*it);
    p = p->next;
  }
  return res;
}

inline bool compare(l19::ListNode *p, l19::ListNode *q) {
  while (p != nullptr && q != nullptr) {
    if (p->val != q->val) return false;
    p = p->next;
    q = q->next;
  }
  return p == nullptr && q == nullptr;
}
}  // namespace l19

TEST(q19, sample_input01) {
  auto head = l19::generate({1, 2, 3, 4, 5});
  int n = 2;
  auto exp = l19::generate({1, 2, 3, 5});
  l19::Solution solver;
  EXPECT_TRUE(compare(solver.removeNthFromEnd(head, n), exp));
  release(head);
  release(exp);
}

TEST(q19, sample_input02) {
  auto head = l19::generate({1});
  int n = 1;
  auto exp = l19::generate({});
  l19::Solution solver;
  EXPECT_TRUE(compare(solver.removeNthFromEnd(head, n), exp));
  release(head);
  release(exp);
}

TEST(q19, sample_input03) {
  auto head = l19::generate({1, 2});
  int n = 1;
  auto exp = l19::generate({1});
  l19::Solution solver;
  EXPECT_TRUE(compare(solver.removeNthFromEnd(head, n), exp));
  release(head);
  release(exp);
}

#endif