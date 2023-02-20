-- detail: https://atcoder.jp/contests/arc037/submissions/39069010
f x = if x < 80 then 80 - x else 0

main = do
  getLine
  a <- map read . words <$> getLine
  print $ sum $ map f a
