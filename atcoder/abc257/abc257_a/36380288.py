# detail: https://atcoder.jp/contests/abc257/submissions/36380288
n, x = map(int, input().split())
x -= 1
x = x // n
print(chr(ord("a") + x))