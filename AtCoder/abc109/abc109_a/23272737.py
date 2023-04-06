# detail: https://atcoder.jp/contests/abc109/submissions/23272737
a,b=map(int,input().split())
ans=False
for c in range(1,3+1):
  if a*b*c%2:
    ans=True
    
print('Yes' if ans else 'No')