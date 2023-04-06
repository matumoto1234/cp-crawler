# detail: https://atcoder.jp/contests/abc159/submissions/23273723
s=input()
print('Yes' if s==s[::-1] and s[0:(len(s)-1)//2]==s[0:(len(s)-1)//2][::-1]  and s[(len(s)+3)//2-1::]==s[(len(s)+3)//2-1::][::-1] else 'No')
