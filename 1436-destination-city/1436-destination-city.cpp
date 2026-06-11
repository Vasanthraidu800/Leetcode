class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> sources;

        for (auto &path : paths) {
            sources.insert(path[0]);
        }

        for (auto &path : paths) {
            if (!sources.count(path[1])) {
                return path[1];
            }
        }

        return "";
    }
};