class Solution {
public:
    int cnt(int x) {
        int c = 0;
        while (x > 0) {
            c += x % 2;
            x /= 2;
        }
        return c;
    }

    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;

        for (int h = 0; h < 12; h++) {
            for (int m = 0; m < 60; m++) {
                
                if (cnt(h) + cnt(m) == turnedOn) {
                    string t = to_string(h) + ":";
                    
                    if (m < 10) t += "0";
                    t += to_string(m);

                    ans.push_back(t);
                }
            }
        }

        return ans;
    }
};
