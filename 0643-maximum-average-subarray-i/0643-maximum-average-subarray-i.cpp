class Solution {
public:
    double findMaxAverage(vector<int>& a, int k) {
        int n = a.size();
        int sum = 0;

        for(int i = 0; i < k; i++)
            sum += a[i];

        int mx = sum;

        for(int i = k; i < n; i++) {
            sum = sum + a[i] - a[i-k];
            if(sum > mx)
                mx = sum;
        }

        return (double)mx / k;
    }
};