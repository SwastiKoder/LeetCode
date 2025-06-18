class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        for (int i = 0; i < n-1 ; i++) {
            int count = 0;
            for (int j = i + 1; j < n; j++) {
                if (nums[i] == nums[j])
                    count++;
                if (count >= n / 2)
                    return nums[i];
            }
        }
        return -1;
    }
};