class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>pos,neg;
        for( int i : nums)
        {
            if (i>0) pos.push_back(i);
            else neg.push_back(i);
        }
        vector<int>res;
        int k=0,l=0;
        while(k+l<n)
        {
            res.push_back(pos[k]); k++;
            res.push_back(neg[l]);l++;
        }
        return res;
    }
};