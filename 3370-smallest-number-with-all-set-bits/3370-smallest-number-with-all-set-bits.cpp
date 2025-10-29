class Solution {
public:
    int smallestNumber(int n) {

        int count = 0;
        while (n > 0) {
            count++;
            n /= 2;
        }
        int sum = 0;
        int y = 0;
        while (count > 0) {
            sum += pow(2, y);
            y++;
            count--;
        }
        return sum;
    }
};