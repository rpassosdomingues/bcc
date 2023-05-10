-- define o período de recursão
periodo :: Int
periodo = 7

-- tabela de vendas
vendas :: Int -> Int
vendas 0 = 0
vendas 1 = 41
vendas 2 = 72
vendas 3 = 48
vendas 4 = 0
vendas 5 = 91
vendas 6 = 55
vendas 7 = 30

-- função que soma todas as vendas de dia par

par :: Int -> Bool
par x = x `mod` 2 == 0

impar :: Int -> Bool
impar x = not (par x)

somaDiasPares :: Int -> Int
somaDiasPares 0 = vendas 0
somaDiasPares d
   | par d = vendas d + somaDiasPares (d-1)
   | otherwise = somaDiasPares (d-1)

-- função que soma todas as vendas de dia ímpar

somaDiasImpares :: Int -> Int
somaDiasImpares 0 = vendas 0
somaDiasImpares d
   | not (par d) = vendas d + somaDiasImpares (d-1)
   | otherwise = somaDiasImpares (d-1)

-- Unificando: função que soma todas as vendas, de dia par e dia ímpar

somaDias :: (Int -> Bool) -> Int -> Int
somaDias f 0 = vendas 0
somaDias f d
   | f d = vendas d + somaDias f (d-1)
   | otherwise = somaDias f (d-1)

