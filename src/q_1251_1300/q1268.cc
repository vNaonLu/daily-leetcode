#include <array>
#include <gtest/gtest.h>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 1268.
 *       Search Suggestions System
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   You are given an array of strings ‘products’ and a string ‘searchWord’
 *   Design a system that suggests at most three product names from
 *   ‘products’ after each character of ‘searchWord’ is typed. Suggested
 *   products should have common prefix with ‘searchWord’ . If there are
 *   more than three products with a common prefix return the three
 *   lexicographically minimums
 *   Return “a list of lists of the suggested products after each character
 *   of ” ‘searchWord’ “ is typed” .
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤ products.length ≤ 1000’
 *   • ‘1 ≤ products[i].length ≤ 3000’
 *   • ‘1 ≤ sum(products[i].length) ≤ 2 × 10⁴’
 *   • All the strings of ‘products’ are “unique” .
 *   • ‘products[i]’ consists of lowercase English letters.
 *   • ‘1 ≤ searchWord.length ≤ 1000’
 *   • ‘searchWord’ consists of lowercase English letters.
 *
 */

struct q1268 : public ::testing::Test {
  // Leetcode answer here
class Solution {
private:
    struct Trie {
        array<unique_ptr<Trie>, 26> next;
        bool is_end = {false};
        vector<string> suggested;
    };
    
    template <typename iterator>
    unique_ptr<Trie> build_trie(iterator beg, iterator end) {
        auto res = make_unique<Trie>();
        while (beg != end) {
            auto &sv = *beg++;
            Trie *p = res.get();
            
            for (auto &c : sv) {
                auto &next = p->next[c-'a'];
                if (nullptr == next) {
                    next = make_unique<Trie>();
                }
                if (next->suggested.size() < 3) {
                    next->suggested.emplace_back(sv);
                }
                p = next.get();
            }
            
            p->is_end = true;
        }
        
        return res;
    }
    
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> res;
        sort(products.begin(), products.end());
        auto dict = build_trie(products.begin(), products.end());
        auto p = dict.get();
        
        for (auto &c : searchWord) {
            auto next = p->next[c-'a'].get();
            if (nullptr != next)  {
                res.emplace_back(next->suggested);
            } else break;
            p = next;
        }
        res.resize(searchWord.size());
        
        return res;
    }
};

  class Solution *solution;
};

TEST_F(q1268, sample_input01) {
  solution = new Solution();
  vector<string> products = {"mobile", "mouse", "moneypot", "monitor", "mousepad"};
  string searchWord = "mouse";
  vector<vector<string>> exp = {{"mobile", "moneypot", "monitor"}, {"mobile", "moneypot", "monitor"}, {"mouse", "mousepad"}, {"mouse", "mousepad"}, {"mouse", "mousepad"}};
  vector<vector<string>> act = solution->suggestedProducts(products, searchWord);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q1268, sample_input02) {
  solution = new Solution();
  vector<string> products = {"havana"};
  string searchWord = "havana";
  vector<vector<string>> exp = {{"havana"}, {"havana"}, {"havana"}, {"havana"}, {"havana"}, {"havana"}};
  vector<vector<string>> act = solution->suggestedProducts(products, searchWord);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q1268, sample_input03) {
  solution = new Solution();
  vector<string> products = {"bags", "baggage", "banner", "box", "cloths"};
  string searchWord = "bags";
  vector<vector<string>> exp = {{"baggage", "bags", "banner"}, {"baggage", "bags", "banner"}, {"baggage", "bags"}, {"bags"}};
  vector<vector<string>> act = solution->suggestedProducts(products, searchWord);
  EXPECT_EQ(act, exp);
  delete solution;
}