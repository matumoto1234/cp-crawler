// detail: https://atcoder.jp/contests/abc197/submissions/21323295
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
using Pll = pair<ll, ll>;
using P = pair<int, int>;
const ll INF64 = INT64_MAX / 2;
const int INF32 = INT32_MAX / 2;
const char newl = '\n';

struct Point{
  long double x,y;
  Point(){}
  Point(long double x,long double y):x(x),y(y){}
  friend ostream& operator<<(ostream &os,Point p) { os<<p.x<<' '<<p.y; return os;}
};

Point rotR(Point origin,Point p,long double rad){
  p.x-=origin.x;
  p.y-=origin.y;
  Point res=Point(p.x*cosl(rad)+p.x*sinl(rad),-p.y*sinl(rad)+p.y*cosl(rad));
  res.x+=origin.x;
  res.y+=origin.y;
  return res;
}

Point rotL(Point origin,Point p,long double rad){
  p.x-=origin.x;
  p.y-=origin.y;
  Point res(p.x*cos(rad)-p.y*sin(rad),p.x*sin(rad)+p.y*cos(rad));
  res.x+=origin.x;
  res.y+=origin.y;
  return res;
}

int main() {
  int n;
  cin>>n;
  Point p1,p2;
  cin>>p1.x>>p1.y;
  cin>>p2.x>>p2.y;

  Point temp=p1;

  p2.x-=p1.x;
  p2.y-=p1.y;
  p1.x=0.0;
  p1.y=0.0;


  Point center = Point(p2.x/2.0,p2.y/2.0);
  long double rad=(360.0*M_PI)/(180.0*n);
  p1=rotL(center,p1,rad);
  p1.x+=temp.x;
  p1.y+=temp.y;

  cout<<fixed<<setprecision(10);
  cout<<p1<<endl;
}