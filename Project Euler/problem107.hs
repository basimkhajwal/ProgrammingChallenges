import Data.Array
import Data.List
import Data.Ord
import Data.List.Split

type Vert = Int
type Weight = Int
type Edge = (Vert, Weight)
type Network = Array Int [Edge]

readNetwork :: String -> Network
readNetwork = arr . map (map (second read) . filter ((/="-") . snd) . zip [1..] . splitOn ",") . lines
  where arr xs = listArray (1, length xs) xs
        second f (a,b) = (a, f b)

totalWeight :: Network -> Weight
totalWeight = (`div` 2) . sum . map (sum . map snd) . elems

relax :: Array Int Int -> [Edge] -> [(Int, Int)]
relax dist = filter (\e -> snd e < dist ! (fst e))

prim :: Network -> Array Int Int -> [Int] -> Int
prim _       _    []        = 0
prim network dist remaining = (dist ! v) + prim network dist' (filter (/= v) remaining) 
  where v = minimumBy (comparing (dist !)) remaining
        dist' = dist // relax dist (network ! v)

mstCost :: Network -> Int
mstCost network = prim network (listArray (1,n) (0:(replicate (n-1) maxBound))) [1..n]
  where n = length network

solve :: Network -> Int
solve network = totalWeight network - mstCost network

main :: IO ()
main = readFile "p107_network.txt" >>= (print . solve . readNetwork)
