# detail: https://atcoder.jp/contests/abc153/submissions/23079726
n, k = map(int,input().split())
h = list(map(int,input().split()))

list.sort(h, reverse=True)

for i in range(min(k, n)):
  h[i] = 0

ans = 0
for i in range(n):
  ans += h[i]
  
print(ans)