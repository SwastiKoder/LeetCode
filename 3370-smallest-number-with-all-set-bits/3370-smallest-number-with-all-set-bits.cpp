class Solution {
public:
    int smallestNumber(int n) {
        int sum = 0;
        for (int i = 0; i < INT_MAX; i++) {
            sum += pow(2, i);
            if (sum >= n)
                return sum ;
        }
        return -1;
    }
};