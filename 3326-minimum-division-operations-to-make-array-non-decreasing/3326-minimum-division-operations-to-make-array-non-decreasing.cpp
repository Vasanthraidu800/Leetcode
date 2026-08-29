class Solution {
public:
    int gpd(int x) {
        if(x == 1) return 1;

        for(int i = 2; i * i <= x; i++) {
            if(x % i == 0)
                return x / i;
        }

        return 1;
    }

    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;

        for(int i = n - 2; i >= 0; i--) {
            while(nums[i] > nums[i + 1]) {
                int d = gpd(nums[i]);

                if(d == 1)
                    return -1;

                nums[i] /= d;
                cnt++;
            }
        }

        return cnt;
    }
};