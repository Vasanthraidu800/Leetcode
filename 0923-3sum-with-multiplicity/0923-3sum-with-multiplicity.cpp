class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        unordered_map<int,int>freq;
        int m = arr.size();
        for(int i=0;i<m;i++)
        {
            freq[arr[i]]++;
        }
        long long  ans = 0;
        long long MOD = 1e9+7;

        for(int i=0;i<=100;i++)
        {
            if(freq.find(i) == freq.end())
            continue;
            for(int j=i;j<=100;j++)
            {
                if(freq.find(j) == freq.end())
                continue;

                int k = target - i -j;

                if(k<j || k>100) continue;

                if(freq.find(k) == freq.end())
                continue;

                if(i==j && j==k)
                {
                    long long n = freq[i];
                    ans += 1LL *n*(n-1)*(n-2)/6;
                }
                else if(i==j)
                {
                    long long n = freq[i];
                    ans+= 1LL * n*(n-1)/2 *freq[k];
                }
                else if(j==k)
                {
                    long long n = freq[j];
                    ans += 1LL *freq[i] * n * (n-1)/2;
                }
                else
                {
                    ans += 1LL * freq[i] * freq[j] * freq[k];
                }
                ans %= MOD;
            }
        }
        return ans;
    }
};