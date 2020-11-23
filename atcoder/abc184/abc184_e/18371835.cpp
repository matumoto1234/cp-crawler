// detail: https://atcoder.jp/contests/abc184/submissions/18371835
#include <algorithm>
#include <iostream>
#include <queue>
#include <cctype>
using namespace std;
using ll = long long;
using P = pair<int,int>;

bool range_check(int h,int w,int y,int x){
  return !(y<0||x<0||y>=h||x>=w);
}

int main() {
  int h,w;
  cin>>h>>w;
  vector<vector<char>> s(h,vector<char>(w));
  vector<vector<int>> alpha(26);
  P start,goal;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin>>s[i][j];
      if(s[i][j]=='S'){
        start.first=i;
        start.second=j;
      }
      if(s[i][j]=='G'){
        goal.first=i;
        goal.second=j;
      }
      if(islower(s[i][j])){
        int idx=s[i][j]-'a';
        alpha[idx].push_back(i*w+j);
      }
    }
  }


  int dy[]={0,1,0,-1};
  int dx[]={1,0,-1,0};
  vector<vector<int>> arrived(h,vector<int>(w,0));
  queue<P> Q;
  Q.push(start);
  
  while(!Q.empty()){
    P now=Q.front();
    Q.pop();

    //cerr<<now.first<<' '<<now.second<<endl;

    if(islower(s[now.first][now.second])){
      int idx=s[now.first][now.second]-'a';
      for(auto n:alpha[idx]){
        int ny=n/w;
        int nx=n%w;
        if(ny==now.first&&nx==now.second){
          continue;
        }
        //cerr<<"arrived[ny][nx]="<<arrived[ny][nx]<<endl;
        if(arrived[ny][nx]!=0) break;
        arrived[ny][nx]=arrived[now.first][now.second]+1;
        //cerr << (char)(idx + 'a') << endl;
        Q.emplace(ny,nx);
      }
    }
    
    for(int i=0;i<4;i++){
      int ny=dy[i]+now.first;
      int nx=dx[i]+now.second;

      if(!range_check(h,w,ny,nx)) continue;
      if(s[ny][nx]=='#') continue;
      if(arrived[ny][nx]) continue;

      Q.emplace(ny,nx);
      arrived[ny][nx]=arrived[now.first][now.second]+1;
    }
  }
  if(arrived[goal.first][goal.second]==0){
    cout<<-1<<endl;
    return 0;
  }
  cout<<arrived[goal.first][goal.second]<<endl;
  return 0;
}