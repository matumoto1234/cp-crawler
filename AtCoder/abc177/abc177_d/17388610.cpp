// detail: https://atcoder.jp/contests/abc177/submissions/17388610
#include<bits/stdc++.h>
using namespace std;

class UnionFind{
public:
  
  vector<int> size;
  vector<int> parent;

  UnionFind(int len):size(len),parent(len){
    for(int i=0;i<len;i++){
      size[i]=1;
      parent[i]=i;
    }
  }

  bool merge(int x,int y){
    int rx=root(x),ry=root(y);
    if(rx==ry){
      return false;
    }

    if(size[rx]<size[ry]){
      swap(rx,ry);
    }
    parent[ry]=rx;
    size[rx]+=size[ry];
    return true;
  }

  int root(int x){
    if(x==parent[x]){
      return x;
    }
    return root(parent[x]);
  }

  int retSize(int x){
    return size[root(x)];
  }

  bool isSame(int x,int y){
    return root(x)==root(y);
  }
};

int main(){
  int n,m;
  cin>>n>>m;
  UnionFind tree(n);

  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    a--;
    b--;
    tree.merge(a,b);
  }

  int maxs=0;
  for(int i=0;i<n;i++){
    maxs=max(maxs,tree.retSize(i));
  }
  cout<<maxs<<endl;
  return 0;
}