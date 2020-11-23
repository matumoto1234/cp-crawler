// detail: https://atcoder.jp/contests/abc184/submissions/18375069
#include<iostream>
#include<vector>
#include<queue>
#include<cstdint>
using namespace std;
const int INF = INT32_MAX/4;

struct zahyo{
  int y,x;
  zahyo(){};
  zahyo(const int& y,const int& x):y(y),x(x){}
};

int h,w;

bool range_check(int y,int x){
  return (0<=y&&y<h&&0<=x&&x<w);
}

int stov(int y,int x){
  return y*w+x;
}

int main(){
  cin>>h>>w;
  vector<vector<char>> s(h,vector<char>(w));
  vector<vector<int>> alpha(26);
  zahyo S,G;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin>>s[i][j];
      if(s[i][j]=='S'){
        S.y=i;
        S.x=j;
      }
      if(s[i][j]=='G'){
        G.y=i;
        G.x=j;
      }
      if(islower(s[i][j])){
        int idx=s[i][j]-'a';
        alpha[idx].push_back(stov(i,j));
      }
    }
  }

  int dy[]={1,0,-1,0};
  int dx[]={0,1,0,-1};
  vector<int> arrived(h*w,INF);
  vector<bool> used(26,false);
  queue<zahyo> Q;
  Q.push(S);
  arrived[stov(S.y,S.x)]=0;
  while(!Q.empty()){
    zahyo n=Q.front();
    Q.pop();

    for(int i=0;i<4;i++){
      int ny=n.y+dy[i];
      int nx=n.x+dx[i];

      if(range_check(ny,nx)==false) continue;
      if(s[ny][nx]=='#') continue;
      if(arrived[stov(ny,nx)]!=INF) continue;

      Q.emplace(ny,nx);
      arrived[stov(ny,nx)]=arrived[stov(n.y,n.x)]+1;
    }

    int idx=s[n.y][n.x]-'a';
    if(islower(s[n.y][n.x])&&used[idx]==false){
      used[idx]=true;
      //cerr<<s[n.y][n.x]<<endl;
      for(int e:alpha[idx]){
        //cerr<<"arrived[e]:"<<arrived[e]<<endl;
        if(arrived[stov(n.y,n.x)]+1<arrived[e]){
          arrived[e]=arrived[stov(n.y,n.x)]+1;
          Q.emplace(e/w,e%w);
        }
      }
    }
  }
  if(arrived[stov(G.y,G.x)]==INF){
    cout<<-1<<endl;
    return 0;
  }
  cout<<arrived[stov(G.y,G.x)]<<endl;
  return 0;
}