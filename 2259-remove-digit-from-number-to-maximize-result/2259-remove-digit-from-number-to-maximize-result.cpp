class Solution {
public:
    string removeDigit(string number, char digit) {
        int idx = -1;

        for (int i = 0; i < number.size(); i++) {
            if (number[i] == digit) {
                idx = i;  

                if (i + 1 < number.size() && number[i + 1] > digit) {
                    idx = i;
                    break;
                }
            }
        }

        number.erase(idx, 1);
        return number;
    }
};