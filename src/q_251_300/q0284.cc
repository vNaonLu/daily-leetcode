#include <gtest/gtest.h>
#include <iostream>
#include <vector>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 284.
 *      Peeking Iterator
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   Design an iterator that supports the ‘peek’ operation on an existing
 *   iterator in addition to the ‘hasNext’ and the ‘next’
 *   Implement the ‘PeekingIterator’
 *       -  ‘PeekingIterator(Iterator<int> nums)’ Initializes the object
 *   with the given integer iterator ‘iterator’
 *       -  ‘int next()’ Returns the next element in the array and moves
 *   the pointer to the next
 *       -  ‘boolean hasNext()’ Returns ‘true’ if there are still elements
 *   in the
 *       -  ‘int peek()’ Returns the next element in the array “without”
 *   moving the
 *    “Note:” Each language may have a different implementation of the
 *   constructor and ‘Iterator’ , but they all support the ‘int next()’ and
 *   ‘boolean hasNext()’ functions.
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤ nums.length ≤ 1000’
 *   • ‘1 ≤ nums[i] ≤ 1000’
 *   • All the calls to ‘next’ and ‘peek’ are valid.
 *   • At most ‘1000’ calls will be made to ‘next’ , ‘hasNext’ , and ‘peek’ .
 *
 */

struct q284 : public ::testing::Test {
  // Leetcode answer here
   class Iterator {
   	struct Data;
   	Data* data;
   public:
   	Iterator(const vector<int>& nums);
   	Iterator(const Iterator& iter);
   
   	// Returns the next element in the iteration.
   	int next();
   
   	// Returns true if the iteration has more elements.
   	bool hasNext() const;
   };
   
  class PeekingIterator : public Iterator {
   private:
    vector<int> d_;
    vector<int>::iterator it;

   public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums), d_{nums}, it{d_.begin()} {
      // Initialize any member here.
      // **DO NOT** save a copy of nums and manipulate it directly.
      // You should only use the Iterator interface methods.
    }

    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
      return *it;
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
      return *it++;
    }

    bool hasNext() const {
      return it != d_.end();
    }
  };

  class Solution *solution;
};

TEST_F(q284, NOT_IMPLEMENT) {
   EXPECT_TRUE("NOT IMPLEMENT");
}