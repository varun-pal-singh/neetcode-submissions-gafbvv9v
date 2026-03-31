class Solution {
    public void dfs(List<List<Integer>> graph, boolean[] visited, int u){
        if (visited[u]) return;
        visited[u] = true;
        for (int v : graph.get(u)){
            if (!visited[v]){
                dfs(graph, visited, v);
            }
        }
    }

    public int countComponents(int n, int[][] edges) {
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < n; i++){
            graph.add(new LinkedList<>());
        }
        for (int[] edge: edges){
            int u = edge[0], v = edge[1];
            graph.get(u).add(v);
            graph.get(v).add(u);
        }
        boolean[] visited = new boolean[n];
        int cnt = 0;
        for (int u = 0; u < n; u++){
            if (!visited[u]){
                dfs(graph, visited, u);
                cnt += 1;
            }
        }
        return cnt;
    }
}
