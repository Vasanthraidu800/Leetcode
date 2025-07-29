class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
         int n = nums.size();
        map<int,int>mpp;
        for(int i=0;i<n;i++)
        {
            mpp[nums[i]]++;
        }
        vector<pair<int,int>>vec;
        for(auto i:mpp)
        {
            vec.push_back({i.second,i.first});
        }
        sort(vec.rbegin(),vec.rend());
        vector<int>res;
        for(int i=0;i<k;i++)
        {
            res.push_back(vec[i].second);
        }
        return res;
    }
};