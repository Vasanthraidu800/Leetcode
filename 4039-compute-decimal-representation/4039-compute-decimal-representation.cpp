class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        vector<int>res;
        int cnt = -1;
        while(n>0)
        {
            int temp = n%10;
            cnt++;
            if(temp!=0)
            {
                res.push_back(temp * pow(10,cnt));
            }
            n/=10;
        }
        sort(res.rbegin(),res.rend());
        return res;
    }
};