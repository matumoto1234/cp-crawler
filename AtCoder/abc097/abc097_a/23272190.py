# detail: https://atcoder.jp/contests/abc097/submissions/23272190
a,b,c,d=map(int,input().split())
print('Yes' if abs(a-b)<=d or abs(b-c)<=d or abs(a-c)<=d else 'No')