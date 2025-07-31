class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();
        map<string, int> mpp;
        
        // Count frequency of each word
        for (int i = 0; i < n; i++) {
            mpp[words[i]]++;
        }

        // Store {frequency, word} pairs
        vector<pair<int, string>> vec;
        for (auto& i : mpp) {
            vec.push_back({i.second, i.first});
        }

        // Sort by frequency descending, then lex ascending
        sort(vec.begin(), vec.end(), [](pair<int, string>& a, pair<int, string>& b) {
            if (a.first == b.first)
                return a.second < b.second;  // lex order if freq equal
            return a.first > b.first;        // higher freq first
        });

        // Get top k
        vector<string> res;
        for (int i = 0; i < k; i++) {
            res.push_back(vec[i].second);
        }

        return res;
    }
};
