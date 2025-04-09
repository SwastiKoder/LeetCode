class Solution {
public:
    bool isPrime(int n) {
        if (n == 1)
            return 0;
        if (n == 2)
            return 1;
        if (n == 3)
            return 1;
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0)
                return 0;
        }
        return 1;
    }
     int diagonalPrime(vector<vector<int>>& nums) {
         int maxel = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (i == j) {
                    if (isPrime(nums[i][j]))
                        maxel = max(maxel, nums[i][j]);
                }
                if (isPrime(nums[i][nums.size() - i - 1]))
                    maxel = max(maxel, nums[i][nums.size() - i - 1]);
            }
        }
        return maxel;
    }
};