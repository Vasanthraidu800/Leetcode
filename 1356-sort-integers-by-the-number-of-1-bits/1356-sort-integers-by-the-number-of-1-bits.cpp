class Solution {
public:

    int countOnes(int n) {
        int count = 0;
        while(n > 0) {
            if(n % 2 == 1)
                count++;
            n = n / 2;
        }
        return count;
    }

    vector<int> sortByBits(vector<int>& arr) {
        
        sort(arr.begin(), arr.end(), [this](int a, int b) {
            int c1 = countOnes(a);
            int c2 = countOnes(b);
            if(c1 == c2)
                return a < b;   
            return c1 < c2;    
        });
        
        return arr;
    }
};