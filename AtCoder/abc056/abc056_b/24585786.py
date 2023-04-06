# detail: https://atcoder.jp/contests/abc056/submissions/24585786
w,a,b=map(int,input().split())
if a<b:
  print(max(0,b-(a+w)))
else:
  print(max(0,a-(b+w)))