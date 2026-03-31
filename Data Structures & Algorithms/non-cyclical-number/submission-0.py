class Solution:
    def isHappy(self, n: int) -> bool:
        seen = set()
        while True:
            total = 0
            while n:
                digit = n % 10
                sq = digit ** 2
                total += sq
                n //= 10
            
            n = total
            if n == 1:  return True
            if n in seen:   return False
            seen.add(n)
        return False