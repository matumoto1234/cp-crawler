// detail: https://atcoder.jp/contests/ahc009/submissions/30418125
#include <bits/stdc++.h>
using namespace std;

struct RandomNumberGenerator {
  mt19937 mt;

  RandomNumberGenerator() : mt(chrono::steady_clock::now().time_since_epoch().count()) {}

  int operator()(int a, int b) { // [a, b)
    uniform_int_distribution< int > dist(a, b - 1);
    return dist(mt);
  }

  int operator()(int b) { // [0, b)
    return (*this)(0, b);
  }
};


char dir_to_char(int dir){
  assert(0 <= dir < 4);
  switch(dir) {
    case 0:
      return 'R';
    case 1:
      return 'D';
    case 2:
      return 'U';
    case 3:
      return 'L';
    default:
      return 'R';
  }
}

int max_min_diff(const vector<int> &vs) {
  int mx = *max_element(begin(vs), end(vs));
  int mn = *min_element(begin(vs), end(vs));
  
  return mx - mn;
}

int min_element_index(const vector<int> &vs) {
  auto itr = min_element(begin(vs), end(vs));
  return distance(begin(vs), itr);
}

int main(){
  constexpr int limit = 200;
  constexpr int pre_limit = 60;
  constexpr int post_limit = limit - pre_limit;
  constexpr int allow_diff = 4;
  string s = "";
  
  RandomNumberGenerator gen;
  
  for(int i = 0; i < pre_limit; i++) {
    int dir = gen(2);
    char c = dir_to_char(dir);
    s += c;
  }
  
  vector<int> dir_counter = {0, 0, 0, 0};
  
  for(int i = 0; i < post_limit; i++) {
    int dir = gen(4);
    int diff = max_min_diff(dir_counter);
    
    if (diff > allow_diff) {
      dir = min_element_index(dir_counter);
    }
    
    char c = dir_to_char(dir);
    s += c;
  }
  
  cout << s << endl;
}