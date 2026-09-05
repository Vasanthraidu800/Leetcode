class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        //using prefix sums
        vector<int> prefMax(n);
        vector<int> suffMin(n);

        prefMax[0] = nums[0]; // setting first element to nums[0]
        for(int i = 1; i < n; i++) {
            prefMax[i] = max(prefMax[i - 1], nums[i]);
        }

        suffMin[n - 1] = nums[n - 1]; // setting last element to nums[n-1]
        for(int i = n - 2; i >= 0; i--) {
            suffMin[i] = min(suffMin[i + 1], nums[i]);
        }

        for(int i = 0; i < n; i++) {
            if(prefMax[i] - suffMin[i] <= k)
                return i;
        }

        return -1;
    }
};