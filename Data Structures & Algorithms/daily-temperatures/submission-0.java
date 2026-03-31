class Solution {
    public int[] dailyTemperatures(int[] temps) {
        Stack<Integer> stk = new Stack<>();           // idx
        int n = temps.length;
        int[] answer = new int[n];
        for (int i = n - 1; i >= 0; i--){
            while (!stk.isEmpty() && temps[i] >= temps[stk.peek()]){
                stk.pop();
            }
            if (!stk.isEmpty()){
                answer[i] = stk.peek() - i;
            }
            stk.push(i);
        }
        return answer;
    }
}
