class Solution {
public:
    bool checkIfPangram(string sentence) {
        int n =sentence.size();
        map<char,int>mpp;
        for(char ch:sentence)
        {
            mpp[ch]++;
        }
        int cnt=0;
        for(auto i:mpp)
        {
            if(islower(i.first))
            cnt++;
        }
        if(cnt==26)
        return true;
        else
        return false;
    }
};