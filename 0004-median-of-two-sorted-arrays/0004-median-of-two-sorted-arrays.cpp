class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        vector<int> res;

        for(int x : nums1)
            res.push_back(x);

        for(int x : nums2)
            res.push_back(x);

        sort(res.begin(), res.end());

        int n = res.size();

        if(n % 2 == 1)
        {
            return res[n / 2];
        }
        else
        {
            return (res[n / 2] + res[n / 2 - 1]) / 2.0;
        }
    }
};