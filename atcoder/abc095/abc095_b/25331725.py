# detail: https://atcoder.jp/contests/abc095/submissions/25331725
n,x=map(int,input().split())
m=[int(input()) for _ in range(n)]
for i in range(n):
  x-=m[i]

m.sort()
print(x//m[0] + n)