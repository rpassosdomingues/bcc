-- Vendas por período

type Dia = Int
type Vendas = Int

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

vendasB :: [(Dia, Vendas)]
vendasB = [(7,30),(6,55),(5,91),(4,0),(3,48),(2,72),(1,41),(0,0)]

--função que insere um elemento na lista

--insereElemento :: Int -> [Int] -> [Int]
--insereElemento y [] = [y]

--função que insere um elemento na lista na ordem certa
--ordenaLista :: [Int] -> [Int]
--ordenaLista [] = []

--função que retorna [(Dia, Venda)]
listaDuplas :: Int -> [(Dia, Vendas)]
listaDuplas (-1) = []
listaDuplas x = (x, vendas x) : listaDuplas (x-1)

totalVendas :: Int -> Int
totalVendas 0 = 0
totalVendas x = vendas x + totalVendas (x-1)

--função que soma total de vendasB de uma lista de duplas.
totalVendasB :: [(Dia, Vendas)] -> Int
totalVendasB [] = 0 
totalVendasB (a:x) = snd a + totalVendasB x

--função que lista vendas
listaVendas :: Int -> [Vendas]
listaVendas (-1) = []
listaVendas x = vendas x : listaVendas (x-1)

--função que lista dias
listaDias :: Int -> [Dia]
listaDias (-1) = []
listaDias x = x : listaDias (x-1)

mesclaListas :: [Dia] -> [Vendas] -> [(Dia,Vendas)]
mesclaListas [] [] = []
mesclaListas (a:b) (c:d) = (a,c) : mesclaListas b d
