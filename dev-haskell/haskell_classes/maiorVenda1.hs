-- define o período de recursão
periodo :: Int
periodo = 7

{-
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
-}

-- tabela de vendas
vendas :: Int -> Int
vendas d
   | d == 1 = 41
   | d == 2 = 72
   | d == 3 = 48
   | d == 4 = 0
   | d == 5 = 91
   | d == 6 = 55
   | d == 7 = 30

-- função que retorna o dia que aconteceu a maior venda no período.

maior :: Int -> Int -> Int
maior a b
   | a > b = a
   | otherwise = b

maiorVenda :: Int -> Int
maiorVenda 0 = vendas 0
maiorVenda d = maior (vendas d) (maiorVenda (d-1))

