class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int totalApples = 0;
        for (int a : apple) {
            totalApples += a;
        }

        sort(capacity.begin(), capacity.end(), greater<int>());

        int usedBoxes = 0;
        int currCapacity = 0;

        for (int c : capacity) {
            currCapacity += c;
            usedBoxes++;
            if (currCapacity >= totalApples) {
                return usedBoxes;
            }
        }

        return usedBoxes; 
    }
};
