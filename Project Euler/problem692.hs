-- After some intuitive analysis a pattern reveals itself
-- H(fib_n) = fib_n only for fibonacci numbers and
-- H(fib_n + k) = H(k) for 1<=k<fib_(n-1)
-- This yield a quick recursive calculation for the sum G
-- at each fib_n and the recursing to build a soln for 
-- general n.
--
-- O(log n), Takes ~20ms 

fibs :: [Integer]
fibs = 1 : 1 : zipWith (+) fibs (tail fibs)

sums :: [Integer]
sums = 1 : 1 : map f (zip3 (tail fibs) sums (tail sums))
  where f (a,b,c) = a+b+c

solve :: Integer -> Integer
solve 0 = 0
solve n = s + solve (n - f)
  where (s, f) = last $ takeWhile ((<=n) . snd) (zip sums fibs)

main :: IO ()
main = print $ solve 23416728348467685
