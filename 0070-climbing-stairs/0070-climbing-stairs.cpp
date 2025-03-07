class Solution {
public:
    int climbStairs(int n) {

        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        // return climbStairs(n - 1) + climbStairs(n - 2);
        int prev1 = 2, prev2 = 1, curr;
        for (int i = 3; i <= n; i++) {
            curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};