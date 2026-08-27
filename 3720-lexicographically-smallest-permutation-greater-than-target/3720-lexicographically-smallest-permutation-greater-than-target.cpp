class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int cnt[26] = {};
        for (char c : s) cnt[c - 'a']++;

        int n = s.size();
        int pos = -1;

        for (int i = 0; i < n; i++) {
            int x = target[i] - 'a';

            for (int j = x + 1; j < 26; j++) {
                if (cnt[j]) {
                    pos = i;
                    break;
                }
            }

            if (!cnt[x])
                break;

            cnt[x]--;
        }

        if (pos == -1)
            return "";

        // Rebuild remaining characters for the best position
        int rem[26] = {};
        for (char c : s) rem[c - 'a']++;

        for (int i = 0; i < pos; i++)
            rem[target[i] - 'a']--;

        int x = target[pos] - 'a';
        int y = x + 1;

        while (!rem[y])
            y++;

        string ans = target.substr(0, pos);
        ans += char('a' + y);
        rem[y]--;

        for (int i = 0; i < 26; i++)
            ans.append(rem[i], char('a' + i));

        return ans;
    }
};