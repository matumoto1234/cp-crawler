# detail: https://atcoder.jp/contests/abc068/submissions/22740066
n = int(input())

ans = 1
while 1:
  if ans * 2 >= n:
    print(ans)
    break
  ans *= 2