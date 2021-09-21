
#ifndef LEETCODE_Q98_H__
#define LEETCODE_Q98_H__
#include <iostream>
#include <leetcode/tree_node.hpp>
#include <limits>

namespace l98 {
using namespace std;

/**
  * this file is generated by gquestion.py
  *
  * 98. Validate Binary Search Tree
  *
  * Given the root of a binary tree, determine if it
  * is a valid binary search tree (BST) .
  * A “valid BST“ is defined as follows:
  * - The left subtree of a node contains only nodes
  * with keys “less than“ the node';s key.
  * - The right subtree of a node contains only nodes
  * with keys “greater than“ the node';s key.
  * - Both the left and right subtrees must also be
  * binary search trees.
  *
  * Constraints:
  * - The number of nodes in the tree is in the range [1, 10^(4)] .
  * -  -2^(31) <= Node.val <= 2^(31) - 1 
  *
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
 private:
  bool isBST(TreeNode* p, long min, long max) {
    if (!p) return true;
    if (p->val <= min || p->val >= max) return false;
    return isBST(p->left, min, p->val) && isBST(p->right, p->val, max);
  }

 public:
  bool isValidBST(TreeNode* root) {
    return isBST(root, numeric_limits<long>::min(), numeric_limits<long>::max());
  }
};
}  // namespace l98
#endif