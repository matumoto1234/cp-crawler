// detail: https://atcoder.jp/contests/agc007/submissions/15333944
#include <bits/stdc++.h>
using namespace std;

int h, w;
vector<string> a(8);
int nextX[] = { 0, 1};
int nextY[] = {1, 0};
vector<vector<int>> arrived(8, vector<int>(8, 0));

bool range_check(int y, int x) {
  if (y < 0 || x < 0 || y >= h || x >= w) {
    return false;
  }
  return true;
}

bool dfs(int y, int x) {
  // cout << y << " " << x << endl;
  if (!range_check(y, x)) {
    return false;
  }
  if (arrived[y][x]) {
    return false;
  }
  arrived[y][x] = 1;
  if (y == h - 1 && x == w - 1) {
    return true;
  }
  bool flg = false;
  for (int i = 0; i < 2; i++) {
    int ny = y + nextY[i], nx = x + nextX[i];
    if (range_check(ny, nx)) {
      if (a[ny][nx] == '#') {
        if (arrived[ny][nx] == 0) {
          flg = dfs(ny, nx);
        }
      }
    }
  }
  return flg;
}
int main() {
  cin >> h >> w;
  for (int i = 0; i < h; i++) {
    cin >> a[i];
  }
  if(dfs(0,0)){
    for (int i = 0;i<h;i++){
      for (int j = 0; j < w;j++){
        if(s[i][j]=='#'){
          if(arrived[i][j]==0){
            cout << "Impossible" << endl;
            return 0;
          }
        }
      }
    }
    cout << "Possible" << endl;
  }else{
    cout << "Impossible" << endl;
  }
  return 0;
}