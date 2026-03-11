class Solution {
public:
    int mergeSort(vector<long long>& s, int l, int r, int lower, int upper){
        if(r - l <= 1) return 0;

        int m = (l + r) / 2;
        int cnt = mergeSort(s, l, m, lower, upper) + mergeSort(s, m, r, lower, upper);

        int j = m, k = m, t = m;
        vector<long long> temp;
        int idx = 0;

        for(int i = l; i < m; i++){
            while(k < r && s[k] - s[i] < lower) k++;
            while(j < r && s[j] - s[i] <= upper) j++;
            cnt += j - k;
        }

        int p1 = l, p2 = m;

        while(p1 < m && p2 < r){
            if(s[p1] <= s[p2]) temp.push_back(s[p1++]);
            else temp.push_back(s[p2++]);
        }

        while(p1 < m) temp.push_back(s[p1++]);
        while(p2 < r) temp.push_back(s[p2++]);

        for(int i = 0; i < temp.size(); i++){
            s[l + i] = temp[i];
        }

        return cnt;
    }

    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long long> pre(n + 1, 0);

        for(int i = 0; i < n; i++){
            pre[i + 1] = pre[i] + nums[i];
        }

        return mergeSort(pre, 0, n + 1, lower, upper);
    }
};