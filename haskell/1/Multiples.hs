multiples n = sum [x | x <- [1..n], rem x 3 == 0 || rem x 5 == 0]

main = print $ multiples 999
