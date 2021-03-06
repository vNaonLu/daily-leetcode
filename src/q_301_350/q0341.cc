#include <gtest/gtest.h>
#include <iostream>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 341.
 *      Flatten Nested List Iterator
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   You are given a nested list of integers ‘nestedList’ . Each element is
 *   either an integer or a list whose elements may also be integers or
 *   other lists. Implement an iterator to flatten
 *   Implement the ‘NestedIterator’
 *       -  ‘NestedIterator(List<NestedInteger> nestedList)’ Initializes
 *   the iterator with the nested list ‘nestedList’
 *       -  ‘int next()’ Returns the next integer in the nested
 *       -  ‘boolean hasNext()’ Returns ‘true’ if there are still some
 *   integers in the nested list and ‘false’
 *   Your code will be tested with the following
 *   initialize iterator with
 *   res =
 *   while
 *       append iterator.next() to the end of
 *   return
 *   If ‘res’ matches the expected flattened list, then your code will be
 *   judged as correct.
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤ nestedList.length ≤ 500’
 *   • The values of the integers in the nested list is in the range ‘[-10⁶, 10⁶]’ .
 *
 */

struct q341 : public ::testing::Test {
  // Leetcode answer here
 
 // This is the interface that allows for creating nested lists.
 // You should not implement it, or speculate about its implementation
 class NestedInteger {
   public:
     // Return true if this NestedInteger holds a single integer, rather than a nested list.
     bool isInteger() const;
 
     // Return the single integer that this NestedInteger holds, if it holds a single integer
     // The result is undefined if this NestedInteger holds a nested list
     int getInteger() const;
 
     // Return the nested list that this NestedInteger holds, if it holds a nested list
     // The result is undefined if this NestedInteger holds a single integer
     const vector<NestedInteger> &getList() const;
 };
 

  class NestedIterator {
   private:
    vector<int> expand_;
    vector<int>::iterator it_;

    void expand_integer(vector<int> &res, vector<NestedInteger> list) {
      for (auto &x : list) {
        if (x.isInteger()) {
          res.emplace_back(x.getInteger());
        } else {
          expand_integer(res, x.getList());
        }
      }
    }

   public:
    NestedIterator(vector<NestedInteger> &nestedList) {
      expand_integer(expand_, nestedList);
      it_ = expand_.begin();
    }

    int next() {
      return *it_++;
    }

    bool hasNext() {
      return it_ != expand_.end();
    }
  };

  /**
   * Your NestedIterator object will be instantiated and called as such:
   * NestedIterator i(nestedList);
   * while (i.hasNext()) cout << i.next();
   */

  class NestedIterator *nested_iterator;
};

TEST_F(q341, NOT_IMPLEMENT) {
   EXPECT_TRUE("NOT IMPLEMENT");
}