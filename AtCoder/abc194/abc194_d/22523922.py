# detail: https://atcoder.jp/contests/abc194/submissions/22523922
n = int(input())

ans = 0.0
for i in range(1,n):
  ans += n / (n-i)

print(ans)
