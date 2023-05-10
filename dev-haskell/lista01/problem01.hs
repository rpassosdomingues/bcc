funcao1 :: Float -> Float
funcao1 x
   | x >= 0 = (x + 4)/(x + 2)
   | x < 0 = 2/x

funcao2 :: Float -> Float -> Float
funcao2 x y
   | x >= y = x + y
   | x < y = x - y

funcao3 :: Float -> Float -> Float -> Float
funcao3 x y z
   | x + y > z = x + y + z
   | x + y < z = x - y - z
   | x + y == z = 0

