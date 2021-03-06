#include <gtest/gtest.h>
#include <iostream>
#include <vector>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 705.
 *      Design HashSet
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   Design a HashSet without using any built-in hash table
 *   Implement ‘MyHashSet’
 *       -  ‘void add(key)’ Inserts the value ‘key’ into the
 *       -  ‘bool contains(key)’ Returns whether the value ‘key’ exists in
 *   the HashSet or
 *       -  ‘void remove(key)’ Removes the value ‘key’ in the HashSet. If
 *   ‘key’ does not exist in the HashSet, do nothing.
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘0 ≤ key ≤ 10⁶’
 *   • At most ‘10⁴’ calls will be made to ‘add’ , ‘remove’ , and ‘contains’ .
 *
 */

struct q705 : public ::testing::Test {
  // Leetcode answer here
  class MyHashSet {
   private:
    vector<int> data_;

   public:
    MyHashSet() : data_(1000001, -1) {
    }

    void add(int key) {
      data_[key] = 1;
    }

    void remove(int key) {
      data_[key] = -1;
    }

    bool contains(int key) {
      return data_[key] == 1;
    }
  };

  class MyHashSet *my_hash_set;
};

TEST_F(q705, sample_input01) {
  my_hash_set = new MyHashSet();
  my_hash_set->add(1);
  my_hash_set->add(2);
  EXPECT_EQ(my_hash_set->contains(1), true);
  EXPECT_EQ(my_hash_set->contains(3), false);
  my_hash_set->add(2);
  EXPECT_EQ(my_hash_set->contains(2), true);
  my_hash_set->remove(2);
  EXPECT_EQ(my_hash_set->contains(2), false);
  delete my_hash_set;
}