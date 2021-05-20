# detail: https://atcoder.jp/contests/diverta2019/submissions/22757329
n = int(input())
s = [input() for _ in range(n)]

acnt = 0
bcnt = 0
allsame = True
cnt = 0
for i in range(n):
  if s[i][len(s[i]) - 1] == 'A':
    acnt += 1
  if s[i][0] == 'B':
    bcnt += 1

  if (s[i][len(s[i]) - 1] == 'A') != (s[i][0] == 'B'):
    allsame = False

  cnt += s[i].count('AB')

if allsame == True:
  cnt += min(acnt,bcnt) - 1
else:
  cnt += min(acnt, bcnt)
print(cnt)