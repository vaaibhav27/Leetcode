class Solution {
public:
    bool dfs(int node, vector<int> &visited, vector<vector<int>> &graph) {
        //visited[node] = 0;
        for(int i = 0; i < graph[node].size(); i++) {
            int nextnode = graph[node][i];
            if(visited[nextnode] == -1) {
                visited[nextnode] = 1 - visited[node];
                if(!dfs(nextnode, visited, graph)) return false;
            }
            else if(visited[nextnode] == visited[node]) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n, -1);
        for(int i = 0; i < n; i++) {
            if(visited[i] == -1) {
                visited[i] = 0;
                if(!dfs(i, visited, graph)) return false;
            }
        }
        return true;
    }
};