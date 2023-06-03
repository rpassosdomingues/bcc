-- Este é um comentário.
-- Este é um código implementado em linguagem Haskell.

{-
Este é um comentário em bloco.
-}

answer :: Int -- answer é uma função constante.
answer = 42   -- Esta função recebe um valor inteiro 42
              -- e retorna este valor toda vez que é chamada.

square :: Int -> Int -- A função square recebe um parâmetro inteiro
		     -- e retorna um valor inteiro.
square x = x * x     -- x é o identificador do parâmetro
--square 2 = -1
--square 3 = 0	     -- parâmetro != valor
--square _ = 6	     -- parâmetro descartável.

allEqual :: Int -> Int -> Int -> Bool -- Recebe 3 parâmetros inteiros
				      -- e retorna um booleano.
allEqual m n p = (m==p) && (n==p)

{-
Haskell faz casamento de padrão de cima para baixo.
-}

maxi :: Int -> Int -> Int
maxi m n
   |m >= n = m
   |otherwise = n

