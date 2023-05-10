-- Aplicando Recursividade à soma dos n primeiros termos e ao operador fatorial.

soma :: Int -> Int
soma 1 = 1
soma n = soma (n-1) + n

fatorial :: Integer -> Integer
fatorial 0 = 1
fatorial n = n * fatorial (n-1)
