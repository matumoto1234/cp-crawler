# detail: https://atcoder.jp/contests/tenka1-2017-beginner/submissions/22933310
s = input()
ans = 0
for i in range(len(s)):
  if s[i] == '1':
    ans += 1
print(ans)