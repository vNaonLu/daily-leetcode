
#ifndef Q173_UNITTEST_H__
#define Q173_UNITTEST_H__
#include <gtest/gtest.h>

#include "q0173.hpp"
using namespace std;

/**
  * This file is generated by leetcode_add.py
  *
  * 173.
  *      Binary Search Tree Iterator
  *
  * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
  *
  *   Implement the ‘BSTIterator’ class that represents an iterator over the
  *   “<a href="https://en.wikipedia.org/wiki/Tree_traversal#In-order_(LNR)"
  *   target="_blank">in-order traversal</a>” of a binary search tree.
  *   
  *   - ‘BSTIterator(TreeNode root)’ Initializes an object of the
  *   ‘BSTIterator’ class. The ‘root’ of the BST is given as part of the
  *   constructor. The pointer should be initialized to a non-existent
  *   number smaller than any element in the BST.
  *   
  *   - ‘boolean hasNext()’ Returns ‘true’ if there exists a number in the
  *   traversal to the right of the pointer, otherwise returns ‘false’.
  *   
  *   - ‘int next()’ Moves the pointer to the right, then returns the
  *   number at the pointer.
  *   
  *   Notice that by initializing the pointer to a non-existent smallest
  *   number, the first call to ‘next()’ will return the smallest element in
  *   the BST.
  *   
  *   You may assume that ‘next()’ calls will always be valid. That is,
  *   there will be at least a next number in the in-order traversal when
  *   ‘next()’ is called.
  *
  * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
  *
  *   • The number of nodes in the tree is in the range ‘[1, 10⁵]’ .
  *   • ‘0 ≤ Node.val ≤ 10⁶’
  *   • At most ‘10⁵’ calls will be made to ‘hasNext’ , and ‘next’ .
  *   • Could you implement ‘next()’ and ‘hasNext()’ to run in average ‘O(1)’ time and use ‘O(h)’ memory, where ‘h’ is the height of the tree?
  *
*/

TEST(q173, sample_input01) {
  l173::BSTIterator solver(TreeNode::generate({7, 3, 15, NULL_TREENODE, NULL_TREENODE, 9, 20}));
  EXPECT_EQ(solver.next(), 3);
  EXPECT_EQ(solver.next(), 7);
  EXPECT_EQ(solver.hasNext(), true);
  EXPECT_EQ(solver.next(), 9);
  EXPECT_EQ(solver.hasNext(), true);
  EXPECT_EQ(solver.next(), 15);
  EXPECT_EQ(solver.hasNext(), true);
  EXPECT_EQ(solver.next(), 20);
  EXPECT_EQ(solver.hasNext(), false);
}

#endif