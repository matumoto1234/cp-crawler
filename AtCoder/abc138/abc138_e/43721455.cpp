// detail: https://atcoder.jp/contests/abc138/submissions/43721455
#include <bits/stdc++.h>
using namespace std;

bool all_chars_exists(string s, string t) {
  set<char> chars;
  for (auto ch: s) {
    chars.insert(ch);
  }

  for (auto ch: t) {
    if (chars.find(ch) == chars.end()) {
      return false;
    }
  }

  return true;
}

int main() {
  string s, t;
  cin >> s >> t;

  if (not all_chars_exists(s, t)) {
    cout << -1 << endl;
    return 0;
  }

  // first_index[i][j] := sのi番目以降で文字('a'+j)が現れる最左のindex
  // ただし、sのi番目以降に文字('a'+j)が現れない場合は-1
  vector<vector<int>> first_index(s.size() + 1, vector<int>(26, -1));
  for (int i = s.size() - 1; i >= 0; i--) {
    for (int j = 0; j < 26; j++) {
      first_index[i][j] = first_index[i + 1][j];
    }
    first_index[i][s[i] - 'a'] = i;
  }

  long long concat_cnt = 0;
  long long current_idx = 0;
  for (auto ch: t) {
    if (first_index[current_idx + 1][ch - 'a'] == -1) {
      concat_cnt++;
      current_idx = first_index[0][ch - 'a'];
    } else {
      current_idx = first_index[current_idx + 1][ch - 'a'];
    }
  }

  current_idx++; // to 1-indexed

  cout << concat_cnt * s.size() + current_idx << endl;
}
