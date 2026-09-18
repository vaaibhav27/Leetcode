class Solution {
public:

    bool isAnagram(string s1, string s2) {

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

    bool checkInclusion(string s1, string s2) {

        int n = s1.size();
        int m = s2.size();

        if (n > m)
            return false;

        for (int i = 0; i <= m - n; i++) {

            string temp = s2.substr(i, n);

            if (isAnagram(s1, temp)) {
                return true;
            }
        }

        return false;
    }
};