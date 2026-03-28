class Solution {
public:
    vector<int> partitionLabels(string s) {
        // declare a vector to store last occurrence of each char
        vector<int> last(26);
        
        // i am storing last occurrence of each character
        for(int i = 0; i < s.size(); i++) {
            last[s[i] - 'a'] = i;
        }
        
        vector<int> result;
        int start = 0;
        int end = 0;
        
        //  traverse string
        for(int i = 0; i < s.size(); i++) {
            end = max(end, last[s[i] - 'a']);
            
            
            if(i == end) {
                result.push_back(end - start + 1);
                start = i + 1;
            }
        }
        
        return result;
    }
};