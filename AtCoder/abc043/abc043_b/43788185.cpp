// detail: https://atcoder.jp/contests/abc043/submissions/43788185
#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;

  stack<char> display;
  for (auto ch: s) {
    if (ch == '0') {
      display.push('0');
    } else if (ch == '1') {
      display.push('1');
    } else {
      if (not display.empty()) {
        display.pop();
      }
    }
  }

  vector<int> buffer;
  while (not display.empty()) {
    buffer.push_back(display.top());
    display.pop();
  }
  reverse(buffer.begin(), buffer.end());

  for (auto v: buffer) {
    cout << (char)v;
  }
  cout << endl;
}