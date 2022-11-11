# detail: https://atcoder.jp/contests/abc253/submissions/36380174
a, b, c = map(int,input().split())
vals = [a, b, c]
vals.sort()
print("Yes" if vals[1] == b else "No")