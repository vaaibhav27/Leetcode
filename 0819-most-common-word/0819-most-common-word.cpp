class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> ban;
        for(int i = 0; i < banned.size(); i++) {
            ban.insert(banned[i]);
        }

        unordered_map<string, int> freq;
        string word = "";

        for(int i = 0; i < paragraph.size(); i++) {
            char c = tolower(paragraph[i]);

            if(isalpha(c)) {
                word += c;
            }
            else {
                if(word != "" && ban.find(word) == ban.end()) {
                    freq[word]++;
                }
                word = "";
            }
        }

        if(word != "" && ban.find(word) == ban.end()) {
            freq[word]++;
        }

        string ans = "";
        int maxi = 0;

        for(auto it : freq) {
            if(it.second > maxi) {
                maxi = it.second;
                ans = it.first;
            }
        }

        return ans;
    }
};