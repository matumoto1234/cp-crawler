# detail: https://atcoder.jp/contests/abc068/submissions/22740051
n = int(input())
if n < 2:
  print(0)
  exit()

two = 2
while 1:
  if two * 2 >= n:
    print(two)
    break
  two *= 2
