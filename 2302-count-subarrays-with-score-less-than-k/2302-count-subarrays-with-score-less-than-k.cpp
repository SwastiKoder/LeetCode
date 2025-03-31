class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long n = nums.size();
        long long i = 0, j = 0, ans = 0, sum = 0;
        while (j < n) {
            sum += nums[j];
            while (sum * (j - i + 1) >= k) {
                sum -= nums[i];
                i++;
            }
            ans += (j - i + 1);  // Count valid subarrays
            j++;
        }
        return ans;
    }
};
