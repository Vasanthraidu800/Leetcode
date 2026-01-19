class Solution {
public:
    int minTimeToType(string word) {
        int time = 0;
        char curr = 'a';

        for (char c : word) {
            int diff = abs(c - curr);
            time += min(diff, 26 - diff); 
            time += 1;                    // for typing
            curr = c;                     // for  updating  pointer
        }

        return time;
    }
};
