fat :: Int -> Int
fat x = x * fat(x-1)

{-

Erro - stack overflow

O problema na função fat é que temos uma solução recursiva, porém
não foi atribuída uma base para a indução.

Sem uma base, a recursão é processada em loop infinito e
esse empilhamento de funções enche a memória.

-}

fatorial :: Int -> Int
fatorial 0 = 1
fatorial x = x * fatorial(x-1)

