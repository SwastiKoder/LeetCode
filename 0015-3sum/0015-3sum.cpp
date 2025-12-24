class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        // set<vector<int>> s;
        vector<vector<int>> ans;
        int n = nums.size();
        for (int i = 0; i < n - 2; i++) {
            int j = i + 1;
            int k = n - 1;
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    while (j < k && nums[j] == nums[j + 1])
                        j++;
                    while (j < k && nums[k] == nums[k - 1])
                        k--;
                    j++;
                    k--;
                } else if (sum < 0)
                    j++;
                else
                    k--;
            }
        }
        // for (auto ele : s) {
        //     ans.push_back(ele);
        // }
        return ans;
    }
};