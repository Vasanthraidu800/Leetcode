class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();
        vector<string>res;
        res.push_back(words[0]);
        for(int i=1;i<n;i++)
        {
            string curr = words[i];
            string prev = res.back();
            sort(curr.begin(),curr.end());
            sort(prev.begin(),prev.end());
            if(curr!=prev)
            {
                res.push_back(words[i]);
            }
        }
        return res;
    }
};