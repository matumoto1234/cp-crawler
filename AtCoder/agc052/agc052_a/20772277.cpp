// detail: https://atcoder.jp/contests/agc052/submissions/20772277
#include <bits/stdc++.h>
using namespace std;
#define range(i, l, r) for (int i = (int)(l); i < (int)(r); (i) += 1)
#define rrange(i, l, r) for (int i = (int)(r)-1; i >= (int)(l); (i) -= 1)
template <typename T1, typename T2> inline void chmax(T1 &a, T2 b) { a = (a > b ? a : b); }
template <typename T1, typename T2> inline void chmin(T1 &a, T2 b) { a = (a < b ? a : b); }
template <typename T1, typename T2> ostream &operator<<(ostream &os,const pair<T1,T2> &p) { os<<p.first<<' '<<p.second; return os;}
template <typename T> ostream &operator<<(ostream &os,const vector<T> &v) { range(i,0,v.size()) {os<<(i?" ":"")<<v[i];} return os;}
using ull = unsigned long long;
using ll = long long;
using PL = pair<ll, ll>;
using P = pair<int, int>;
const ll INF64 = INT64_MAX / 2;
const int INF32 = INT32_MAX / 2;
const char newl = '\n';

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t;
  cin>>t;
  
  range(i,0,t){
    int n;
    cin>>n;

    bool flg=true;
    string s;
    range(j,0,3){
      cin>>s;
      if(flg&&s.front()==s.back()){
        cout<<s+s.back()<<newl;
        flg=false;
      }
    }
    if(flg){
      cout<<string(n,'0')+"1"+string(n,'0')<<newl;
    }
  }
}

/*
0110
-> 01100110
1001
-> 10011001
1100
-> 11001100

1.左端と右端が0のとき
2.左端と右端が1のとき
3.左端が1で右端が0のとき
4.左端が0で右端が1のとき

1のとき 11011 or 01000 or 00010 など
2のとき 00100 or 10111 or 11101 など
3のとき 00100 or 11011 など

3は気にしなくていい

1と2が同時に来たとき
01100 or 10011

1だけのとき
01100

2だけのとき
10011
*/