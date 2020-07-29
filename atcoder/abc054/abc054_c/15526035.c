// detail: https://atcoder.jp/contests/abc054/submissions/15526035
#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> graph(8);
int dfs(int vertex,int count,int arrived){
  arrived += 1 << vertex;
  //cout << "arrived=" << arrived << " count=" << count << " vertex="<<vertex<<endl;
  if(count==n-1){
    bool flg = true;
    for (int i = 0; i < n;i++){
      if(arrived>>i&0){
        flg = false;
      }
    }
    if(flg){
      return 1;
    }else{
      return 0;
    }
  }
  int sum = 0;
  for (int i = 0; i < graph[vertex].size();i++){
    //cout << "graph="<<graph[vertex][i] << endl;
    if(((arrived>>graph[vertex][i])&1)==0){
      sum += dfs(graph[vertex][i], count + 1, arrived);
    }
  }
  return sum;
}

int main(){
  cin >> n >> m;
  for (int i = 0; i < m;i++){
    int a,b;
    cin >> a>>b;
    a--;
    b--;
    graph[a].emplace_back(b);
    graph[b].emplace_back(a);
  }
  cout << dfs(0, 0, 0) << endl;
  return 0;
}