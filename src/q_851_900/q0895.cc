#include <gtest/gtest.h>
#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 895.
 *      Maximum Frequency Stack
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   Design a stack-like data structure to push elements to the stack and
 *   pop the most frequent element from the
 *   Implement the ‘FreqStack’
 *       -  ‘FreqStack()’ constructs an empty frequency
 *       -  ‘void push(int val)’ pushes an integer ‘val’ onto the top of
 *   the
 *       -  ‘int pop()’ removes and returns the most frequent element in
 *   the
 *           - If there is a tie for the most frequent element, the element
 *   closest to the stack's top is removed and
 *       	
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘0 ≤ val ≤ 10⁹’
 *   • At most ‘2 × 10⁴’ calls will be made to ‘push’ and ‘pop’ .
 *   • It is guaranteed that there will be at least one element in the stack before calling ‘pop’ .
 *
 */

struct q895 : public ::testing::Test {
  // Leetcode answer here
  class FreqStack {
   private:
    unordered_map<int, int>        freq;
    unordered_map<int, stack<int>> group;
    int                            maxfreq;

   public:
    FreqStack() {
      maxfreq = 0;
    }

    void push(int val) {
      int count = ++freq[val];
      maxfreq = max(count, maxfreq);

      group[count].push(val);
    }

    int pop() {
      auto &stk = group[maxfreq];
      auto res = stk.top();
      stk.pop();
      --freq[res];

      if (stk.empty()) {
        --maxfreq;
      }

      return res;
    }
  };

  /**
   * Your FreqStack object will be instantiated and called as such:
   * FreqStack* obj = new FreqStack();
   * obj->push(val);
   * int param_2 = obj->pop();
   */

  class FreqStack *freq_stack;
};

TEST_F(q895, sample_input01) {
  freq_stack = new FreqStack();
  freq_stack->push(5);
  freq_stack->push(7);
  freq_stack->push(5);
  freq_stack->push(7);
  freq_stack->push(4);
  freq_stack->push(5);
  EXPECT_EQ(freq_stack->pop(), 5);
  EXPECT_EQ(freq_stack->pop(), 7);
  EXPECT_EQ(freq_stack->pop(), 5);
  EXPECT_EQ(freq_stack->pop(), 4);
  delete freq_stack;
}