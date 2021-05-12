# detail: https://atcoder.jp/contests/abc026/submissions/22530166
n = int(input())
ans = -101010101
for i in range(n):
  for j in range(n):
    if(i+j==n):
      ans = max(ans,i*j)

print(ans)