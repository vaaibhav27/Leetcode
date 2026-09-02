class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int n = sentences.size();
        int maxi = 0;
        for(int i = 0; i < n; i++) {
            string s = sentences[i];
            int cnt = 1;
            for(int j = 0; j < s.size(); j++) {
                if(sentences[i][j] == ' ') cnt++;
            }
            maxi = max(maxi, cnt);
        }
        return maxi;
    }
};