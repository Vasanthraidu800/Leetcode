class Solution {
public:
    bool isBalanced(string num) {
        int sum_even = 0, sum_odd = 0;
        for (int i = 0; i < num.size(); i++) {
            int digit = num[i] - '0';  
            if (i % 2 == 0)
                sum_even += digit;
            else
                sum_odd += digit;
        }
        return sum_even == sum_odd;
    }
};
