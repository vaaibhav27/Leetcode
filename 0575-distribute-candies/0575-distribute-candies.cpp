class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        set<int> st;

        for(int i = 0; i < candyType.size(); i++) {
            st.insert(candyType[i]);
        }

        return min((int)st.size(), (int)candyType.size() / 2);
    }
};