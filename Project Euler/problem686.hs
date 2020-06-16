-- A bit of a hack but it appears Double precision is enough to capture the
-- significant digits for this problem.
-- Solves in about 1s

solve :: Double -> Double -> Int -> Int
solve s e n = fst $ (!! (n-1)) $ filter (startsL . snd) $ iterate dbl (0,1.0)
  where startsL v = s <= v && v < e
        dbl (i,v) = (i+1, if v > 5 then v/5 else v+v)

main :: IO ()
main = print $ solve 1.23 1.24 678910