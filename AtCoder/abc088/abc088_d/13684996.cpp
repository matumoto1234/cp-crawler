// detail: https://atcoder.jp/contests/abc088/submissions/13684996
#include <bits/stdc++.h>
using namespace std;

int h, w, cnt = 0, cntMin = INT_MAX, ret = INT_MAX;
vector<string> s(50);
vector<vector<int>> cntMap(50, vector<int>(50, 0));
vector<vector<bool>> done(50, vector<bool>(50, false));
vector<vector<bool>> flgStack(50, vector<bool>(50, false));
vector<int> nextX = {0, 1, 0, -1};
vector<int> nextY = {1, 0, -1, 0};
stack<int> stackNode;

int dfs(int x, int y) {
  if (x < 0 || y < 0 || x >= h || y >= w) {
    return -1;
  }
  if (done[x][y] == true) {
    return cntMap[x][y];
  }
  if (s[x][y] == '#') {
    return cntMap[x][y] = -1;
  }
  done[x][y] = true;
  cnt++;
  if (x == h - 1 && y == w - 1) {
    if (cntMin > cnt) {
      cntMin = cnt;
    }
    return cntMap[x][y] = cntMin;
  }
  
  if (flgStack[x][y] == true) {
    cnt = stackNode.top();
    stackNode.pop();
  } else {
    int flgNode = 0;
    for (int i = 0; i < 4; i++) {
      if (x + nextX[i] < 0 || y + nextY[i] < 0 || x + nextX[i] >= h ||
          y + nextY[i] >= w) {
        continue;
      }
      if (s[x + nextX[i]][y + nextY[i]] == '.' &&
          done[x + nextX[i]][y + nextY[i]] == false) {
        flgNode++;
      }
    }
    if (flgNode >= 2) {
      flgStack[x][y] = true;
      stackNode.push(cnt);
    }
  }

  for (int i = 0; i < 4; i++) {
    int temp = dfs(x + nextX[i], y + nextY[i]);
    if (temp != -1) {
      return cntMap[x][y] = cnt;
    }
  }
  return -1;
}

int main() {
  cin >> h >> w;
  for (int i = 0; i < h; i++) {
    cin >> s[i];
  }
  int ans = 0, temp;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (s[i][j] == '.') {
        ans++;
      }
    }
  }
  temp = dfs(0, 0);
  if (temp == -1) {
    cout << -1 << endl;
  } else {
    cout << ans - temp << endl;
  }
  return 0;
}