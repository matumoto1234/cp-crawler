# detail: https://atcoder.jp/contests/diverta2019/submissions/22757409
n = int(input())
s = [input() for _ in range(n)]

acnt = 0
bcnt = 0
bacnt = 0
cnt = 0
for i in range(n):
  if s[i][len(s[i]) - 1] == 'A':
    acnt += 1
  if s[i][0] == 'B':
    bcnt += 1
  if s[i][len(s[i]) - 1] == 'A' and s[i][0] == 'B':
    bacnt += 1

  cnt += s[i].count('AB')

if bacnt == bcnt and bacnt == acnt:
  cnt += bacnt - 1 
else:
  cnt += bacnt + min(acnt, bcnt)

print(cnt)