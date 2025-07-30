class Solution {
    void Create(int n,int o,int c,string s,vector<string>&result)
    {
        if(o==n && c==n)
        {
            result.push_back(s);
            return;
        }
        if(o<n)
        {
            s.push_back('(');
            Create(n,o+1,c,s,result);
            s.pop_back();
        }
        if(c<o)
        {
            s.push_back(')');
            Create(n,o,c+1,s,result);
            s.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string>result;
        string s;
        Create(n,0,0,s,result);
        return result;
    }
};