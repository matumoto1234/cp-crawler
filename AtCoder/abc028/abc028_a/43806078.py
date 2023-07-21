# detail: https://atcoder.jp/contests/abc028/submissions/43806078
n = int(input())

if n <= 59:
  print("Bad")
elif n <= 89:
  print("Good")
elif n <= 99:
  print("Great")
else:
  print("Perfect")
  