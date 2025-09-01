#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        string res;
        for (char d : num) {
            while (!res.empty() && res.back() > d && k > 0) {
                res.pop_back();
                k--;
            }
            res.push_back(d);
        }
        while (k > 0 && !res.empty()) {
            res.pop_back();
            k--;
        }
        int idx = 0;
        while (idx < (int)res.size() && res[idx] == '0') idx++;
        res = res.substr(idx);
        return res.empty() ? "0" : res;
    }
};
