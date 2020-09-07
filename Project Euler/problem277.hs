-- Iterate forwards through the string, maintaining a representation
-- of a polynomial in base 3 of the original number.
-- Each next character in the sequence uniquely determines the next
-- most significant base 3 numbers.
-- Once a smallest solution is found, prefix by '10...0' in base 3
-- to find the smallest above the limit.
-- Runs <1ms

genSeq :: Integer -> String
genSeq 1 = ""
genSeq n = p : genSeq k
  where i = (fromInteger n) `mod` 3
        p = "DUd" !! i
        k = [n`div`3, (4*n+2)`div`3, (2*n-1)`div`3] !! i

type Repr = (Integer, Integer)

stepRepr :: Repr -> Integer -> Integer -> Repr
stepRepr (a,b) k0 x
  | x == 0    = (a, (b + a*k0) `div` 3)
  | x == 1    = (4*a, (4*b + 4*a*k0 + 2) `div` 3)
  | x == 2    = (2*a, (2*b + 2*a*k0 - 1) `div` 3)
  | otherwise = (a,b)

findK :: Repr -> Integer -> Integer
findK (a,b) d = head $ filter (\i -> (a*i+b-d) `mod` 3 == 0) [0,1,2]

getPows :: [Integer] -> [Integer]
getPows = snd . foldl step ((1,0), [])
  where step (repr, acc) s = (stepRepr repr k0 s, k0 : acc)
          where k0 = findK repr s

seqToNum :: String -> Integer
seqToNum = foldl (\acc n -> acc*3+n) 0 . getPows . map getIdx
  where getIdx 'D' = 0
        getIdx 'U' = 1
        getIdx 'd' = 2

findNext :: Integer -> Integer -> Integer -> Integer
findNext l n b = x*k+n
  where k = 3^l
        x = 1+(b-n)`div`k

solve :: String -> Integer -> Integer
solve s b = findNext (toInteger $ length s) (seqToNum s) b

main = print $ solve "UDDDUdddDDUDDddDdDddDDUDDdUUDd" (10^15)
