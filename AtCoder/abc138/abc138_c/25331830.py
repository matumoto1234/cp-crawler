# detail: https://atcoder.jp/contests/abc138/submissions/25331830
from collections import deque

n=int(input())
v=list(map(int,input().split()))
v.sort()

d=deque()
d.append(v[0])
for i in range(1,n):
  nv=d.pop()
  d.append((nv+v[i])/2)
  
print(d.pop())