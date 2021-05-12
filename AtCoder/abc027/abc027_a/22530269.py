# detail: https://atcoder.jp/contests/abc027/submissions/22530269
import collections

ls = list(map(int,input().split()))

cnt = collections.Counter(ls)

for i in range(3):
  if cnt[ls[i]] != 2:
    print(ls[i])
    break
 