class Solution {
public:
    string smallestPalindrome(string s) {
        sort(s.begin() , s.end());
        unordered_map<char,int>freq;
        for(char c : s)
        {
            freq[c]++;
        }
        int n = s.size();
        vector<char>res(n);
        int left = 0;
        int right = n-1; // to make palindrome from last 
        for(char c : s)
        {
            while(freq[c]>=2) // even frequency
            {
            res[left] = c; // pushing at first 
            res[right]= c; //pushing at last
            left++; 
            right --;  // decrementing the last index
            freq[c] -=2; // decreasing the frequncy
            }
        }

        for (auto &p : freq)
        {
            if(p.second == 1) // if odd length
            {
                res[n/2]=p.first; //placing in middle
                break;
            }
        }
        return string(res.begin(),res.end());
    }
};