class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        PriorityQueue<int[]> minHeap = new PriorityQueue<>((a, b) -> Integer.compare(a[0], b[0]));
        Map<Integer, Integer> hmap = new HashMap<>();

        for (int n : nums){
            // if (!hmap.containsKey(n)){
            //     hmap.put(n, 0);
            // }
            hmap.compute(n, (key, val) -> (val == null) ? 1 : val + 1);
        }

        // System.out.println(hmap);

        hmap.forEach((key, val) -> {
            minHeap.offer(new int[]{val, key});
            if (minHeap.size() > k){
                minHeap.poll();
            }
        });

        int[] result = new int[k];
        int i = 0;
        while (!minHeap.isEmpty()){
            int[] pair = minHeap.poll();
            int key = pair[1];
            result[i++] = key;
        }
        return result;
    }
}
