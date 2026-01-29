class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        int n = nums.size();
        vector<int>target(n);
        int m = 0;
        for(int i=0;i<n;i++)
        {
            int ele = nums[i]; // element to insert
            int pos = index[i]; // pos to insert

            for(int i=m;i>pos;i--)
            {
                target[i]=target[i-1];
            }
            target[pos]=ele;
            m++;
        }
        return target;
    }
};