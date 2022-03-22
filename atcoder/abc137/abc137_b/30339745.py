# detail: https://atcoder.jp/contests/abc137/submissions/30339745
k, x = map(int,input().split())
l = x - k + 1
r = x + k

is_first = False
for i in range(l,r):
  if is_first:
    print(" ", end="")
  print(i, end="")
  is_first = True
  
print()