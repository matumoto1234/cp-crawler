-- detail: https://atcoder.jp/contests/abc286/submissions/39068516
import Data.List

main = do
  n <- readLn :: IO Int

  s <- getLine
  let ans = replace "na" "nya" s

  putStrLn ans

replace _ _ [] = []
replace x y str@(s:ss)
  | isPrefixOf x str = y ++ drop (length x) str
  | otherwise = s:replace x y ss