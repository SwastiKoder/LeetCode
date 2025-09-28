class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int, int> m1;
        for (int i = 0; i < nums.size(); i++) {
            int x = target - nums[i];
           
            if (m1.find(x) != m1.end()) {
                ans.push_back(m1[x]);
                ans.push_back(i);
            } else {
                m1[nums[i]] = i;
            }
        }
        return ans;
    }
};