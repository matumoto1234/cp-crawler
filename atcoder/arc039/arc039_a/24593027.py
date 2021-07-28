# detail: https://atcoder.jp/contests/arc039/submissions/24593027
a,b=input().split()
na="9"+a[1:]
nb="1"+b[1:]
print(max(int(na)-int(b),int(a)-int(nb)))