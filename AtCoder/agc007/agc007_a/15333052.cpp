// detail: https://atcoder.jp/contests/agc007/submissions/15333052
#include <bits/stdc++.h>
using namespace std;

int h, w;
vector<string> a(8);
int nextX[] = {0, -1, 0, 1};
int nextY[] = {-1, 0, 1, 0};
vector<vector<int>> arrived(8, vector<int>(8, 0));

bool range_check(int y, int x) {
  if (y < 0 || x < 0 || y >= h || x >= w) {
    return false;
  }
  return true;
}

bool dfs(int y, int x) {
  //cout << y << " " << x << endl;
  if (!range_check(y, x)) {
    //cout << 1 << endl;
    return false;
  }
  if (a[y][x] == '.') {
    //cout << 2 << endl;
    return false;
  }
  arrived[y][x] = 1;
  if (y == h - 1 && x == w - 1) {
    //cout << 3 << endl;
    return true;
  }
  for (int i = 0; i < 2; i++) {
    int ny = y + nextY[i], nx = x + nextX[i];
    if (range_check(ny, nx) && a[ny][nx] == '#' && arrived[ny][nx] == 0) {
      //cout << 4 << endl;
      return false;
    }
  }
  for (int i = 2; i < 4; i++) {
    int ny = y + nextY[i], nx = x + nextX[i];
    if (range_check(ny, nx) && a[ny][nx] == '#' && arrived[ny][nx] == 0) {
      if (!dfs(ny, nx)) {
        //cout << 5 << endl;
        return false;
      }

    }
  }
  //cout << 6 << endl;
  return true;
}
int main() {
  cin >> h >> w;
  for (int i = 0; i < h; i++) {
    cin >> a[i];
  }
  if (dfs(0, 0)) {
    cout << "Possible" << endl;
  } else {
    cout << "ImPossible" << endl;
  }/*
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      printf("%3d", arrived[i][j]);
    }
    cout << endl;
  }*/
  return 0;
}