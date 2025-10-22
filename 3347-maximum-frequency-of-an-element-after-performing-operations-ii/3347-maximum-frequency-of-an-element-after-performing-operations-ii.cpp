class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        if (nums.empty())
            return 0;
        int maxEl = *max_element(begin(nums), end(nums)) + k;
        map<int, int> diff;
        unordered_map<int, int> freq;
        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;

            int l = max(nums[i] - k, 0);
            int r = nums[i] + k;
            diff[l]++;
            diff[r + 1]--;

            diff[nums[i]] += 0;
        }
        int res = 1;
        int cumSum = 0;
        
        for (auto it = diff.begin(); it != diff.end(); it++) {
            cumSum += it->second; // running sum
            int target = it->first;
            int targetFreq = freq[target]; // freq[target] is 0 if not present
            int needConversion = cumSum - targetFreq;
            int maxPossibleFreq = min(needConversion, numOperations);
            res = max(res, targetFreq + maxPossibleFreq);
        }

        return res;
    }
};
