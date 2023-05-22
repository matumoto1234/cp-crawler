// detail: https://atcoder.jp/contests/ahc009/submissions/30417359
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


int main(){
  string s = "";
  
  RandomNumberGenerator gen;
  
  for(int i = 0; i < 80; i++) {
    int dir = gen(2);
    char c = dir_to_char(dir);
    s += c;
  }
  
  for(int i = 0; i < 120; i++) {
    int dir = gen(4);
    char c = dir_to_char(dir);
    s += c;
  }
  
  cout << s << endl;
}