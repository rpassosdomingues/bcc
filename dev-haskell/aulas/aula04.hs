-- Vendas por período

-- define o período de recursão
periodo :: Int
periodo = 7

-- tabela de dia e vendas do dia
vendas :: Int -> Int
vendas 0 = 0
vendas 1 = 91
vendas 2 = 72
vendas 3 = 91
vendas 4 = 0
vendas 5 = 91
vendas 6 = 55
vendas 7 = 30

-- retorna o total de vendas
totalVendas :: Int -> Int
totalVendas 0 = vendas 0
totalVendas d = vendas d + totalVendas (d-1)

-- retorna o dia que vendeu mais
maior :: Int -> Int -> Int
maior a b
   | a > b = a
   | otherwise = b

-- retorna maior venda
maiorVenda :: Int -> Int
maiorVenda x
   | x == 0 = vendas 0
   | otherwise = maior (vendas x) (maiorVenda (x-1))

listaDiasMaiorVenda :: Int -> Int -> [Int]
listaDiasMaiorVenda (-1) _ = []
listaDiasMaiorVenda (dia) (maiorVenda)
   | (vendas dia) == (maiorVenda) = dia : listaDiasMaiorVenda (dia-1) (maiorVenda)
   | otherwise = listaDiasMaiorVenda (dia-1) (maiorVenda)

listaTuplaVendas :: Int -> [(Int, Int)]
listaTuplaVendas 0 = []
listaTuplaVendas (dia) = (dia, vendas dia) : listaTuplaVendas (dia-1)
