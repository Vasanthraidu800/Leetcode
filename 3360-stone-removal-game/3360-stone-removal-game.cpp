class Solution {
public:
    bool canAliceWin(int n) {
    int move = 10;
    bool isAliceTurn = true;

    while (n >= move) {
        n -= move;
        move--;
        isAliceTurn = !isAliceTurn;
    }
    return !isAliceTurn;
}
};