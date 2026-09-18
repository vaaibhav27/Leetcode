class Solution {
public:
    int maxFreqSum(string s) {

        unordered_map<char, int> mp;

        for (char ch : s) {
            mp[ch]++;
        }

        int maxVowel = 0;
        int maxConsonant = 0;

        for (auto it : mp) {

            char ch = it.first;
            int freq = it.second;

            if (ch == 'a' || ch == 'e' || ch == 'i' ||
                ch == 'o' || ch == 'u') {

                maxVowel = max(maxVowel, freq);
            }
            else {
                maxConsonant = max(maxConsonant, freq);
            }
        }

        return maxVowel + maxConsonant;
    }
};