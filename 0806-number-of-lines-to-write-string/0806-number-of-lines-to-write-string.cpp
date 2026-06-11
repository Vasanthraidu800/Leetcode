class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int lines = 1;
        int currWidth = 0;

        for (char ch : s) {
            int w = widths[ch - 'a'];

            if (currWidth + w <= 100) {
                currWidth += w;
            } else {
                lines++;
                currWidth = w;
            }
        }

        return {lines, currWidth};
    }
};