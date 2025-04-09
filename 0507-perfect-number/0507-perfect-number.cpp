class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sum = 0;
        for (int i = 1; i <= sqrt(num); i++) {
            if (num % i == 0) {
                sum = sum + i;
                if (sqrt(num) != i)
                    sum = sum + (num / i);
            }
        }
        if(num == (sum-num)) return true ;
        else return false ;
    }
};