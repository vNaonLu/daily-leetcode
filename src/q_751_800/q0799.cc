#include <gtest/gtest.h>
#include <iostream>
#include <vector>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 799.
 *      Champagne Tower
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   We stack glasses in a pyramid, where the “first” row has ‘1’ glass,
 *   the “second” row has ‘2’ glasses, and so on until the 100ᵗʰ row. Each
 *   glass holds one cupof
 *   Then, some champagne is poured into the first glass at the top. When
 *   the topmost glass is full, any excess liquid poured will fall equally
 *   to the glass immediately to the left and right of it. When those
 *   glasses become full, any excess champagne will fall equally to the
 *   left and right of those glasses, and so on. (A glass at the bottom row
 *   has its excess champagne fall on the
 *   For example, after one cup of champagne is poured, the top most glass
 *   is full. After two cups of champagne are poured, the two glasses on
 *   the second row are half full. After three cups of champagne are
 *   poured, those two cups become full - there are 3 full glasses total
 *   now. After four cups of champagne are poured, the third row has the
 *   middle glass half full, and the two outside glasses are a quarter
 *   full, as pictured
 *   Now after pouring some non-negative integer cups of champagne, return
 *   how full the ‘jᵗʰ’ glass in the ‘iᵗʰ’ row is (both ‘i’ and ‘j’ are
 *   
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘0 ≤poured ≤ 10⁹’
 *   • ‘0 ≤ query_glass ≤ query_row< 100’
 *
 */

struct q799 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
   public:
    double champagneTower(int poured, int query_row, int query_glass) {
      vector<vector<double>> tower(101, vector<double>(101, 0.));
      tower.front().front() = poured;
      for (int i = 0; i <= query_row; ++i) {
        for (int j = 0; j <= i; ++j) {
          double liq = (tower[i][j] - 1.0) / 2.0;
          if (liq > 0) {
            tower[i + 1][j] += liq;
            tower[i + 1][j + 1] += liq;
          }
        }
      }
      return min(1.0, tower[query_row][query_glass]);
    }
  };

  class Solution *solution;
};

TEST_F(q799, sample_input01) {
  solution = new Solution();
  int poured = 1;
  int query_row = 1;
  int query_glass = 1;
  double exp = 0.00000;
  double act = solution->champagneTower(poured, query_row, query_glass);
  EXPECT_DOUBLE_EQ(act, exp);
  delete solution;
}

TEST_F(q799, sample_input02) {
  solution = new Solution();
  int poured = 2;
  int query_row = 1;
  int query_glass = 1;
  double exp = 0.50000;
  double act = solution->champagneTower(poured, query_row, query_glass);
  EXPECT_DOUBLE_EQ(act, exp);
  delete solution;
}

TEST_F(q799, sample_input03) {
  solution = new Solution();
  int poured = 100000009;
  int query_row = 33;
  int query_glass = 17;
  double exp = 1.00000;
  double act = solution->champagneTower(poured, query_row, query_glass);
  EXPECT_DOUBLE_EQ(act, exp);
  delete solution;
}