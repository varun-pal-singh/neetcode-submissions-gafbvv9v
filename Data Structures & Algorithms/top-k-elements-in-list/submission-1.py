class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        minHeap = []
        hmap = {}
        for n in nums:
            hmap[n] = hmap.get(n, 0) + 1;
        
        for key, val in hmap.items():
            heapq.heappush(minHeap, [val, key])
            if len(minHeap) > k:
                heapq.heappop(minHeap)
            
        result = [0] * k
        i = 0
        for _, key in minHeap:
            result[i] = key
            i += 1
            
        return result;