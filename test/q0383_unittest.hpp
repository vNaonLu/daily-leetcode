
#ifndef Q383_UNITTEST_H__
#define Q383_UNITTEST_H__
#include <gtest/gtest.h>

#include "../src/q0383.hpp"
using namespace std;

/**
  * this file is generated by gquestion.py
  *
  * 383. Ransom Note
  *
  * Given two stings ransomNote and magazine , return
  * true if ransomNote can be constructed from
  * magazine and false otherwise.
  * Each letter in magazine can only be used once in
  * ransomNote .
  *
  * Constraints:
  * -  1 <= ransomNote.length, magazine.length <= 10^(5) 
  * -  ransomNote and magazine consist of lowercase English letters.
  *
*/

TEST(q383, sample_input01) {
  string ransomNote = "a";
  string magazine = "b";
  bool exp = false;
  l383::Solution solver;
  EXPECT_EQ(solver.canConstruct(ransomNote, magazine), exp);
}

TEST(q383, sample_input02) {
  string ransomNote = "aa";
  string magazine = "ab";
  bool exp = false;
  l383::Solution solver;
  EXPECT_EQ(solver.canConstruct(ransomNote, magazine), exp);
}

TEST(q383, sample_input03) {
  string ransomNote = "aa";
  string magazine = "aab";
  bool exp = true;
  l383::Solution solver;
  EXPECT_EQ(solver.canConstruct(ransomNote, magazine), exp);
}

#endif