// detail: https://atcoder.jp/contests/abc235/submissions/39491505
#include <bits/stdc++.h>
using namespace std;

namespace graph_library {
  using namespace std;
}

namespace graph_library {
  template <class T>
  class EdgeInterface {
    // TODO: Do implement constructor
    // UnWeightedEdge(from, to)
    // WeightedEdge  (from, to, cost)
  public:
    int &from() {
      return static_cast<T &>(this)->from();
    }

    const int &from() const {
      return static_cast<T &>(this)->from();
    }

    int &to() {
      return static_cast<T &>(this)->to();
    }

    const int &to() const {
      return static_cast<T &>(this)->to();
    }
  };

  template <typename Cost>
  class WeightedEdge: public EdgeInterface<WeightedEdge<Cost>> {
  private:
    int from_, to_;
    Cost cost_;

  public:
    WeightedEdge() = default;
    WeightedEdge(int to): to_(to) {}
    WeightedEdge(int to, Cost cost): to_(to), cost_(cost) {}
    WeightedEdge(int from, int to, Cost cost): from_(from), to_(to), cost_(cost) {}

    bool operator<(const WeightedEdge<Cost> &rhs) const {
      if (cost_ != rhs.cost_)
        return cost_ < rhs.cost_;

      if (from_ != rhs.from_)
        return from_ < rhs.from_;

      return to_ < rhs.to_;
    }

    bool operator<=(const WeightedEdge<Cost> &rhs) const {
      if (cost_ != rhs.cost_)
        return cost_ <= rhs.cost_;

      if (from_ != rhs.from_)
        return from_ <= rhs.from_;

      return to_ <= rhs.to_;
    }

    bool operator>(const WeightedEdge<Cost> &rhs) const {
      if (cost_ != rhs.cost_)
        return cost_ > rhs.cost_;

      if (from_ != rhs.from_)
        return from_ > rhs.from_;

      return to_ > rhs.to_;
    }

    bool operator>=(const WeightedEdge<Cost> &rhs) const {
      if (cost_ != rhs.cost_)
        return cost_ >= rhs.cost_;

      if (from_ != rhs.from_)
        return from_ >= rhs.from_;

      return to_ >= rhs.to_;
    }

    bool operator!=(const WeightedEdge<Cost> &rhs) const {
      return from_ != rhs.from_ or to_ != rhs.to_ or cost_ != rhs.cost_;
    }

    int &from() {
      return from_;
    }

    const int &from() const {
      return from_;
    }

    int &to() {
      return to_;
    }

    const int &to() const {
      return to_;
    }

    Cost &cost() {
      return cost_;
    }

    const Cost &cost() const {
      return cost_;
    }

    template <typename T>
    friend ostream &operator<<(ostream &os, const WeightedEdge<T> &rhs) {
      os << rhs.from_ << ' ' << rhs.to_ << ' ' << rhs.cost_;
      return os;
    }
  };

  class UnWeightedEdge: public EdgeInterface<UnWeightedEdge> {
  private:
    int from_, to_;

  public:
    UnWeightedEdge() = default;
    UnWeightedEdge(int to_): to_(to_) {}
    UnWeightedEdge(int from_, int to_): from_(from_), to_(to_) {}

    bool operator<(const UnWeightedEdge &rhs) const {
      if (from_ != rhs.from_)
        return from_ < rhs.from_;

      return to_ < rhs.to_;
    }

    bool operator<=(const UnWeightedEdge &rhs) const {
      if (from_ != rhs.from_)
        return from_ <= rhs.from_;

      return to_ <= rhs.to_;
    }

    bool operator>(const UnWeightedEdge &rhs) const {
      if (from_ != rhs.from_)
        return from_ > rhs.from_;

      return to_ > rhs.to_;
    }

    bool operator>=(const UnWeightedEdge &rhs) const {
      if (from_ != rhs.from_)
        return from_ >= rhs.from_;

      return to_ >= rhs.to_;
    }

    bool operator!=(const UnWeightedEdge &rhs) const {
      return from_ != rhs.from_ or to_ != rhs.to_;
    }

