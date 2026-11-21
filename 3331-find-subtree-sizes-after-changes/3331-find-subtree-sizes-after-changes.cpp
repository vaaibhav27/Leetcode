
class Solution {
public:
    vector<vector<int>> adj;
    vector<int> last;
    vector<int> ans;

    void dfs1(int node, string &s, vector<int> &parent) {

        int c = s[node] - 'a';

        int old = last[c];

        if(old != -1) {
            parent[node] = old;
        }

        last[c] = node;

        for(int child : adj[node]) {
            dfs1(child, s, parent);
        }

        last[c] = old;
    }

    int dfs2(int node) {

        int size = 1;

        for(int child : adj[node]) {
            size += dfs2(child);
        }

        ans[node] = size;

        return size;
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {

        int n = parent.size();

        adj.resize(n);
        last.assign(26, -1);
        ans.resize(n);

        for(int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        vector<int> newParent = parent;

        dfs1(0, s, newParent);

        vector<vector<int>> newAdj(n);

        for(int i = 1; i < n; i++) {
            newAdj[newParent[i]].push_back(i);
        }

        adj = newAdj;

        dfs2(0);

        return ans;
    }
};
