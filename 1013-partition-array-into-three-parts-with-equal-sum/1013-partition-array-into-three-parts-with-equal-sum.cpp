class Solution {
public:
    bool is_possible(vector<int>&nums,int target)
    {
        int m = nums.size();
        int cnt=0;
        int sum=0;
        for(int i=0;i<m;i++)
        {
            sum+=nums[i];
            if(sum==target)
            {
                cnt++;
                sum=0;
            }
        }
        return cnt>=3;
    }
    bool canThreePartsEqualSum(vector<int>& arr) {
        int n = arr.size();
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
        }
        if(sum%3!=0) return false; 
         return is_possible(arr,sum/3);
    }

};