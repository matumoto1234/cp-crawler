// detail: https://atcoder.jp/contests/abc329/submissions/47798169
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> a(m);
  for (auto &v : a) {
    cin >> v;
    v--;
  }

  map<int, set<int>> votes_to_candidates;
  map<int, int> candidate_to_votes;

  auto move_next_votes = [&](int candidate) -> void {
    const auto &votes = candidate_to_votes[candidate];

    votes_to_candidates[votes].erase(candidate);

    if (votes_to_candidates[votes].empty()) {
      votes_to_candidates.erase(votes);
    }

    votes_to_candidates[votes + 1].insert(candidate);
    candidate_to_votes[candidate]++;
  };

  for (auto candi : a) {
    move_next_votes(candi);

    auto [_, candidates] = *votes_to_candidates.rbegin();
    cout << *candidates.begin() + 1 << "\n";
  }
}
