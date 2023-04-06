// detail: https://atcoder.jp/contests/abc088/submissions/13688766
#include <bits/stdc++.h>
using namespace std;

int h, w;
vector<vector<int>> done(500, vector<int>(500, 0));
vector<vector<bool>> memo(500, vector<bool>(500, false));
vector<int> nextX = {0, 1, 0, -1};
vector<int> nextY = {1, 0, -1, 0};
vector<string> c(500);
int cnt = 0, minCnt = INT_MAX;
stack<int> stackCnt;
vector<vector<int>> stacked(500, vector<int>(500, 0));

bool dfs(int x, int y) {
  // cout << "imanoX=" << x << " imanoY=" << y << endl;
  if (x < 0 || y < 0 || x >= h || y >= w || c[x][y] == '#') {
    return false;
  }
  if (c[x][y] == 's') {
    cnt = 0;
  }
  if (done[x][y] == 1) {
    return memo[x][y];
  }
  done[x][y] = 1;
  cnt++;
  if (c[x][y] == 'g') {
    if (cnt < minCnt) {
      minCnt = cnt;
      // cout << minCnt << endl;
    }
    return memo[x][y] = true;
  }

  if (stacked[x][y] == 1) {
    cnt = stackCnt.top();
    stackCnt.pop();
  } else {
    int flg = 0, cntFlg = 0;
    for (int i = 0; i < 4; i++) {
      if (nextX[i] + x < 0 || nextY[i] + y < 0 || nextX[i] + x >= h ||
          nextY[i] + y >= w) {
        continue;
      }
      if (c[nextX[i] + x][nextY[i] + y] == '.') {
        cntFlg++;
        if (cntFlg >= 2) {
          flg = 1;
          break;
        }
      }
    }
    if (flg == 1) {
      stackCnt.push(cnt);
      stacked[x][y] = 1;
    }
  }

  for (int i = 0; i < 4; i++) {
    if (dfs(x + nextX[i], y + nextY[i]) == true) {
      return memo[x][y] = true;
    }
  }
  return false;
}

int main() {
  int startX, startY;
  startX = startY = 0;
  cin >> h >> w;
  for (int i = 0; i < h; i++) {
    cin >> c[i];
  }
  c[0][0] = 's';
  c[h - 1][w - 1] = 'g';
  for (int i = 0; i < h; i++) {
    if (startX != 0) {
      break;
    }
    for (int j = 0; j < w; j++) {
      if (c[i][j] == 's') {
        startX = i;
        startY = j;
        break;
      }
    }
  }
  int ans = 2;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (c[i][j] == '.') {
        ans++;
      }
    }
  }
  if (dfs(startX, startY) == true) {
    cout << ans - minCnt<< endl;
  } else {
    cout << -1 << endl;
  }
  // cout << startX << " " << startY << endl;

  /*if (dfs(startX, startY) == true) {
    cout << "Yes" << endl;
  } else {
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        cout << done[i][j] << ' ' << flush;
      }
      cout << endl;
    }
    cout << "No" << endl;
  }*/
  return 0;
}