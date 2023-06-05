arvore :: Float -> Float
arvore 0 = 0
arvore x = sqrt (x + arvore (x-1))
