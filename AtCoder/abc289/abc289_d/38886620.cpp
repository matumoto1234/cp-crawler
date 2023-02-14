// detail: https://atcoder.jp/contests/abc289/submissions/38886620
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int n;
vector<int> n_array;
int m;
vector<int> m_array;
set<int> m_set;
int x;
string answer = "No";
set<int> get_sum;

void loop(int sum) {
  if (get_sum.find(sum) != get_sum.end()) {
    return;
  }

  get_sum.insert(sum);
  if (sum == x) {
    answer = "Yes";
    return;
  }

  if (sum > x || m_set.find(sum) != m_set.end()) {
    return;
  }

  for (int i = 0; i < n; i++) {
    loop(sum + n_array[i]);
  }
}

int main() {
  cin >> n;
  n_array.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> n_array[i];
  }
  cin >> m;
  m_array.resize(m);
  for (int i = 0; i < m; i++) {
    cin >> m_array[i];
    m_set.insert(m_array[i]);
  }
  cin >> x;

  loop(0);

  cout << answer << endl;
  return 0;
}
