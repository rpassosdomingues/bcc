-- aplicando tipos compostos com tuplas

type dia = Int
type vendas = Int

-- vendas por período
periodo :: dia
periodo = 7

-- tabela de dia e vendas do dia
vendas :: dia -> vendas
vendas 0 = 0
vendas 1 = 91
vendas 2 = 72
vendas 3 = 91
vendas 4 = 0
vendas 5 = 91
vendas 6 = 55
vendas 7 = 30

-- retorna o dia comparando a maior de dois dias
maior :: vendas -> vendas -> dia
maior a b
   | a > b = a
   | otherwise = b

-- retorna maior venda
maiorVenda :: [(dia, vendas periodo)] -> dia -> vendas
maiorVenda [] m = m
maiorVenda (a:x) m
   | snd a >= m = maior (x) (snd a)
   | otherwise = maior (x) (a)

listaDiasMaiorVenda :: dia -> vendas -> [dia]
listaDiasMaiorVenda (-1) _ = []
listaDiasMaiorVenda (dia) (maiorVenda)
   | (vendas dia) == (maiorVenda) = dia : listaDiasMaiorVenda (dia-1) (maiorVenda)
   | otherwise = listaDiasMaiorVenda (dia-1) (maiorVenda)

-- periodo pode ser igual a dia, retorna os dias recursivamente

listaTuplaVendas :: dia -> [(dia, vendas)]
listaTuplaVendas 0 = []
listaTuplaVendas (dia) = (dia, vendas dia) : listaTuplaVendas (dia-1)

-- retorna os dias que venderam mais
listaDias :: [(dia, vendas)] -> [dia]
listaDias [(_, -1)] = [[]]
listaDias [(dia, vendas dia)]
   | (vendas dia) == (maiorVenda) = dia : listaDiasMaiorVenda (dia-1) (maiorVenda)
   | otherwise = listaDiasMaiorVenda (dia-1) (maiorVenda)
