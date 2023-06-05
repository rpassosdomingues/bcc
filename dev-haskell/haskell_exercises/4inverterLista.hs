invertDigits :: Int -> Int
invertDigits n
  | n < 10    = n
  | otherwise = invertDigits rest * 10 + lastDigit
  where
    lastDigit = n `mod` 10
    rest = n `div` 10

invertInt :: Int -> Int
invertInt x
  | x < 10    = x
  | otherwise = invertInt (x `div` 10) * 10 + (x `mod` 10)

