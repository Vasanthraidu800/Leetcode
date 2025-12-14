class Solution {
public:
    bool isValid(string s) {
        if (s.size() == 0) return false;
        for (char c : s) {
            if (!(isalnum((unsigned char)c) || c == '_'))
                return false;
        }
        return true;
    }

    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& bl,
                                   vector<bool>& isActive) {
        unordered_map<string, int> order;
        order["electronics"] = 0;
        order["grocery"] = 1;
        order["pharmacy"] = 2;
        order["restaurant"] = 3;

        vector<pair<string, string>> v;

        for (int i = 0; i < code.size(); i++) {
            if (isActive[i] &&
                isValid(code[i]) &&
                order.find(bl[i]) != order.end()) {
                v.push_back({bl[i], code[i]});
            }
        }

        sort(v.begin(), v.end(),
             [&](pair<string,string> a, pair<string,string> b) {
                 if (order[a.first] != order[b.first])
                     return order[a.first] < order[b.first];
                 return a.second < b.second;
             });

        vector<string> ans;
        for (auto p : v)
            ans.push_back(p.second);

        return ans;
    }
};
