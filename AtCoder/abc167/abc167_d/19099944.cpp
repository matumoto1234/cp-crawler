// detail: https://atcoder.jp/contests/abc167/submissions/19099944
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 200000;

vector<ll> a(MAXN);
vector<ll> visit(MAXN,-1);
ll n, k;
void dfs(int idx,ll& cnt){
  if(visit[idx]!=-1){
    cnt=cnt-visit[idx];
    return;
  }
  visit[idx]=cnt;
  cnt++;
  dfs(a[idx],cnt);
}

int main() {
  cin >> n >> k;
  for(int i=0;i<n;i++){
      cin>>a[i];
      a[i]--;
  }
  ll cnt=0;
  dfs(0,cnt);
  ll remain=k%cnt;
  int idx=0;
  cnt=0;
  while(remain){
    idx=a[idx];
    remain--;
  }
  cout<<idx+1<<endl;
}