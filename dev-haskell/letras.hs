-- função que converte letras minúsculas em maiúsculas

import Data.Char (isLower, ord, chr)

toUpper :: Char -> Char
toUpper c
  | isLower c = chr (ord c - ord 'a' + ord 'A')
  | otherwise = c
  where
    isLower :: Char -> Bool
    isLower c = c >= 'a' && c <= 'z'

