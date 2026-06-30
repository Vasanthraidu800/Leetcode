class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if (finalSum % 2) return {};

        vector<long long> ans;

        for (long long x = 2; finalSum >= x; x += 2) {
            ans.push_back(x);
            finalSum -= x;
        }

        if (finalSum > 0)
            ans.back() += finalSum;

        return ans;
    }
};