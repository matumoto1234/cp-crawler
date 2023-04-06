# detail: https://atcoder.jp/contests/abc087/submissions/23191222
n=int(input())
a=[list(map(int,input().split())) for _ in range(2)]

sum=[[0 for _ in range(n)] for i in range(2)]
sum[0][0]=a[0][0]
sum[1][0]=sum[0][0]+a[1][0]
for i in range(1,n):
  sum[0][i]+=sum[0][i-1]+a[0][i]
  sum[1][i]+=max(sum[1][i-1],sum[0][i])+a[1][i]
  
print(sum[1][n-1])
