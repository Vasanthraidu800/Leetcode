class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        vector<int> minutes;

        // Converting  HH:MM to minutes
        for (auto &t : timePoints) {
            int h = stoi(t.substr(0, 2));
            int m = stoi(t.substr(3, 2));
            minutes.push_back(h * 60 + m);
        }
        sort(minutes.begin(), minutes.end());

        int minDiff = 1440;
        for (int i = 1; i < n; i++) {
            minDiff = min(minDiff, minutes[i] - minutes[i - 1]);
        }

        // Circular difference (last & first)
        minDiff = min(minDiff, 1440 - minutes[n - 1] + minutes[0]);

        return minDiff;
    }
};