-- Exercício proposto: Fornecidos três valores a, b e c, escreva uma função que retorne 0 quando os três valores forem iguais.

allEquall :: Int -> Int -> Int -> Int
allEquall a b c
   | (a == b) && (a == c) = 0
   | otherwise = 1
   
allEquall_2 :: Int -> Int -> Int -> Bool
allEquall_2 a b c
   | (a == b) && (a == c) = True
   | otherwise = False
