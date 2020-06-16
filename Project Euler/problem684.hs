-- Essentially a direct result after noticing there is a pattern to the s(n)
-- and hence a geometric sum for S(n). The trickery below simply keeps the
-- numbers small but isn't actually necessary.

expMod :: Integral a => a -> a -> a -> a
expMod n k m
  | k <= 0    = 1
  | even k    = h
  | otherwise = (n * h) `mod` m
    where h = expMod ((n*n) `mod` m) (k `div` 2) m

fibber :: (a -> a -> a) -> a -> a -> [a]
fibber s a0 a1 = xs
  where xs = a0 : a1 : zipWith s xs (tail xs)

xs m = fibber s (0,0) (0,1)
  where s (n1,m1) (n2,m2) = ((n1 + n2 + q) `mod` (m-1), r)
          where (q,r) = divMod (m1 + m2) 9
ys m = fibber (\a b -> (a + b) `mod` m) 0 1

digitSums :: Integral a => a -> a -> a -> a -> a
digitSums k n r m = (expMod 10 n m * (5 + div ((r+1)*(r+2)) 2) - k - 6) `mod` m

solve :: Int -> Integer -> Integer
solve f m =
  (`mod` m) . sum . take (f-1) . drop 2 $
  zipWith (\(n,r) k -> digitSums k n r m) (xs m) (ys m)

main :: IO ()
main = print $ solve 90 1000000007