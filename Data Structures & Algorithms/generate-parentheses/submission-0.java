class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> result = new ArrayList<>();
        generate(result, "", n, n);
        return result;
    }

    public void generate(List<String> result, String curStr, int open, int close){
        if (open == 0 && close == 0){
            result.add(curStr);
            return;
        }
        if (open > 0){
            generate(result, curStr + "(", open - 1, close);
        }
        if (close > 0 && close > open){
            generate(result, curStr + ")", open, close - 1);
        }
    }
}
