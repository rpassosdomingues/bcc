arvore :: Float -> Float
--x = 6
--i0 = sqrt x

-- i1 = sqrt ( x + i0 )
-- i2 = sqrt ( x + i1 )
-- i3 = sqrt ( x + i2 )
-- i4 = sqrt ( x + i3 )
-- in = sqrt ( x + in-1 )

arvore x = sqrt (x + sqrt (x-1))

