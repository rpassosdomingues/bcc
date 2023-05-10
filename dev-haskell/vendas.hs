-- Vendas por período

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

-- função que retorna o total de vendas
totalVendas :: Int -> Int
totalVendas 0 = vendas 0
totalVendas d = vendas d + totalVendas (d-1)

-- função que retorna quantas vendas superam um valor
vendaSup :: Int -> Int -> Int -> Int
vendaSup 0 _ v = v
vendaSup d f v
   |vendas d > f = vendaSup (d-1) f (v+1)
   |vendas d <= f = vendaSup (d-1) f v

-- retorna o dia de certa venda, mas depende do parâmetro
diaVenda :: Int -> Int -> Int
diaVenda 0 _ = 0
diaVenda d v
   |vendas d == v = d
   |otherwise = diaVenda (d - 1) v

-- dia de certa venda: Qual dia vendeu tanto?
diaVendaSimples :: Int -> Int
diaVendaSimples v = diaVenda periodo v
