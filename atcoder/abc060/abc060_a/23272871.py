# detail: https://atcoder.jp/contests/abc060/submissions/23272871
a,b,c=input().split()
print('YES' if a[len(a)-1]==b[0] and b[len(b)-1]==c[0] else 'NO')