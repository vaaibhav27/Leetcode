class Solution {
public:

    struct Node {
        long long cnt[5] = {};
        int prod = 1;
    };

    int n, k;
    vector<Node> tree;

    Node mergeNode(const Node& left, const Node& right) {

        Node ans;

        ans.prod = (left.prod * right.prod) % k;

        for(int r = 0; r < k; r++) {
            ans.cnt[r] = left.cnt[r];
        }

        for(int r = 0; r < k; r++) {

            int rem = (left.prod * r) % k;

            ans.cnt[rem] += right.cnt[r];
        }

        return ans;
    }

    void build(int node, int l, int r,
               vector<int>& nums) {

        if(l == r) {

            int rem = nums[l] % k;

            tree[node].prod = rem;
            tree[node].cnt[rem] = 1;

            return;
        }

        int mid = (l + r) / 2;

        build(node * 2, l, mid, nums);
        build(node * 2 + 1, mid + 1, r, nums);

        tree[node] =
            mergeNode(tree[node * 2],
                      tree[node * 2 + 1]);
    }

    void update(int node, int l, int r,
                int index, int value) {

        if(l == r) {

            int rem = value % k;

            tree[node].prod = rem;

            for(int i = 0; i < k; i++) {
                tree[node].cnt[i] = 0;
            }

            tree[node].cnt[rem] = 1;

            return;
        }

        int mid = (l + r) / 2;

        if(index <= mid) {
            update(node * 2, l, mid, index, value);
        }
        else {
            update(node * 2 + 1, mid + 1, r, index, value);
        }

        tree[node] =
            mergeNode(tree[node * 2],
                      tree[node * 2 + 1]);
    }

    Node query(int node, int l, int r,
               int ql, int qr) {

        if(ql <= l && r <= qr) {
            return tree[node];
        }

        int mid = (l + r) / 2;

        if(qr <= mid) {
            return query(node * 2,
                         l,
                         mid,
                         ql,
                         qr);
        }

        if(ql > mid) {
            return query(node * 2 + 1,
                         mid + 1,
                         r,
                         ql,
                         qr);
        }

        Node left =
            query(node * 2,
                  l,
                  mid,
                  ql,
                  qr);

        Node right =
            query(node * 2 + 1,
                  mid + 1,
                  r,
                  ql,
                  qr);

        return mergeNode(left, right);
    }

    vector<int> resultArray(
        vector<int>& nums,
        int k,
        vector<vector<int>>& queries) {

        this->n = nums.size();
        this->k = k;

        tree.resize(4 * n + 5);

        build(1, 0, n - 1, nums);

        vector<int> result;
        result.reserve(queries.size());

        for(auto &q : queries) {

            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            nums[index] = value;

            update(1, 0, n - 1,
                   index, value);

            Node ans =
                query(1, 0, n - 1,
                      start, n - 1);

            result.push_back(ans.cnt[x]);
        }

        return result;
    }
};