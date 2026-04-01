class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(2);
        vector<int> count(n + 1, 0); 

        for (int num : nums) {
            count[num]++;
        }


        for (int i = 1; i <= n; i++) {
            if (count[i] == 2) res[0] = i; 
            if (count[i] == 0) res[1] = i;
        }

        return res;
    }
};