#include <gtest/gtest.h>
#include <leetcode/treenode.hpp>
#include <iostream>

using namespace std;

/**
 * This file is generated by leetcode_add.py v1.0
 *
 * 173.
 *      Binary Search Tree Iterator
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   Implement the ‘BSTIterator’ class that represents an iterator over the
 *   “<a href="https://en.wikipedia.org/wiki/Tree_traversal#In-order_(LNR)"
 *   target="_blank">in-order traversal</a>” of a binary search tree
 *       -  ‘BSTIterator(TreeNode root)’ Initializes an object of the
 *   ‘BSTIterator’ class. The ‘root’ of the BST is given as part of the
 *   constructor. The pointer should be initialized to a non-existent
 *   number smaller than any element in the
 *       -  ‘boolean hasNext()’ Returns ‘true’ if there exists a number in
 *   the traversal to the right of the pointer, otherwise returns ‘false’
 *       -  ‘int next()’ Moves the pointer to the right, then returns the
 *   number at the
 *   Notice that by initializing the pointer to a non-existent smallest
 *   number, the first call to ‘next()’ will return the smallest element in
 *   the
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

struct q173 : public ::testing::Test {
  // Leetcode answer here
  class BSTIterator {
   private:
    int index;
    vector<int> traverse;
    void traverseHelper(TreeNode* p) {
      if (p == nullptr) return;
      traverseHelper(p->left);
      traverse.push_back(p->val);
      traverseHelper(p->right);
    }
   public:
    BSTIterator(TreeNode* root) {
      index = -1;
      traverse.clear();
      traverseHelper(root);
    }
    int next() {
      return traverse[++index];
    }
    bool hasNext() {
      return index < (int)traverse.size() - 1;
    }
  };

  class BSTIterator *bst_iterator;
};

TEST_F(q173, sample_input01) {
  TreeNode* root = TreeNode::generate({7, 3, 15, NULL_TREENODE, NULL_TREENODE, 9, 20});
  bst_iterator = new BSTIterator(root);
  EXPECT_EQ(bst_iterator->next(), 3);
  EXPECT_EQ(bst_iterator->next(), 7);
  EXPECT_EQ(bst_iterator->hasNext(), true);
  EXPECT_EQ(bst_iterator->next(), 9);
  EXPECT_EQ(bst_iterator->hasNext(), true);
  EXPECT_EQ(bst_iterator->next(), 15);
  EXPECT_EQ(bst_iterator->hasNext(), true);
  EXPECT_EQ(bst_iterator->next(), 20);
  EXPECT_EQ(bst_iterator->hasNext(), false);
  delete bst_iterator;
}