# detail: https://atcoder.jp/contests/cf17-final/submissions/22930897
s = input()

ans = False
if s == "KIHBR": ans = True
if s == "KIHBRA": ans = True
if s == "KIHBAR": ans = True
if s == "KIHBARA": ans = True
if s == "KIHABR": ans = True
if s == "KIHABRA": ans = True
if s == "KIHABAR": ans = True
if s == "KIHABARA": ans = True
if s == "AKIHBR": ans = True
if s == "AKIHBRA": ans = True
if s == "AKIHBAR": ans = True
if s == "AKIHBARA": ans = True
if s == "AKIHABR": ans = True
if s == "AKIHABRA": ans = True
if s == "AKIHABAR": ans = True
if s == "AKIHABARA": ans = True
  
if ans:
  print("YES")
else:
  print("NO")