# detail: https://atcoder.jp/contests/arc015/submissions/22243932
n = int(input())

cnt = [0]*6

for i in range(n):
  a, b = map(float, input().split())
  if a >= 35:
    cnt[0] += 1
  elif a >= 30:
    cnt[1] += 1
  elif a >= 25:
    cnt[2] += 1
  if b >= 25:
    cnt[3] += 1
  if b < 0 and a >= 0:
    cnt[4] += 1
  if a < 0:
    cnt[5] += 1

print(*cnt)