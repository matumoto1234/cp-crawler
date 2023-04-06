# detail: https://atcoder.jp/contests/abc022/submissions/24601179
n,s,t=map(int,input().split())
w=int(input())
a=[int(input()) for _ in range(n-1)]
a.insert(0,0)
ans=0
for i in range(n):
  w+=a[i]
  if s<=w<=t:
    ans+=1
    
print(ans)