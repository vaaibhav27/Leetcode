class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];
            adj[u].push_back({v, w});
        }
        vector<vector<long long>> dist(n, vector<long long>(k + 1, LLONG_MAX));
        priority_queue<
            tuple<long long, int, int>,
            vector<tuple<long long, int, int>>,
            greater<tuple<long long, int, int>>
        > pq;
        dist[0][1] = 0;
        pq.push({0, 0, 1});
        while (!pq.empty()) {
            auto [cost, node, count] = pq.top();
            pq.pop();
            if (cost != dist[node][count]) {
                continue;
            }
            if (node == n - 1) {
                return cost;
            }
            for (auto &edge : adj[node]) {
                int next = edge.first;
                int weight = edge.second;
                int newCount;
                if (labels[node] == labels[next]) {
                    newCount = count + 1;
                }
                else {
                    newCount = 1;
                }
                if (newCount > k) {
                    continue;
                }
                long long newCost = cost + weight;
                if (newCost < dist[next][newCount]) {
                    dist[next][newCount] = newCost;
                    pq.push({newCost, next, newCount});
                }
            }
        }
        return -1;
    }
};