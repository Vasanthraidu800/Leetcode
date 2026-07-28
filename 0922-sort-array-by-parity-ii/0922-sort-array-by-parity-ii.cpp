class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        vector<int>even,odd;
        for(int i : nums)
        {
            if(i%2==0) even.push_back(i);
            else odd.push_back(i);
        }
        vector<int>res;
        int l=0,k=0;
        for(int i=0;i<n;i++)
        {
            if(i%2==0) {res.push_back(even[l]);
            l++;}
            else 
            {res.push_back(odd[k]);
            k++;
            }
        }
        return res;
    }
};