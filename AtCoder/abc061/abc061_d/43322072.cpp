// detail: https://atcoder.jp/contests/abc061/submissions/43322072
#include <bits/stdc++.h>
using namespace std;

namespace matumoto {
  using namespace std;
}

namespace matumoto {
  vector<pair<int, int>> adjacency_list_to_edges(const vector<vector<int>> &adj_list) {
    vector<pair<int, int>> edges;
    for (int v = 0; v < (int)adj_list.size(); v++) {
      for (const auto &to: adj_list[v]) {
        edges.emplace_back(v, to);
      }
    }
    return edges;
  }

  template <typename Cost>
  vector<tuple<int, int, Cost>> adjacency_list_to_edges(const vector<vector<pair<Cost, int>>> &adj_list) {
    vector<tuple<int, int, Cost>> edges;
    for (int v = 0; v < (int)adj_list.size(); v++) {
      for (const auto &[cost, to]: adj_list[v]) {
        edges.emplace_back(v, to, cost);
      }
    }
    return edges;
  }
} // namespace matumoto

namespace matumoto {
  using namespace std;
}

namespace matumoto {
#define assert_msg(expr, msg) (static_cast<bool>(expr) ? void(0) : assert_fail(__FILE__, __LINE__, #expr, msg))

  namespace {
    void assert_fail(const char *file, int line, const char expr_str[], string msg) {
      cerr << "File: " << file << "\n"
           << "Line: " << line << "\n"
           << "Assertion '" << expr_str << "' failed.\n"
           << "Message: " << msg << "\n";
      abort();
    }
  } // namespace
} // namespace matumoto

namespace matumoto {
  template <typename Cost>
  class BellmanFord {
    // adjacency list
    vector<vector<pair<Cost, int>>> adj_list_;
    vector<tuple<int, int, Cost>> edges_;
    vector<Cost> dists_;
    vector<int> prevs_;
    int start_, goal_;
    bool has_neg_cycle_, has_neg_cycle_to_goal_;

  public:
    BellmanFord(const vector<vector<pair<Cost, int>>> &adj_list, int start, int goal = -1)
      : adj_list_(adj_list),
        dists_(adj_list_.size(), inf()),
        prevs_(adj_list_.size(), -1),
        start_(start),
        goal_(goal),
        has_neg_cycle_(false),
        has_neg_cycle_to_goal_(false) {
      int n = adj_list_.size();
      if (goal_ == -1) {
        goal_ = n - 1;
      }
      assert_msg(0 <= start and start < n, "start:" + to_string(start) + " n:" + to_string(n));
      assert_msg(0 <= goal and goal < n, "goal:" + to_string(goal) + " n:" + to_string(n));

      edges_ = adjacency_list_to_edges(adj_list_);

      dists_[start] = 0;

      for (int i = 0; i < 2 * n; i++) {
        for (const auto &[from, to, cost]: edges_) {
          assert_msg(0 <= from and from < n, "from:" + to_string(from) + " n:" + to_string(n));
          assert_msg(0 <= to and to < n, "to:" + to_string(to) + " n:" + to_string(n));

          if (dists_[from] + cost >= dists_[to]) {
            continue;
          }

          if (i >= n - 1 and to == goal) {
            has_neg_cycle_ = true;
            has_neg_cycle_to_goal_ = true;
            return;
          } else if (i >= n - 1) {
            has_neg_cycle_ = true;
            dists_[to] = -inf();
          } else {
            dists_[to] = dists_[from] + cost;
          }
        }
      }
    }

    static constexpr Cost inf() {
      return numeric_limits<Cost>::max() / 4;
    }

    bool has_negative_cycle() const {
      return has_neg_cycle_;
    }

    bool has_negative_cycle_to_goal_() const {
      return has_neg_cycle_to_goal_;
    }

    Cost operator[](int k) {
      assert(0 <= k and k < (int)dists_.size());
      return dists_[k];
    }

    vector<int> restore(int to) {
      assert(0 <= to and to < (int)prevs_.size());
      vector<int> path;
      if (prevs_.at(to) == -1) {
        path.emplace_back(to);
        return path;
      }

      while (prevs_.at(to) != -1) {
        path.emplace_back(to);
        to = prevs_.at(to);
      }
      reverse(path.begin(), path.end());
      return path;
    }
  };
} // namespace matumoto

using namespace matumoto;

using ll = long long;

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<pair<ll, int>>> adj_list(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    ll c;
    cin >> a >> b >> c;

    a--;
    b--;

    adj_list[a].emplace_back(-c, b);
  }

  auto bf = BellmanFord<ll>(adj_list, 0, n - 1);
  if (bf.has_negative_cycle()) {
    cout << "inf" << endl;
  } else {
    cout << -bf[n - 1] << endl;
  }
}
