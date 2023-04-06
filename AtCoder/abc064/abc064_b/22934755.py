# detail: https://atcoder.jp/contests/abc064/submissions/22934755
n = int(input())
a = list(map(int,input().split()))
a.sort()
print(a[n-1]-a[0])