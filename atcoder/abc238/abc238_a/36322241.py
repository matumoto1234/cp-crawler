# detail: https://atcoder.jp/contests/abc238/submissions/36322241
n = int(input())

yes_list = [false for _ in range(30)]
for i in range(30):
  yes_list[i] = 2**i > i*i
  
if n >= 30:
  print("Yes")
else:
  print("Yes" if yes_list[n] else "No")
    