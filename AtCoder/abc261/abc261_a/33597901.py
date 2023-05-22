# detail: https://atcoder.jp/contests/abc261/submissions/33597901
l1, r1, l2, r2 = list(map(int,input().split()))

ans = 0 

for i in range(100 + 1):
  if l1 <= i < r1 and l2 <= i < r2:
    ans+=1
    
print(ans)