class Solution {
public:
    int gd(int n) {
        for (int i = n / 2; i >= 1; i--) {
            if (n % i == 0) {
                return i;
                break;
            }
        }
        return 1 ;
    }
    int minSteps(int n) {
        int count = 0;
        while (n > 1) {
            int hf = gd(n);
            count = count + (n / hf);
            n = hf;
        }
        return count;
    }
};