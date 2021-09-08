# detail: https://atcoder.jp/contests/abc051/submissions/25696740
def print_dir(cnt, ch):
  for i in range(cnt):
    print(ch,end="")

sx,sy,tx,ty=map(int,input().split())

dx=tx-sx
dy=ty-sy

print_dir(dx,'R')
print_dir(dy,'U')
print_dir(dx,'L')
print_dir(dy,'D')

print_dir(1,'D')
print_dir(dx+1,'R')
print_dir(dy+1,'U')
print_dir(1,'L')
# arrived the goal

print_dir(1,'U')
print_dir(dx+1,'L')
print_dir(dy+1,'D')
print_dir(1,'R')

