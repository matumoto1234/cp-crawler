# detail: https://atcoder.jp/contests/abc110/submissions/43774823
vs = list(map(int,input().split()))
vs.sort()
vs.reverse()
print(vs[0]*10+vs[1] + vs[2])
