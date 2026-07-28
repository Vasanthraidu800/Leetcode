class Solution {
public:
    int largestInteger(int num) {
        string s = to_string(num);

        vector<char> even, odd;

        for (char c : s) {
            if ((c - '0') % 2 == 0)
                even.push_back(c);
            else
                odd.push_back(c);
        }

        sort(even.rbegin(), even.rend());
        sort(odd.rbegin(), odd.rend());

        string res = "";
        int e = 0, o = 0;

        for (int i = 0; i < s.size(); i++) {
            if ((s[i] - '0') % 2 == 0)
                res.push_back(even[e++]);
            else
                res.push_back(odd[o++]);
        }

        return stoi(res);
    }
};