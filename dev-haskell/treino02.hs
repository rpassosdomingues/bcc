hipotenusa :: Float -> Float -> Float
hipotenusa a b = sqrt (a*a + b*b)

-- Distância entre dois pontos A(x1,y1) e B(x2,y2)

distancia_AB :: Float -> Float -> Float -> Float -> Float
distancia_AB x1 y1 x2 y2 | x1 == x2 = abs (y2-y1)  -- Condição 01
			 | y1 == y2 = abs (x2-x1)  -- Condição 02
			 |otherwise = sqrt ( (x2-x1)^2 + (y2-y1)^2 )  -- Condição 03
