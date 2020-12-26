import Data.Int
import Data.Char (digitToInt)

-- Slow but does the job (~6s)

search :: [Int64] -> Int64 -> Int64 -> Int64 -> Bool
search [] acc v t = acc + v == t
search (x:xs) acc v t
  | acc+v+x <= t = search xs (acc+v) x t || search xs acc (v*10+x) t
  | otherwise    = False

isSplit :: Int64 -> Bool
isSplit rn = (rn `mod` 9 <= 1) && search xs 0 0 rn
  where xs = map (fromIntegral . digitToInt) $ show (rn * rn)

solve :: Int64 -> Int64
solve rt = sum $ map (^2) $ filter isSplit [2..rt]

main :: IO ()
main = print $ solve (10^6)
