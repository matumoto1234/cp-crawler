# detail: https://atcoder.jp/contests/abc063/submissions/22881656
s = input()

dic = {}

ans = True
for i in range(len(s)):
  if s[i] in dic == True:
    ans = False
  dic[s[i]] = 1

if ans == True:
  print("yes")
else:
  print("no")