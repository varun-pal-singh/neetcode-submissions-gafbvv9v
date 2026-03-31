class Solution:
    def sumOfSqrs(self, n: int) -> int:
        total = 0
        while n:
            digit = n % 10
            sq = digit ** 2
            total += sq
            n //= 10
        return total
    
    def isHappy(self, n: int) -> bool:
        slow, fast = n, self.sumOfSqrs(n)

        while slow != fast:
            fast = self.sumOfSqrs(fast)
            fast = self.sumOfSqrs(fast)
            slow = self.sumOfSqrs(slow)
            
        
        return True if fast == 1 else False