    int &from() {
      return from_;
    }

    const int &from() const {
      return from_;
    }

    int &to() {
      return to_;
    }

    const int &to() const {
      return to_;
    }

    friend ostream &operator<<(ostream &os, const UnWeightedEdge &rhs) {
      os << rhs.from_ << ' ' << rhs.to_;
      return os;
    }
  };

  template <typename Cost>
  using WeightedEdges = vector<WeightedEdge<Cost>>;

  using UnWeightedEdges = vector<UnWeightedEdge>;


  template <class Edge, bool is_extended_edge = is_base_of_v<EdgeInterface<Edge>, Edge>>
  class Graph {
    static_assert(is_extended_edge, "Edge is not extended edge interface class.");
  };

  template <class Edge>
  class Graph<Edge, true> {
  public:
    using Edges = vector<Edge>;

  private:
    Edges edges_;
    vector<Edges> graph_;
    int size_;

  public:
    Graph() = default;
    Graph(int N): graph_(N), size_(N) {}

    int size() const {
      return size_;
    }

    void add_edge(const Edge &edge) {
      const int &from = edge.from();
      graph_.at(from).push_back(edge);
      edges_.push_back(edge);
    }

    Edge get_edge(int k) const {
      return edges_.at(k);
    }

    Edges edges() const {
      return edges_;
    }

    void pop_back_edge() {
      assert(not edges_.empty());

      const Edge e = edges_.back();
      edges_.pop_back();
      graph_.at(e.from()).pop_back();
    }

    vector<Edges> graph() const {
      return graph_;
    }
  };

  template <typename Cost>
  using WeightedGraph = Graph<WeightedEdge<Cost>>;

  using UnWeightedGraph = Graph<UnWeightedEdge>;
} // namespace graph_library

namespace graph_library {
  template <typename Cost>
  struct Dijkstra {
    using Edge = WeightedEdge<Cost>;
    vector<Cost> ds;
    vector<int> bs;

    static constexpr Cost inf() {
      return numeric_limits<Cost>::max() / 2;
    }

    Dijkstra(WeightedGraph<Cost> g, int start): ds(g.size(), inf()), bs(g.size(), -1) {
      assert(0 <= start and start < g.size());
      auto G = g.graph();
      priority_queue<Edge, vector<Edge>, greater<Edge>> Q;
      ds[start] = 0;
      Q.emplace(start, ds[start]);

      while (!Q.empty()) {
        Edge p = Q.top();
        int v = p.to();
        Q.pop();

        if (ds[v] < p.cost())
          continue;

        for (Edge e: G[v]) {
          int to = e.to();
          Cost cost = e.cost();
          if (ds[to] > ds[v] + cost) {
            ds[to] = ds[v] + cost;
            bs[to] = v;
            Q.emplace(to, ds[to]);
          }
        }
      }
    }

    Cost operator[](int k) {
      return ds.at(k);
    }

    vector<int> restore(int to) {
      vector<int> res;
      if (bs[to] == -1) {
        res.emplace_back(to);
        return res;
      }
      while (to != -1) {
        res.emplace_back(to);
        to = bs[to];
      }
      reverse(res.begin(), res.end());
      return res;
    }
  };
} // namespace graph_library
using namespace graph_library;

long long operation1(long long x, long long a) {
  return a * x;
}

int operation2(int x) {
  string s = to_string(x);
  char back = s.back();
  s.pop_back();
  return stoi(back + s);
}

int main() {
  int a, n;
  cin >> a >> n;

  constexpr int limit = 1e6;
  WeightedGraph<long long> graph(2 * limit);
  for (int x = 1; x <= limit; x++) {
    if (operation1(x, a) <= limit) {
      graph.add_edge(WeightedEdge<long long>(x, operation1(x, a), 1));
    }
    graph.add_edge(WeightedEdge<long long>(x, operation2(x), 1));
  }

  Dijkstra<long long> d(graph, 1);
  if (d[n] == Dijkstra<long long>::inf()) {
    cout << -1 << endl;
  } else {
    cout << d[n] << endl;
  }
}
