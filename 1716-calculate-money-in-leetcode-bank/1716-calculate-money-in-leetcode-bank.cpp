class Solution {
public:
    int totalMoney(int n) {
        int k = 1;
        int sum = 0;
        int z = 1;
        for (int i = 1; i <= n; i++) {
            sum += k;
            k++;
            if (i % 7 == 0) {
                z++;
                k = z;
            }
        }
        return sum;
    }
};