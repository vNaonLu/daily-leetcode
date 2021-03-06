#include <gtest/gtest.h>
#include <iostream>
#include <vector>

using namespace std;

/**
 * This file is generated by leetcode_add.py v1.0
 *
 * 717.
 *      1-bit and 2-bit Characters
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   We have two special
 *       - The first character can be represented by one bit ‘0’
 *       - The second character can be represented by two bits ( ‘10’ or
 *   ‘11’
 *   Given a binary array ‘bits’ that ends with ‘0’ , return ‘true’ if the
 *   last character must be a one-bit character.
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤ bits.length ≤ 1000’
 *   • ‘bits[i]’ is either ‘0’ or ‘1’ .
 *
 */

struct q717 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   public:
    bool isOneBitCharacter(vector<int>& bits) {
      for (int i = 0; i < bits.size();) {
        if (i == bits.size() - 1) return true;
        i = bits[i] ? i + 2 : i + 1;
      }
      return false;
    }
  };

  class Solution *solution;
};

TEST_F(q717, sample_input01) {
  solution = new Solution();
  vector<int> bits = {1, 0, 0};
  bool exp = true;
  EXPECT_EQ(solution->isOneBitCharacter(bits), exp);
  delete solution;
}

TEST_F(q717, sample_input02) {
  solution = new Solution();
  vector<int> bits = {1, 1, 1, 0};
  bool exp = false;
  EXPECT_EQ(solution->isOneBitCharacter(bits), exp);
  delete solution;
}