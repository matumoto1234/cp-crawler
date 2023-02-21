-- detail: https://atcoder.jp/contests/abc253/submissions/39090125
module Main where
 
import Debug.Trace
--import Data.Bits
--import Data.List
--import Data.Char
--import Data.Maybe
import Data.Function
--import Data.Ratio
--import Data.Bifunctor
--import Data.Foldable
--import Data.Tuple
--import Data.Complex
--import Data.STRef
import Data.Array.ST
--import qualified Data.Array as A
import qualified Data.Array.Unboxed as AU
--import qualified Data.Vector as V
--import qualified Data.Vector.Mutable as VM
--import qualified Data.Vector.Unboxed as VU
--import qualified Data.Vector.Unboxed.Mutable as VUM
--import qualified Data.Vector.Algorithms.Intro as VAI
--import qualified Data.Vector.Algorithms.Search as VAS
import Control.Monad
import Control.Monad.ST
--import qualified Data.ByteString.Char8 as BS
--import qualified Data.Set as S
--import qualified Data.IntSet as IS
--import qualified Data.Map.Strict as M
--import qualified Data.IntMap.Strict as IM
--import qualified Data.Sequence as Seq
--import qualified Data.IntPSQ as IPSQ
--import qualified Data.Heap as H

main :: IO ()
main = do
  [h, w] <- map read . words <$> getLine
  cs <- lines <$> getContents
  print $ solve h w cs

solve :: Int -> Int -> [String] -> Int
solve h w cs = answer
  where
    field = AU.listArray ((1, 1), (h, w)) $ concat cs
    s = getPos 'o' field
    field2 = newField 'x' s field
    g = getPos 'o' field2
    answer = abs (fst s - fst g) + abs (snd s - snd g)

newField :: Char -> (Int, Int) -> AU.UArray (Int, Int) Char -> AU.UArray (Int, Int) Char
newField c (y, x) field = field AU.// [((y, x), c)]

getPos :: Char -> AU.UArray (Int, Int) Char -> (Int, Int)
getPos c field = fst . head . filter ((== c) . snd) $ AU.assocs field
