// detail: https://atcoder.jp/contests/arc111/submissions/19284202
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MAXV = 400000;

int main() {
  ll n;
  cin >> n;
  using P = pair<ll,ll>;
  vector<P> a(n);
  vector<ll> cnt(MAXV+1,0);
  for(int i=0;i<n;i++){
    cin>>a[i].first>>a[i].second;
    cnt[a[i].first]++;
    cnt[a[i].second]++;
  }

  int ans=0;
  vector<bool> used(MAXV,false);
  for(int i=0;i<n;i++){
    int fv=a[i].first;
    int sv=a[i].second;
    if(used[fv]&&used[sv]){
      continue;
    }
    if(used[fv]){
      ans++;
      used[sv]=true;
      continue;
    }else if(used[sv]){
      ans++;
      used[fv]=true;
      continue;
    }

    int fst=cnt[a[i].first];
    int snd=cnt[a[i].second];
    if(fst<snd){
      ans++;
      used[fv]=true;
      continue;
    }else{
      ans++;
      used[sv]=true;
      continue;
    }
  }
  cout<<ans<<endl;
  return 0;
}