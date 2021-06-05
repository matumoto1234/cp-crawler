# detail: https://atcoder.jp/contests/code-formula-2014-quala/submissions/23191095
n=int(input())
ans=False
for i in range(1000):
  if i*i*i==n:
    ans=True
    
print('YES' if ans else 'NO')