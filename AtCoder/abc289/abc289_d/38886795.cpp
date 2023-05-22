// detail: https://atcoder.jp/contests/abc289/submissions/38886795
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> n_array;

int m;
// 0: not exists, 1: exists
vector<int> m_array(200000, 0);

int x;
string answer = "No";

// 0: not exists, 1: exists
vector<int> get_sum(200000, 0);

void loop(int sum) {
  if (get_sum[sum]) {
    return;
  }

  get_sum[sum] = 1;
  if (sum == x) {
    answer = "Yes";
    return;
  }

  if (sum > x || m_array[sum]) {
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
  for (int i = 0; i < m; i++) {
    int mi;
    cin >> mi;
    
    m_array[mi] = 1;
  }
  cin >> x;

  loop(0);

  cout << answer << endl;
  return 0;
}
