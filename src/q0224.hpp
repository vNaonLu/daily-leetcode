
#ifndef LEETCODE_Q224_H__
#define LEETCODE_Q224_H__
#include <cctype>
#include <iostream>
#include <stack>
#include <string>

namespace l224 {
using namespace std;

/**
  * this file is generated by gquestion.py
  *
  * 224. Basic Calculator
  *
  * Given a string s representing a valid expression,
  * implement a basic calculator to evaluate it, and
  * return the result of the evaluation .
  * “Note:“ You are “not“ allowed to use any
  * built-in function which evaluates strings as mathematical
  * expressions, such as eval() .
  *
  * Constraints:
  * -  1 <= s.length <= 3* 10^(5) 
  * -  s consists of digits, ';+'; , ';-'; , ';('; , ';)'; , and '; '; .
  * -  s represents a valid expression.
  * -  ';+'; is not used as a unary operation.
  * -  ';-'; could be used as a unary operation but it has to be inside parentheses.
  * - There will be no two consecutive operators in the input.
  * - Every number and running calculation will fit in a signed 32-bit integer.
  *
*/
class Solution {
 public:
  int calculate(string s) {
    int res = 0, val = 0;
    int sign = 1;
    stack<int> cal;
    for (int i = 0; i < s.size(); ++i) {
      while (i < s.size() && isdigit(s[i])) {
        val = val * 10 + (s[i] - '0');
        ++i;
      }
      res += val * sign;
      val = 0;

      if (s[i] == '+') {
        sign = 1;
      } else if (s[i] == '-') {
        sign = -1;
      } else if (s[i] == '(') {
        cal.push(res);
        cal.push(sign);
        res = 0;
        sign = 1;
      } else if (s[i] == ')') {
        res *= cal.top();
        cal.pop();
        res += cal.top();
        cal.pop();
      }
    }
    return res;
  }
};
}  // namespace l224
#endif