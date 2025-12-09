class Solution {
public:
    int countOdds(int low, int high) {
        int cnt=0;
        while(high>=low)
        {
            if(high%2!=0) cnt++;
            high--;
        }
        return cnt;
    }
};