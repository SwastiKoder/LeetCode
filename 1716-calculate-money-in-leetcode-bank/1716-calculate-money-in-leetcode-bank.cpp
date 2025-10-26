class Solution {
public:
    int totalMoney(int n) {
        int full = n / 7;
        int a = 28;
        int d = 7;
        int remDay = n % 7;
        int money = 0;
        if (full == 1)
            money = (2 * a + (full - 1) * d) / 2;
        else
            money = (full / 2) * (2 * a + (full - 1) * d);
        int z = full + 1;
        for (int i = 1; i <= remDay; i++) {
            money += z;
            z++;
        }
        return money;
    }
};