// detail: https://atcoder.jp/contests/abc289/submissions/38886264
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> n_array;
int m;
vector<int> m_array;
int x;
string answer = "No";
vector<int> get_sum;

void loop(int sum) {
  size_t sum_index = lower_bound(get_sum.begin(), get_sum.end(), sum) - get_sum.begin();
  if (sum_index < get_sum.size() && get_sum[sum_index] == sum) {
    return;
  }

  get_sum.push_back(sum);
  if (sum == x) {
    answer = "Yes";
    return;
  }

  size_t m_index = lower_bound(m_array.begin(), m_array.end(), sum) - m_array.begin();
  if (sum > x || (m_index < m_array.size() && m_array[m_index] == sum)) {
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
  }
  cin >> x;

  loop(0);

  cout << answer << endl;
  return 0;
}
