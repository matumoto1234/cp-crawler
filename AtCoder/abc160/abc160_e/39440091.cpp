// detail: https://atcoder.jp/contests/abc160/submissions/39440091
#include <bits/stdc++.h>
using namespace std;

int main() {
  int x, y, a, b, c;
  cin >> x >> y >> a >> b >> c;

  vector<int> p(a);
  for (auto &pi: p) {
    cin >> pi;
  }

  vector<int> q(b);
  for (auto &qi: q) {
    cin >> qi;
  }

  vector<int> r(c);
  for (auto &ri: r) {
    cin >> ri;
  }

  sort(p.begin(), p.end(), greater<int>());
  sort(q.begin(), q.end(), greater<int>());
  sort(r.begin(), r.end(), greater<int>());

  priority_queue<int, vector<int>, greater<int>> pq;
  for (int i = 0; i < x; i++) {
    pq.push(p[i]);
  }
  for (int i = 0; i < y; i++) {
    pq.push(q[i]);
  }

  for (auto ri: r) {
    if (pq.top() < ri) {
      pq.pop();
      pq.push(ri);
    }
  }

  long long sum = 0;
  while (not pq.empty()) {
    sum += pq.top();
    pq.pop();
  }

  cout << sum << endl;
}
