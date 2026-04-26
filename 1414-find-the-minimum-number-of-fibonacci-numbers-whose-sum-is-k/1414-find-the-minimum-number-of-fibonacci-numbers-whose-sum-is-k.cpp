class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<int> fib;
        fib.push_back(1);
        fib.push_back(1);
        while (fib.back() < k) {
            int n = fib.size();
            fib.push_back(fib[n-1] + fib[n-2]);
        }
        int ans = 0;
        for (int i = fib.size() - 1; i >= 0; i--) {
            while (k >= fib[i]) {
                k -= fib[i];
                ans++;
            }
        }

        return ans;
    }
};