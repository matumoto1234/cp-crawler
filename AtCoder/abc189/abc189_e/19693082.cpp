// detail: https://atcoder.jp/contests/abc189/submissions/19693082
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Point{
  int x,y;
};

struct operate{
  int num,p;
  operate():p(0){}
};

template <typename T>
struct Mattrix{
  int H,W;
  vector<vector<T>> dat;
  
  Mattrix(){}
  Mattrix(vector<vector<T>> v):dat(v),H((int)v.size()),W((int)v[0].size()){}
  Mattrix(Point p):dat(3,vector<T>(1,1)),H(3),W(1){
    dat[0][0]=p.x;
    dat[1][0]=p.y;
  }

  Mattrix operator*(Mattrix a){
    int h=a.dat.size();
    int w=a.dat[0].size();
    Mattrix res(vector<vector<T>>(H,vector<T>(w,0)));
    if(W!=h) return res;
    for(int i=0;i<H;i++){
      for(int j=0;j<w;j++){
        for(int k=0;k<h;k++){
          res[i][j]+=dat[i][k]*a[k][j];
        }
      }
    }
    return res;
  }

  vector<T>& operator[](int i){ return dat[i]; }
};

template <typename T>
ostream& operator<<(ostream &os,Mattrix<T> m){
  for(int i=0;i<m.H;i++){
    for(int j=0;j<m.W;j++){
      if(j) os<<' ';
      os<<m[i][j];
    }
    os<<'\n';
  }
  return os;
}

template <typename T>
Mattrix<T> init_mattrix(int H,int W,int idx){
  vector<vector<T>> init(H,vector<T>(W,0));
  for(int i=0;i<H;i++){
    init[i][i]=1;
  }
  if( 0<=idx&&idx<H && 0<=idx&&idx<W ) init[idx][idx]*=-1;
  //init[idx][N-1]=2*p;
  return Mattrix<T>(init);
}

int main() {
  // input
  int n;
  cin >> n;
  vector<Point> ps(n);
  for(auto &p:ps){
    cin>>p.x>>p.y;
  }


  // calculate
  int m;
  cin>>m;

  Mattrix<ll> matX=init_mattrix<ll>(3,3,0);
  Mattrix<ll> matY=init_mattrix<ll>(3,3,1);
  vector<Mattrix<ll>> accum_mat(m+1,Mattrix<ll>(vector<vector<ll>>(3,vector<ll>(1,1))));

  for(int i=0;i<m;i++){
    int op;
    cin>>op;
    if(op<=2) continue;

    int p;
    cin>>p;
    if(op==3){
      matX.dat[0][2]=2*p;
      accum_mat[i+1]=matX*accum_mat[i];
      matX.dat[0][2]=0;
    }else{
      matY.dat[0][2]=2*p;
      accum_mat[i+1]=matY*accum_mat[i];
      matY.dat[0][2]=0;
    }
  }

  // output
  int q;
  cin>>q;
  for(int i=0;i<q;i++){
    int a,b;
    cin>>a>>b;
    b--;
    cout<<accum_mat[i]*Mattrix<ll>(ps[b])<<endl;
  }
}