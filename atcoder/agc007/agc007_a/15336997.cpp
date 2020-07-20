// detail: https://atcoder.jp/contests/agc007/submissions/15336997
#include<bits/stdc++.h>
using namespace std;

int h, w;
vector<string> a(8);
int nextY[] = {1, 0};
int nextX[] = {0, 1};

/*In range->true, Out range->false*/
bool range_check(int y,int x){
  if(y<0||x<0||y>=h||x>=w){
    return false;
  }
  return true;
}

bool dfs(int y,int x){
  if(y==h-1&&x==w-1){
    return true;
  }
  int count = 0;
  for (int i = 0; i < 2;i++){
    int ny = y + nextY[i], nx = x + nextX[i];
    if(range_check(ny,nx)){
      if(a[ny][nx]=='#'){
        count++;
      }
    }
  }
  if(count!=1){
    return false;
  }
  else{
    for (int i = 0; i < 2;i++){
      int ny = y + nextY[i], nx = x + nextX[i];
      if(range_check(ny,nx)){
        if(a[ny][nx]=='#'){
          return dfs(ny, nx);
        }
      }
    }
  }
  return false;
}

int main(){
  cin >> h >> w;
  for (int i = 0; i < h;i++){
    cin >> a[i];
  }
  if(dfs(0,0)){
    cout << "Possible" << endl;
  }else{
    cout << "Impossible" << endl;
  }
  return 0;
}