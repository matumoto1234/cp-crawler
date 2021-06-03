# detail: https://atcoder.jp/contests/abc169/submissions/23156234
a,b = input().split()
c,d = b.split('.')
e=int(c)*100+int(d)
ans=int(a)
ans*=e
print(ans//100)