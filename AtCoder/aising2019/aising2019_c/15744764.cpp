// detail: https://atcoder.jp/contests/aising2019/submissions/15744764
#include <bits/stdc++.h>
using namespace std;

bool rangeCheck(int y, int x, int h, int w) {
  if (y < 0 || x < 0 || y >= h || x >= w) {
    return false;
  } else {
    return true;
  }
}

void outputDone(int h, int w, vector<vector<int>> a) {
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      printf("%3d", a[i][j]);
    }
    cout << endl;
  }
  return;
}

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  for (int i = 0; i < h; i++) {
    cin >> s[i];
  }

  int ans = 0;
  vector<vector<int>> done(h, vector<int>(w, -1));
  stack<pair<int, int>> st;
  int dirY[] = {1, 0, -1, 0};
  int dirX[] = {0, 1, 0, -1};
  int cnt = 0;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (s[i][j] == '.' || done[i][j] != -1) {
        continue;
      }
      int blackCnt = 0, whiteCnt = 0;
      bool flag;
      pair<int, int> xy;
      xy.first = i;
      xy.second = j;
      st.push(xy);
      while (!st.empty()) {
        xy = st.top();
        st.pop();
        // printf("y=%d x=%d\n",xy.first,xy.second);
        if (done[xy.first][xy.second] != -1) {
          continue;
        }
        if (s[xy.first][xy.second] == '#') {
          flag = false;
        } else {
          flag = true;
        }
        flag ? whiteCnt++ : blackCnt++;
        done[xy.first][xy.second] = cnt;
        for (int k = 0; k < 4; k++) {
          int ny = xy.first + dirY[k];
          int nx = xy.second + dirX[k];
          bool flag2;

          if (!rangeCheck(ny, nx, h, w)) {
            continue;
          }
          if (done[ny][nx] != -1) {
            continue;
          }
          if (s[ny][nx] == '#') {
            flag2 = false;
          } else {
            flag2 = true;
          }
          if (flag == flag2) {
            continue;
          }
          pair<int, int> temp;
          temp.first = ny;
          temp.second = nx;
          st.push(temp);
        }
      }
      cnt++;
      ans += blackCnt * whiteCnt;
    }
  }
  // outputDone(h,w,done);
  cout << ans << endl;
  return 0;
}