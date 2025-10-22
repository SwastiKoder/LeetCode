class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int maxVal = *max_element(nums.begin(), nums.end()) + k;
        unordered_map<int, int> freq;
        vector<int> diff(maxVal + 2, 0);
        for (int x : nums) {
            freq[x]++;
            int l = max(0, x - k);
            int r = min(maxVal, x + k);

            diff[l]++;
            diff[r + 1]--;
        }
        for (int i = 1; i < diff.size(); i++) {
            diff[i] += diff[i - 1];
        }
        int res = 0;
        for (int target = 0; target <= maxVal; target++) {
            int targetFreq = freq[target];
            int needConv = diff[target] - targetFreq;
            int possible = min(needConv, numOperations);
            res = max(res, possible + targetFreq);
        }
        return res;
    }
};