class Solution {
public:
    string frequencySort(string s) {
          unordered_map<char,int>mpp;
        for(char ch : s){
            mpp[ch]++;
        }
        vector<pair<int,char>>arr;
        for(auto& pair : mpp){
            arr.push_back({pair.second, pair.first});
        }
        sort(arr.begin(), arr.end(), [] (auto& a, auto& b){
            return a.first > b.first;
        });
        string ans = "";
        for(auto& it : arr){
            ans.append(it.first, it.second);
        }
        return ans;
    }
};