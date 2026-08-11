class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int n = words.size();

        for(int i = 0; i < n;) {
            int sum = 0, j = i;

            // find how many words can fit
            for(; j < n; j++) {
                if(sum + words[j].size() + (j - i) > maxWidth)
                    break;

                sum += words[j].size();
            }

            int cnt = j - i;
            int rem = maxWidth - sum;
            string s;

            // last line or only one word
            if(j == n || cnt == 1) {
                for(int k = i; k < j; k++) {
                    s += words[k];

                    if(k != j - 1)
                        s += ' ';
                }

                // add remaining spaces at the end
                s += string(maxWidth - s.size(), ' ');
            }
            else {
                // distribute spaces between words
                int space = rem / (cnt - 1);
                int extra = rem % (cnt - 1);

                for(int k = i; k < j; k++) {
                    s += words[k];

                    if(k != j - 1) {
                        s += string(space, ' ');

                        // extra spaces go to left gaps
                        if(extra > 0) {
                            s += ' ';
                            extra--;
                        }
                    }
                }
            }

            ans.push_back(s);

            // move to next line
            i = j;
        }

        return ans;
    }
};