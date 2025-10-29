class Solution {
public:
    int smallestNumber(int n) {
        int x = n;
        while (true) {
            int temp = x;
            bool allSet = true;
            while (temp > 0) {
                int rem = temp % 2;
                if (rem == 0) {
                    allSet = false;
                    break;
                }
                temp = temp / 2;
            }

            if (allSet)
                return x;

            x++;
        }
    }
};
