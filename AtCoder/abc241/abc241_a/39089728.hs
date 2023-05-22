-- detail: https://atcoder.jp/contests/abc241/submissions/39089728
main = do
  a <- map read . words <$> getLine :: IO [Int]
  print $ a!!(a!!(a!!0))
