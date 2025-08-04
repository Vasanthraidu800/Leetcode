class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int>freq(n+1,0);
        for(int num :nums)
        {
            freq[num]++;
        }
        vector<int>res;
        for(int i=1;i<=n;i++)
        {
            if(freq[i]==0)
            res.push_back(i);
        }
        return res;
    }
};