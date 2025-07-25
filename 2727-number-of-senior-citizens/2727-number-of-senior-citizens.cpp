#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;
        for (string& detail : details) {
            string ageStr = detail.substr(11, 2); 
            int age = stoi(ageStr);            
            if (age > 60) {
                count++;
            }
        }
        return count;
    }
};
