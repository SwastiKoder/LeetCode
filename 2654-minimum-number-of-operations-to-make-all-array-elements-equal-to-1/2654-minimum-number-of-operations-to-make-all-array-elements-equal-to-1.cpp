class Solution {
public:
    int gcd(int a, int b) {
        if (b == 0)
            return a;

        return gcd(b, a % b);
    }
    int minOperations(vector<int>& nums) {
        int count_ones = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1)
                count_ones++;
        }
        if (count_ones > 0)
            return nums.size() - count_ones;

        int l = INT_MAX;
        for (int i = 0; i < nums.size() - 1; i++) {
            int g = nums[i];
            for (int j = i + 1; j < nums.size(); j++) {
                g = gcd(g, nums[j]);
                if (g == 1) {
                    l = min(l, j - i + 1);
                    break;
                }
            }
        }

        if (l == INT_MAX)
            return -1;
        return (l - 1) + (nums.size() - 1);
    }
};