# detail: https://atcoder.jp/contests/abc238/submissions/29071874
n=int(input())
a = 1
cnt = 0

while a<n*n:
  a*=2
  cnt+=1
  if cnt>=n:
    break
    
print('Yes' if a>n else 'No')