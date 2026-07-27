class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> winner, loser;

        for (auto &m : matches) {
            winner[m[0]]++;
            loser[m[1]]++;
        }

        vector<int> zeroLoss, oneLoss;

        for (auto &p : winner) {
            if (loser.find(p.first) == loser.end())
                zeroLoss.push_back(p.first);
        }

        for (auto &p : loser) {
            if (p.second == 1)
                oneLoss.push_back(p.first);
        }

        sort(zeroLoss.begin(), zeroLoss.end());
        sort(oneLoss.begin(), oneLoss.end());

        return {zeroLoss, oneLoss};
    }
};