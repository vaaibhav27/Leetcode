class Solution {
public:

    bool isAnagram(string s1, string s2) {

        if (s1.size() != s2.size())
            return false;

        int freq[26] = {0};

        for (int i = 0; i < s1.size(); i++) {

            freq[s1[i] - 'a']++;
            freq[s2[i] - 'a']--;
        }

        for (int i = 0; i < 26; i++) {

            if (freq[i] != 0)
                return false;
        }

        return true;
    }


    vector<int> findAnagrams(string s, string p) {

        vector<int> ans;

        int n = s.size();
        int m = p.size();

        for (int i = 0; i <= n - m; i++) {

            string temp = s.substr(i, m);

            if (isAnagram(temp, p)) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};