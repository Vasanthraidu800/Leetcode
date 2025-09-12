class Solution {
public:
bool isVowel(char ch)
{
    if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
    {
        return true;
    }
    return false;
}
    bool doesAliceWin(string s) {
        int n = s.size();
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(isVowel(s[i])==true)
            {
            return true;
            break;
            }
        }
        return false;
    }
};