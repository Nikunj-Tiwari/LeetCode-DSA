class Solution {
public:
    bool canAliceWin(int n) {
        int amount = 10;
        bool aliceTurn = true;
        while (n >= amount) {
            n -= amount;
            amount--;
            aliceTurn = !aliceTurn;
        }
        return !aliceTurn;
    }
};