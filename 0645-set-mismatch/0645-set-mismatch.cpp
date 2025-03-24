class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> v(2);
        int n = nums.size();
        int i = 0;
        while (i < n) {
            int correctIdx = nums[i] - 1;
            if (nums[i] == i + 1 || nums[i] == nums[correctIdx])
                i++;
            else {
                swap(nums[i], nums[correctIdx]);
            }
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                v[0] = nums[i] ;
                v[1] = i+1 ;
            }
        }
        return v;
    }
};