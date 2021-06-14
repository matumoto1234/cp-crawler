# detail: https://atcoder.jp/contests/abc087/submissions/23477957
x=int(input())
a=int(input())
b=int(input())
x-=a
x-=x//b*b
print(x)