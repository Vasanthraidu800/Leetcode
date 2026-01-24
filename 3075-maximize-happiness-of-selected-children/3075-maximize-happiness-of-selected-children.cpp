class Solution {
public:
    long long maximumHappinessSum(vector<int>& h, int k) {
        long long score=0;
        sort(h.rbegin(),h.rend());
        for(int i=0;i<k;i++)
        {
            score+= max(0,h[i]-i);
        }
        return score;

    }
};