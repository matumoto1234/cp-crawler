# detail: https://atcoder.jp/contests/abc196/submissions/23268041
n=int(input())
ans=0
for i in range(1,2*10**6):
  s=str(i)
  s+=s
  if int(s)<=n:
    ans+=1
    
print(ans)