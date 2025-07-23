class Solution {
public:
    bool isFascinating(int n) {
       // This puzzle is famous: only these 3-digit numbers work → 192, 219, 273, 327.
        return n == 192 || n == 219 || n == 273 || n == 327;
    }
};