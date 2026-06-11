class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> charFreq(26, 0);

        for (char c : chars) {
            charFreq[c - 'a']++;
        }

        int ans = 0;

        for (string &word : words) {
            vector<int> freq(26, 0);

            for (char c : word) {
                freq[c - 'a']++;
            }

            bool good = true;

            for (int i = 0; i < 26; i++) {
                if (freq[i] > charFreq[i]) {
                    good = false;
                    break;
                }
            }

            if (good) {
                ans += word.size();
            }
        }

        return ans;
    }
};