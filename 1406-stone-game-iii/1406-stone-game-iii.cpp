class Solution {
public:
    string stoneGameIII(vector<int>& p) {
        int n = p.size();
        vector<int>dp(n+1,0);
        for(int i=n-1;i>=0;i--) // reverse array from last 
        {
            int s=0; // declaring sum
            dp[i] = INT_MIN; // iniially keeping min
            for(int j=0;j<3 && i+j<n ;j++) // checking upto every 3 indices
            {
                s += p[i+j];
                dp[i] = max(dp[i],s-dp[i+j+1]);
            }

        }
        if(dp[0]>0) return "Alice";
        else if(dp[0]<0) return "Bob";
        return "Tie";
    }
};