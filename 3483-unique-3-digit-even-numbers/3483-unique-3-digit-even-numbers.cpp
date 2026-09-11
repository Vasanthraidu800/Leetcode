class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int ans = 0;

        for(int a = 1; a <= 9; a++) {
            for(int b = 0; b <= 9; b++) {
                for(int c = 0; c <= 9; c++) {
                    if(c % 2 != 0) continue;

                    int x = a * 100 + b * 10 + c;

                    vector<int> used = {a, b, c};
                    vector<int> temp = digits;

                    bool ok = true;

                    for(int d : used) {
                        auto it = find(temp.begin(), temp.end(), d);

                        if(it == temp.end()) {
                            ok = false;
                            break;
                        }

                        temp.erase(it);
                    }

                    if(ok) ans++;
                }
            }
        }

        return ans;
    }
};