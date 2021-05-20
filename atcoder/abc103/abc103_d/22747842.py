# detail: https://atcoder.jp/contests/abc103/submissions/22747842
n, m = map(int,input().split())

G = [-1 for _ in range(n)]

for i in range(m):
  a, b = map(int,input().split())
  a -= 1
  b -= 1
  G[b] = max(G[b], a)

ans = 0
erase_pos = -1
for i in range(n):
  if G[i] == -1:
    continue
  if erase_pos < G[i]:
    erase_pos = i - 1
    ans += 1

print(ans)