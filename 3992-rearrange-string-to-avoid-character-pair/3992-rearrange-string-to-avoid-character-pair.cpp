class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        string res;

        // Put all y first
        for(char c : s) {
            if(c == y)
                res += c;
        }

        // Put all other characters
        for(char c : s) {
            if( c != y)
                res += c;
        }

        // // Put all x last
        // for(char c : s) {
        //     if(c == x)
        //         res += c;
        // }

        return res;
    }
};