class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n + 1, 0);
        for (int i = 0; i <= n; i++) {
            if (v[nums[i]] == 0)
                v[nums[i]] = nums[i];
            else
                return nums[i];
        }
        return 0 ;
    }
};