class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long long sum = 0;
        for (int x : nums)
            sum += x;
        long long diff = llabs((long long)goal - sum);
        return (diff + limit - 1) / limit;
    }
};