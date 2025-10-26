class Solution {
public:
    int totalMoney(int n) {
        int full = n / 7;
        int a = 28;
        int d = 7;
        int remDay = n % 7;
        int b = a + d * (full - 1);
        int money = full * (a + b) / 2;
        int z = full + 1;
        for (int i = 1; i <= remDay; i++) {
            money += z;
            z++;
        }
        return money;
    }
};