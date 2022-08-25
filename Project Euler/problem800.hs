import Data.Array.Unboxed
import Data.Array.ST
import Control.Monad (forM_, when)

sieveTo :: Int -> UArray Int Bool
sieveTo bound = runSTUArray $ do
  let m = ceiling $ sqrt (fromIntegral bound)
  isPrime <- newArray (2, bound) True
  forM_ (2:[3,5..m]) $ \i -> do
    p <- readArray isPrime i
    when p $
      forM_ [i*i,i*i+i..bound] (\j -> writeArray isPrime j False)
  return isPrime

primesTo :: Int -> [Int]
primesTo bound = filter (sieve !) [2..bound]
  where sieve = sieveTo bound

within :: Int -> Int -> Int -> Bool
within n p q = p' * log q' + q' * log p' <= n' * log n'
  where p' = fromIntegral p
        q' = fromIntegral q
        n' = fromIntegral n

solve :: Int -> Int
solve n = go primes (reverse primes) (length primes) 0
  where bound = n * ceiling (logBase 2 (fromIntegral n))
        primes = primesTo bound
        -- two pointer trick
        go [] _ _ acc = acc
        go _ [] _ acc = acc
        go (p:ps) (q:qs) l acc
          | p >= q        = acc
          | within n p q  = go ps (q:qs) (l-1) (acc + l - 1)
          | otherwise     = go (p:ps) qs (l-1) acc

main :: IO ()
main = print $ solve 800800