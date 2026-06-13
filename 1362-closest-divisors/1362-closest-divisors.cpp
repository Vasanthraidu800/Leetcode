class Solution {
public:
    vector<int> getPair(int x) {
        for (int d = sqrt(x); d >= 1; d--) {
            if (x % d == 0) {
                return {d, x / d};
            }
        }
        return {};
    }

    vector<int> closestDivisors(int num) {
        vector<int> p1 = getPair(num + 1);
        vector<int> p2 = getPair(num + 2);

        if (abs(p1[1] - p1[0]) <= abs(p2[1] - p2[0]))
            return p1;

        return p2;
    }
};