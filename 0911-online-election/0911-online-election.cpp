
class TopVotedCandidate {
public:
    vector<int> times;
    vector<int> leaders;

    TopVotedCandidate(vector<int>& persons, vector<int>& t) {
        times = t;

        int n = persons.size();

        vector<int> count(n, 0);
        int leader = -1;

        for (int i = 0; i < n; i++) {
            int p = persons[i];

            count[p]++;

            if (leader == -1 || count[p] >= count[leader]) {
                leader = p;
            }

            leaders.push_back(leader);
        }
    }

    int q(int t) {
        int idx = upper_bound(times.begin(), times.end(), t)
                  - times.begin() - 1;

        return leaders[idx];
    }
};
