class Solution {
public:
    int waysToSplitArray(vector<int>& a) {
        long long s = 0; // sum
        for (int x : a) s += x;

        long long p = 0; //left
        int c = 0;
        //logic is comapring left part with right part sum
        //right is total - left sum
        for (int i = 0; i < a.size() - 1; i++) {
            p += a[i];
            if (p >= s - p) c++; //left>=right
        }

        return c;
    }
};