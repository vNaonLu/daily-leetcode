#include <gtest/gtest.h>
#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 146.
 *      LRU Cache
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   Design a data structure that follows the constraints of a “<a
 *   href="https://en.wikipedia.org/wiki/Cache_replacement_policies#LRU"
 *   target="_blank">Least Recently Used (LRU) cache</a>”
 *   Implement the ‘LRUCache’
 *       -  ‘LRUCache(int capacity)’ Initialize the LRU cache with
 *   “positive” size ‘capacity’
 *       -  ‘int get(int key)’ Return the value of the ‘key’ if the key
 *   exists, otherwise return ‘-1’
 *       -  ‘void put(int key, int value)’ Update the value of the ‘key’ if
 *   the ‘key’ exists. Otherwise, add the ‘key-value’ pair to the cache. If
 *   the number of keys exceeds the ‘capacity’ from this operation, “evict”
 *   the least recently used
 *   The functions<code data-stringify-type="code">get</code>and<code
 *   data-stringify-type="code">put</code>must each run in ‘O(1)’ average
 *   time complexity.
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤ capacity ≤ 3000’
 *   • ‘0 ≤ key ≤ 10⁴’
 *   • ‘0 ≤ value ≤ 10⁵’
 *   • At most 2 ‘× 10⁵’ calls will be made to ‘get’ and ‘put’ .
 *
 */

struct q146 : public ::testing::Test {
  // Leetcode answer here
  class LRUCache {
   private:
    unordered_map<int, list<pair<int, int>>::iterator> memos;
    list<pair<int, int>>                               cache;
    int                                                cap;

    void remove(int key) {
      auto it = memos.find(key);
      if (it != memos.end()) {
        cache.erase(it->second);
        memos.erase(key);
      }
    }

    void add(int key, int value) {
      remove(key);
      if (memos.size() == cap) {
        remove(cache.back().first);
      }
      cache.emplace_front(key, value);
      memos.emplace(key, cache.begin());
    }

   public:
    LRUCache(int capacity) : cap{capacity} {
    }

    int get(int key) {
      auto it = memos.find(key);
      if (it != memos.end()) {
        int res = (*it->second).second;
        add(key, res);
        return res;
      }
      return -1;
    }

    void put(int key, int value) {
      add(key, value);
    }
  };

  /**
   * Your LRUCache object will be instantiated and called as such:
   * LRUCache* obj = new LRUCache(capacity);
   * int param_1 = obj->get(key);
   * obj->put(key,value);
   */

  class LRUCache *lru_cache;
};

TEST_F(q146, sample_input01) {
  int capacity = 2;
  lru_cache = new LRUCache(capacity);
  lru_cache->put(1, 1);
  lru_cache->put(2, 2);
  EXPECT_EQ(lru_cache->get(1), 1);
  lru_cache->put(3, 3);
  EXPECT_EQ(lru_cache->get(2), -1);
  lru_cache->put(4, 4);
  EXPECT_EQ(lru_cache->get(1), -1);
  EXPECT_EQ(lru_cache->get(3), 3);
  EXPECT_EQ(lru_cache->get(4), 4);
  delete lru_cache;
}