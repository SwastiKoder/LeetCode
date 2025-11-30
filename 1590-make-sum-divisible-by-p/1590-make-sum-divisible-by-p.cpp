class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        long long arraySum = accumulate(nums.begin(), nums.end(), 0LL);
        int rem = arraySum % p;
        if (rem == 0)
            return 0;

        unordered_map<int, int> mp;
        mp[0] = -1;
        int curr = 0;
        int mn = INT_MAX;

        for (int i = 0; i < n; i++) {
            curr = (curr + nums[i]) % p;
            int prev = (curr - rem + p) % p;
            if (mp.find(prev) != mp.end()) {
                mn = min(mn, i - mp[prev]);
            }
            mp[curr % p] = i;
        }

        if (mn == INT_MAX || mn == n)
            return -1;
        return mn;
    }
};