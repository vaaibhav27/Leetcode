class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        for(int i = 0; i<prerequisites.size(); i++) {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[v].push_back(u);
            indegree[u]++;
        }
        queue<int> q;
        for(int i = 0; i<numCourses; i++) {
            if(indegree[i] == 0) q.push(i);
        }
        vector<int> ans;
        while(!q.empty()) {
            int t = q.front();
            q.pop();
            ans.push_back(t);
            for(int i = 0; i<adj[t].size(); i++) {
                int node = adj[t][i];
                indegree[node]--;
                if(indegree[node] == 0) q.push(node);
            }
        }
        if(ans.size() == numCourses) return ans;
        else return {};
    }
};