// detail: https://atcoder.jp/contests/abc079/submissions/15104334
#include <stdio.h>
#include <bitset>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  int a, b, c, d;
  int sum;
  string op(3,'+');
  cin >> d;
  a = d / 1000;
  b = d / 100 % 10;
  c = d / 10 % 10;
  d = d % 10;
  for (int i = 0; i < (1 << 3); i++) {
    bitset<3> tmp(i);
    if (tmp[0]) {
      op[0] = '+';
      sum = a + b;
    } else {
      op[0] = '-';
      sum = a - b;
    }
    if (tmp[1]) {
      op[1] = '+';
      sum += c;
    } else {
      op[1] = '-';
      sum -= c;
    }
    if (tmp[2]) {
      op[2] = '+';
      sum += d;
    } else {
      op[2] = '-';
      sum -= d;
    }
    if (sum == 7) {
      printf("%d%c%d%c%d%c%d=7\n", a, op[0], b, op[1], c, op[2], d);
      break;
    }
  }
  return 0;
}