// detail: https://atcoder.jp/contests/atc002/submissions/14012057
#include <bits/stdc++.h>
using namespace std;

typedef struct {
  int x, y, cnt;
} xy;
int h, w, gx, gy, sx, sy;
int cnt = 0;
vector<string> s(500);
vector<vector<int>> cntMap(500, vector<int>(500, 0));
vector<vector<bool>> memo(500, vector<bool>(500));
vector<vector<bool>> done(500, vector<bool>(500, false));
vector<int> nextX = {0, 1, 0, -1};
vector<int> nextY = {1, 0, -1, 0};
queue<xy> que;
bool bfs(int x, int y) {
  if (x < 0 || y < 0 || x >= h || y >= w) {
    return false;
  }
  if (done[x][y]) {
    return memo[x][y];
  }
  done[x][y] = true;
  if (s[x][y] == '#') {
    return memo[x][y] = false;
  }
  if (x == gx - 1 && y == gy - 1) {
    cntMap[x][y] = cnt + 1;
    return memo[x][y] = true;
  }
  cnt++;
  if (x == sx - 1 && y == sy - 1) {
    cnt = 0;
  }
  cntMap[x][y] = cnt;
  for (int i = 0; i < 4; i++) {
    if (s[x + nextX[i]][y + nextY[i]] == '.') {
      xy temp;
      temp.x = x + nextX[i];
      temp.y = y + nextY[i];
      temp.cnt = cnt;
      que.push(temp);
    }
  }
  while (!que.empty()) {
    xy temp = que.front();
    que.pop();
    cnt = temp.cnt;
    if (bfs(temp.x, temp.y) == true) {
      return memo[x][y] = true;
    }
  }
  return false;
}

int main() {
  cin >> h >> w >> sx >> sy >> gx >> gy;
  for (int i = 0; i < h; i++) {
    cin >> s[i];
  }
  if (bfs(sx - 1, sy - 1) == true) {
    cout << cntMap[gx - 1][gy - 1] << endl;
  } else {
    cout << -1 << endl;
  }
  /*
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cout << done[i][j] << flush;
    }
    cout << endl;
  }*/
  return 0;
}