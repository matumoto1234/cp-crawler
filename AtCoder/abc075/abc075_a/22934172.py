# detail: https://atcoder.jp/contests/abc075/submissions/22934172
from collections import Counter
abc = list(map(int,input().split()))
cnt = Counter(abc)
for key in cnt.keys():
  if cnt[key] == 1:
    print(key)