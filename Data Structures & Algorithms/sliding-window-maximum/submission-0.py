class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        deq = deque()
        res = []
        l = 0
        for r in range(len(nums)):
            # maintaining window size
            if r - l + 1 > k:
                if nums[l] == deq[0]:
                    deq.popleft()
                l += 1
            
            # maintaining monotonic decreasing order in deque
            # (equal allowed) 
            while deq and deq[-1] < nums[r]:
                deq.pop()
            
            deq.append(nums[r])

            if r - l + 1 == k:
                res.append(deq[0])
            
        return res