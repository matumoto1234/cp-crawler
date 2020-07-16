// detail: https://atcoder.jp/contests/atc002/submissions/15267686
#include <bits/stdc++.h>
using namespace std;

/*流れ
4方向を探索、行けるところがあったらqueueに追加
queueから座標を取り出し、取り出した座標に移動
もし、ゴールだったら終了
*/

int R, C, sy, sx, gy, gx;
vector<string> c(50);

typedef struct {
  int y, x;
} zahyo;

vector<int> nextY = {0, 1, 0, -1};
vector<int> nextX = {1, 0, -1, 0};
queue<zahyo> node;
vector<vector<int>> cnt(50, vector<int>(50, -2));

int bfs(int y, int x, int cur) {
  if (y < 0 || x < 0 || y >= R || x >= C) {
    return -1;
  }
  if (c[y][x] == '#') {
    return cnt[y][x] = -1;
  }
  if (y == gy && x == gx) {
    return cnt[y][x];
  }
  for (int i = 0; i < 4; i++) {
    if (c[y + nextY[i]][x + nextX[i]] == '.' &&
        cnt[y + nextY[i]][x + nextX[i]] == -2) {
      zahyo tmp;
      tmp.y = y + nextY[i];
      tmp.x = x + nextX[i];
      node.push(tmp);
      cnt[tmp.y][tmp.x] = cur + 1;
    }
  }
  while (!node.empty()) {
    zahyo tmp = node.front();
    node.pop();
    return bfs(tmp.y, tmp.x, cnt[tmp.y][tmp.x]);
  }
  return 0;
}

int main() {
  cin >> R >> C >> sy >> sx >> gy >> gx;
  gy--;
  gx--;
  sy--;
  sx--;
  cnt[sy][sx] = 0;
  for (int i = 0; i < R; i++) {
    cin >> c[i];
  }
  cout << bfs(sy, sx, 0) << endl;
  /*
  for (int i = 0; i < R;i++){
    for (int j = 0; j < C;j++){
      printf("%3d", cnt[i][j]);
      j < C - 1 ? cout << " " << flush : cout << endl;
    }
  }*/
  return 0;
}