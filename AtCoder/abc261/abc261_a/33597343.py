# detail: https://atcoder.jp/contests/abc261/submissions/33597343
a = list(map(int,input().split()))

a.sort()

print(a[1]-a[0] + a[3]-a[2])

