class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int maxVal = *max_element(nums.begin(), nums.end()) + k;
        unordered_map<int, int> freq;
        map<int, int> diff;
        for (int x : nums) {
            freq[x]++;
            diff[x] += 0;
            int l = max(0, x - k);
            int r = min(maxVal, x + k);

            diff[l]++;
            diff[r + 1]--;
        }

        int res = 0;
        int cumSum = 0;
        for (auto it = diff.begin(); it != diff.end(); it++) {
            int target = it->first;
            it->second += cumSum;
           int targetCount = freq[target];
            int needConv = it->second - targetCount;
            int possible = min(needConv, numOperations);
            res = max(res, possible + targetCount);
            cumSum =it->second;
        }
        return res;
    }
};