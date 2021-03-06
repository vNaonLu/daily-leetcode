#include <gtest/gtest.h>
#include <iostream>
#include <vector>

using namespace std;

/**
 * This file is generated by leetcode_add.py
 *
 * 1710.
 *       Maximum Units on a Truck
 *
 * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
 *
 *   You are assigned to put some amount of boxes onto “one truck” . You
 *   are given a 2D array ‘boxTypes’ , where ‘boxTypes[i] =
 *   [numberOfBoxesᵢ, numberOfUnitsPerBoxᵢ]’
 *       -  ‘numberOfBoxesᵢ’ is the number of boxes of type ‘i’
 *       -  ‘numberOfUnitsPerBoxᵢ’ ⎽( )is the number of units in each box
 *   of the type ‘i’
 *   You are also given an integer ‘truckSize’ , which is the “maximum”
 *   number of “boxes” that can be put on the truck. You can choose any
 *   boxes to put on the truck as long as the numberof boxes does not
 *   exceed ‘truckSize’
 *   Return “the “maximum” total number of “units” that can be put on the
 *   truck.” 
 *
 * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
 *
 *   • ‘1 ≤ boxTypes.length ≤ 1000’
 *   • ‘1 ≤ numberOfBoxesᵢ, numberOfUnitsPerBoxᵢ ≤ 1000’
 *   • ‘1 ≤ truckSize ≤ 10⁶’
 *
 */

struct q1710 : public ::testing::Test {
  // Leetcode answer here
  class Solution {
  public:
    int maximumUnits(vector<vector<int>> &boxTypes, int truckSize) {
      sort(boxTypes.begin(), boxTypes.end(), [](auto &x, auto &y) {
        return x[1] == y[1] ? x[0] < y[0] : x[1] > y[1];
      });
      int res = 0;
      for (auto box : boxTypes) {
        auto size = box[0],
             unit = box[1];
        int put_size = min(size, truckSize);
        res += put_size * unit;
        truckSize -= put_size;
      }

      return res;
    }
  };

  class Solution *solution;
};

TEST_F(q1710, sample_input01) {
  solution = new Solution();
  vector<vector<int>> boxTypes = {{1, 3}, {2, 2}, {3, 1}};
  int truckSize = 4;
  int exp = 8;
  int act = solution->maximumUnits(boxTypes, truckSize);
  EXPECT_EQ(act, exp);
  delete solution;
}

TEST_F(q1710, sample_input02) {
  solution = new Solution();
  vector<vector<int>> boxTypes = {{5, 10}, {2, 5}, {4, 7}, {3, 9}};
  int truckSize = 10;
  int exp = 91;
  int act = solution->maximumUnits(boxTypes, truckSize);
  EXPECT_EQ(act, exp);
  delete solution;
}