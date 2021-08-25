# detail: https://atcoder.jp/contests/abc165/submissions/25331751
x=int(input())
money=100
ans=0
while money<x:
  money+=money//100
  ans+=1
  
print(ans)