# detail: https://atcoder.jp/contests/abc096/submissions/28157010
vs = list(map(int,input().split()))
k = int(input())
for _ in range(k):
  vs.sort(reverse=True)
  vs[0]*=2
  
ans = 0
for v in vs:
  ans += v
  
print(ans)