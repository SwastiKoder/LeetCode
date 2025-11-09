class Solution {
public:
    int GCD(int a, int b) {
        if (a == 0)
            return b;
        if (b == 0)
            return a;
        if (a == b)
            return a;

        if (a < b)
            return GCD(a, b - a);
        return GCD(a - b, b);
    }
    int findGCD(vector<int>& nums) {
        int minEl = *min_element(nums.begin(), nums.end());
        int maxEl = *max_element(nums.begin(), nums.end());

        return GCD(minEl, maxEl);
    }
};