class Solution {
public:
    int LOG;
    vector<vector<int>> adj, up;
    vector<int> tin, tout, depth, initialPrefix;
    int timer = 0;

    struct Fenwick {
        int n;
        vector<int> bit;

        Fenwick(int n) {
            this->n = n;
            bit.assign(n + 2, 0);
        }

        void update(int i, int val) {
            while (i <= n) {
                bit[i] ^= val;
                i += i & -i;
            }
        }

        void rangeUpdate(int l, int r, int val) {
            update(l, val);
            update(r + 1, val);
        }

        int query(int i) {
            int ans = 0;

            while (i > 0) {
                ans ^= bit[i];
                i -= i & -i;
            }

            return ans;
        }
    };

    int getMask(char c) {
        return 1 << (c - 'a');
    }

    void dfs(int u, int parent, int mask) {
        tin[u] = ++timer;
        initialPrefix[u] = mask ^ getMask(currentString[u]);

        up[u][0] = parent;

        for (int j = 1; j < LOG; j++) {
            up[u][j] = up[up[u][j - 1]][j - 1];
        }

        for (int v : adj[u]) {
            if (v == parent) continue;

            depth[v] = depth[u] + 1;
            dfs(v, u, initialPrefix[u]);
        }

        tout[u] = timer;
    }

    string currentString;

    int lca(int u, int v) {
        if (depth[u] < depth[v]) {
            swap(u, v);
        }

        int diff = depth[u] - depth[v];

        for (int j = 0; j < LOG; j++) {
            if (diff & (1 << j)) {
                u = up[u][j];
            }
        }

        if (u == v) return u;

        for (int j = LOG - 1; j >= 0; j--) {
            if (up[u][j] != up[v][j]) {
                u = up[u][j];
                v = up[v][j];
            }
        }

        return up[u][0];
    }

    vector<bool> palindromePath(
        int n,
        vector<vector<int>>& edges,
        string s,
        vector<string>& queries
    ) {
        currentString = s;

        adj.assign(n, {});
        tin.assign(n, 0);
        tout.assign(n, 0);
        depth.assign(n, 0);
        initialPrefix.assign(n, 0);

        LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        up.assign(n, vector<int>(LOG, 0));

        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(0, 0, 0);

        Fenwick fw(n);

        vector<bool> answer;

        for (string& q : queries) {
            string type;
            int u;

            stringstream ss(q);
            ss >> type >> u;

            if (type == "update") {
                char c;
                ss >> c;

                int delta =
                    getMask(currentString[u]) ^ getMask(c);

                if (delta != 0) {
                    fw.rangeUpdate(tin[u], tout[u], delta);
                }

                currentString[u] = c;
            } 
            else {
                int v;
                ss >> v;

                int w = lca(u, v);

                int prefixU =
                    initialPrefix[u] ^ fw.query(tin[u]);

                int prefixV =
                    initialPrefix[v] ^ fw.query(tin[v]);

                int pathMask =
                    prefixU ^ prefixV ^ getMask(currentString[w]);

                answer.push_back(
                    (pathMask & (pathMask - 1)) == 0
                );
            }
        }

        return answer;
    }
};