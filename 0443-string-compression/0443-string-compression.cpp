class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int res=0;
        int i=0;

        while(i<n)
        {
            char current = chars[i];
            int count = 0;

            while(i<n && chars[i]==current)
            {
                i++;
                count++;
            }
            chars[res]=current;
            res++;

            if(count>1)
            {
                string s = to_string(count);
                for(char c : s)
                {
                    chars[res++]=c;
                }
            }
        }
       return res;
    }
};