# detail: https://atcoder.jp/contests/abc178/submissions/24215330
n=int(input())
mod=10**9+7
ans=pow(10,n,mod)-2*pow(9,n,mod)+pow(8,n,mod)
ans%=mod
ans+=mod
ans%=mod
print(ans)