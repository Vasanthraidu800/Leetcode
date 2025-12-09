class Solution {
public:
    int countOdds(int low, int high) {
        int range = high - low + 1;

        if (range % 2 == 0) {
            return range / 2;
        } 
        else { // range is odd
            if (low % 2 != 0) {          // odd ... odd (starts with odd)
                return range / 2 + 1;
            } else {                    // even ... even (starts with even)  e.g. 8..10
                return range / 2;
            }
        }
    }
};
