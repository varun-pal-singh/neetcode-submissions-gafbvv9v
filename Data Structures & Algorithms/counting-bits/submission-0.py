class Solution:

    def count1s(self, n: int) -> int:
        count = 0
        while n:
            n = n & (n - 1)
            count += 1
        return count

    def countBits(self, n: int) -> List[int]:
        
        res = []
        for i in range(n + 1):
            res.append(self.count1s(i))
        
        return res