class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int>arr(2,-1);
        for(int i=0;i<n;i++)
        {
            if (nums[i] == target) {
                if (arr[0] == -1)  
                    arr[0] = i;
                arr[1] = i;      
            }
        }
        return arr;
    }
};