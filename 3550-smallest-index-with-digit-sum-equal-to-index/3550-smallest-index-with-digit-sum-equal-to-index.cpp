class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            int x=nums[i], s=0;
            while(x){
                s += x%10;
                x /= 10;
            }
            if(s==i) return i;
        }
        return -1;
    }
};